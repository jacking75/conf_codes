// http://poco.roundsquare.net/2010/06/04/pocouristreamopener/

#include <Poco/URI.h>
#include <Poco/Format.h>
#include <Poco/URIStreamOpener.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/FTPStreamFactory.h>
#include <Poco/StreamCopier.h>
#include <Poco/TemporaryFile.h>
#include <Poco/Path.h>
#include <Poco/Thread.h>

#include <sstream>
#include <fstream>

#include "ScopedLogMessage.h"
#include "PrepareConsoleLogger.h"

void TestURIStreamOpener(ScopedLogMessage& msg, const Poco::URI& uri)
{
	msg.Message(Poco::format(" --- %s ---", uri.toString()));
	if ("ftp" == uri.getScheme())
	{
		std::string password;
		std::string user(uri.getUserInfo());
		if ("" == user)
		{
			user = "anonymous";
			password = Poco::Net::FTPStreamFactory::getAnonymousPassword();
			
			//패스워드가 필요한 경우는
			//Poco::Net::FTPStreamFactory::setAnonymousPassword(password);
		}
		else
		{
			Poco::Net::FTPPasswordProvider* pProvider = Poco::Net::FTPStreamFactory::getPasswordProvider();
			if (NULL != pProvider)
			{
				password = pProvider->password(user, uri.getAuthority());
			}
		}
		msg.Message(Poco::format("     (user=%s, password=%s)", user, password));
	}
	try
	{
		std::auto_ptr<std::istream> pStr(Poco::URIStreamOpener::defaultOpener().open(uri));
		std::stringstream ss;
		Poco::StreamCopier::copyStream(*pStr.get(), ss);

		Poco::Thread* p_thread = Poco::Thread::current();
		int threadID = (0 == p_thread) ? 0 : p_thread->id();

		msg.Message(Poco::format(" <start>\n%s[%d]  <end>", ss.str(), threadID));
	}
	catch (Poco::Exception& exc)
	{
		msg.Message(Poco::format("    %s", exc.displayText()));
	}
}

int main(int /*argc*/, char** /*argv*/)
{
	PrepareConsoleLogger logger(Poco::Logger::ROOT, Poco::Message::PRIO_INFORMATION);

	ScopedLogMessage msg("URIStreamOpenerTest ", "start", "end");

	Poco::Net::HTTPStreamFactory::registerFactory();
	Poco::Net::FTPStreamFactory::registerFactory();

	// HTTP
	Poco::URI uriHTTP("http://poco.roundsquare.net/downloads/test.txt");
	TestURIStreamOpener(msg, uriHTTP);

	// FTP
	Poco::URI uriFTP("ftp://ftp.iij.ad.jp/pub/linux/debian/dists/README");
	TestURIStreamOpener(msg, uriFTP);

	// file
	Poco::TemporaryFile tempFile;
	std::string path = tempFile.path();
	std::ofstream ostr(path.c_str());
	ostr << "Hello, world!" << std::endl;
	ostr.close();
	Poco::URI uriFile;
	uriFile.setScheme("file");
	uriFile.setPath(Poco::Path(path).toString(Poco::Path::PATH_UNIX));
	TestURIStreamOpener(msg, uriFile);

	return 0;
}
