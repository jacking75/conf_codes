// 출처: http://poco.roundsquare.net/2010/05/05/poconethttpclientsession/
// http로 텍스트 파일 요청
#include <iostream>
#include <Poco/URI.h>


#include "HTTPGetter.h"
#include "ScopedElapsedTime.h"
#include "PrepareConsoleLogger.h"

int main(int /*argc*/, char** /*argv*/)
{
	PrepareConsoleLogger logger(Poco::Logger::ROOT, Poco::Message::PRIO_INFORMATION);

	Poco::URI uri("http://poco.roundsquare.net/downloads/test.txt");
	{
		ScopedElapsedTime msg("HTTPGetter ", "start", "end");

		HTTPGetter getter(uri.getHost(), uri.getPort());
		getter.Get(uri.getPath(), std::cout);
	}

	return 0;
}
