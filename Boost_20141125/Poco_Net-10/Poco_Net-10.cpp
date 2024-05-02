// √‚√≥: http://www.cachet.co.jp/?p=126

#include "Poco/Net/SocketReactor.h"
#include "Poco/Net/SocketAcceptor.h"
#include "Poco/Net/SocketNotification.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/NObserver.h"
#include "Poco/Exception.h"
#include "Poco/Thread.h"
#include "Poco/Timespan.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include <iostream>
#include <sstream>


using Poco::Net::SocketReactor;
using Poco::Net::SocketAcceptor;
using Poco::Net::ReadableNotification;
using Poco::Net::ShutdownNotification;
using Poco::Net::WritableNotification;
using Poco::Net::ErrorNotification;
using Poco::Net::TimeoutNotification;
using Poco::Net::IdleNotification;
using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::NObserver;
using Poco::AutoPtr;
using Poco::Thread;
using Poco::Timespan;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;


class EchoServiceHandler
{
public:
	EchoServiceHandler(StreamSocket& socket, SocketReactor& reactor)
		:_socket(socket)
		, _reactor(reactor)
		, _pBuffer(new char[BUFFER_SIZE])
		, _onWritableAdded(false)
		, _onTimeoutAdded(false)
	{
		Application& app = Application::instance();
		app.logger().information("Connection from " + socket.peerAddress().toString());

		_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, ReadableNotification>(*this, &EchoServiceHandler::onReadable));
		_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, ShutdownNotification>(*this, &EchoServiceHandler::onShutdown));
		_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, ErrorNotification>(*this, &EchoServiceHandler::onError));
		_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, IdleNotification>(*this, &EchoServiceHandler::onIdle));
	}

	~EchoServiceHandler()
	{
		Application& app = Application::instance();
		try
		{
			app.logger().information("Disconnecting " + _socket.peerAddress().toString());
		}
		catch (...)
		{
		}
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, ReadableNotification>(*this, &EchoServiceHandler::onReadable));
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, ShutdownNotification>(*this, &EchoServiceHandler::onShutdown));
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, ErrorNotification>(*this, &EchoServiceHandler::onError));
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, IdleNotification>(*this, &EchoServiceHandler::onIdle));
		if (_onWritableAdded)
			_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, WritableNotification>(*this, &EchoServiceHandler::onWritable));
		if (_onTimeoutAdded)
			_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, TimeoutNotification>(*this, &EchoServiceHandler::onTimeout));
		delete[] _pBuffer;
	}

	void onReadable(const AutoPtr<ReadableNotification>& pNf)
	{
		int n = _socket.receiveBytes(_pBuffer, BUFFER_SIZE);
		if (n > 0) {
			std::stringstream str;
			str.write(_pBuffer, n);
			_data = str.str();
			_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, WritableNotification>(*this, &EchoServiceHandler::onWritable));
			_onWritableAdded = true;
		}
		else {
			delete this;
		}
	}

	void onShutdown(const AutoPtr<ShutdownNotification>& pNf)
	{
		delete this;
	}

	void onWritable(const AutoPtr<WritableNotification>& pNf)
	{
		Application::instance().logger().information("onWritable called");
		std::string data = Poco::format("received %s", _data);
		_socket.sendBytes(data.data(), data.length());
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, WritableNotification>(*this, &EchoServiceHandler::onWritable));
		if (_onTimeoutAdded) {
			_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, TimeoutNotification>(*this, &EchoServiceHandler::onTimeout));
		}
		_reactor.addEventHandler(_socket, NObserver<EchoServiceHandler, TimeoutNotification>(*this, &EchoServiceHandler::onTimeout));
		_onTimeoutAdded = true;
	}

	void onError(const AutoPtr<ErrorNotification>& pNf)
	{
		Application::instance().logger().information("onError called");
	}

	void onTimeout(const AutoPtr<TimeoutNotification>& pNf)
	{
		Application::instance().logger().information("onTimeout called");
		_reactor.removeEventHandler(_socket, NObserver<EchoServiceHandler, TimeoutNotification>(*this, &EchoServiceHandler::onTimeout));
		delete this;
	}

	void onIdle(const AutoPtr<IdleNotification>& pNf)
	{
		Application::instance().logger().information("onIdle called");
	}

private:
	enum
	{
		BUFFER_SIZE = 1024
	};

	StreamSocket   _socket;
	SocketReactor& _reactor;
	char*          _pBuffer;
	std::string    _data;
	bool          _onWritableAdded;
	bool          _onTimeoutAdded;
};


class EchoServer : public Poco::Util::ServerApplication
	/// The main application class.
	///
	/// This class handles command-line arguments and
	/// configuration files.
	/// Start the EchoServer executable with the help
	/// option (/help on Windows, --help on Unix) for
	/// the available command line options.
	///
	/// To use the sample configuration file (EchoServer.properties),
	/// copy the file to the directory where the EchoServer executable
	/// resides. If you start the debug version of the EchoServer
	/// (EchoServerd[.exe]), you must also create a copy of the configuration
	/// file named EchoServerd.properties. In the configuration file, you
	/// can specify the port on which the server is listening (default
	/// 9977) and the format of the date/time string sent back to the client.
	///
	/// To test the EchoServer you can use any telnet client (telnet localhost 9977).
{
public:
	EchoServer() : _helpRequested(false)
	{
	}

	~EchoServer()
	{
	}

protected:
	void initialize(Application& self)
	{
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
	}

	void uninitialize()
	{
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);

		options.addOption(
			Option("help", "h", "display help information on command line arguments")
			.required(false)
			.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value)
	{
		ServerApplication::handleOption(name, value);

		if (name == "help")
			_helpRequested = true;
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("An echo server implemented using the Reactor and Acceptor patterns.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args)
	{
		if (_helpRequested)
		{
			displayHelp();
		}
		else
		{
			// get parameters from configuration file
			unsigned short port = (unsigned short)config().getInt("EchoServer.port", 9977);

			// set-up a server socket
			ServerSocket svs(port);
			// set-up a SocketReactor...
			Timespan timeout(30000000);    // timeout is set to 30sec
			SocketReactor reactor(timeout);
			// ... and a SocketAcceptor
			SocketAcceptor<EchoServiceHandler> acceptor(svs, reactor);
			// run the reactor in its own thread so that we can wait for 
			// a termination request
			Thread thread;
			thread.start(reactor);
			// wait for CTRL-C or kill
			waitForTerminationRequest();
			// Stop the SocketReactor
			reactor.stop();
			thread.join();
		}
		return Application::EXIT_OK;
	}

private:
	bool _helpRequested;
};


int main(int argc, char** argv)
{
	EchoServer app;
	return app.run(argc, argv);
}