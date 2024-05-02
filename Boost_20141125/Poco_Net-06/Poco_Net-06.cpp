// 출처: http://d.hatena.ne.jp/tullio/20091212/1260624748
#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/ThreadPool.h"
#include "Poco/Thread.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/RunnableAdapter.h"
#include "iostream"
using Poco::Net::ServerSocket;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::ThreadPool;
using Poco::Thread;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::RunnableAdapter;
using namespace std;


class WWWRequestHandler : public HTTPRequestHandler
{
public:
	WWWRequestHandler()  { } 

	void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
	{
		response.setChunkedTransferEncoding(true);
		response.setContentType("text/html");
		std::ostream& ostr = response.send();
		ostr << "<html><head><title>WWW Server</title>";
		ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
		ostr << "WWW Server by POCO C++ Libraries" << "<BR />";
		ostr << "YOUR REQUEST=" << request.getURI() << "<BR />";
		ostr << "YOUR ADDRESS=" << request.clientAddress().toString() << "<BR />";
		ostr << "</p></body></html>";
	}
};

class WWWRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	WWWRequestHandlerFactory()  {  }
	HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
	{
		return new WWWRequestHandler();
	}
};


class WWWServer : public Poco::Util::ServerApplication
{
public:
	WWWServer()  {  }
	~WWWServer()  {  }
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
	}
	void handleOption(const std::string& name, const std::string& value)
	{
		ServerApplication::handleOption(name, value);
	}
	int main(const std::vector<std::string>& args)
	{
		unsigned short port = (unsigned short)config().getInt("WWWServer.port", 8888);
		int maxQueued = config().getInt("WWWServer.maxQueued", 100);
		int maxThreads = config().getInt("WWWServer.maxThreads", 16);
		ThreadPool::defaultPool().addCapacity(maxThreads);
		HTTPServerParams* pParams = new HTTPServerParams;
		pParams->setMaxQueued(maxQueued);
		pParams->setMaxThreads(maxThreads);
		ServerSocket svs(port);
		HTTPServer srv(new WWWRequestHandlerFactory(), svs, pParams);
		srv.start();

		// CTRL-C를 누르던가, kill 시그널을 받을 때까지 대기한다.
		waitForTerminationRequest(); 
		
		srv.stop();
		return Application::EXIT_OK;
	}
};

int wmain(int argc, wchar_t* argv[])
{
	WWWServer app;
	return app.run(argc, argv);
}