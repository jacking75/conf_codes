// √‚√≥: http://d.hatena.ne.jp/osyo-manga/20131213/1386933884

#include <boost/config.hpp>
#include <boost/predef.h>
#include <iostream>

int main()
{
	std::cout << BOOST_COMPILER << std::endl;

#if BOOST_OS_WINDOWS
	std::cout << "OS is Windows." << std::endl;
#else
	std::cout << "OS is not Windows." << std::endl;
#endif

#if BOOST_COMP_CLANG
	std::cout << "Compiler is Clang." << std::endl;
#elif BOOST_COMP_MSVC
	std::cout << "Compiler is MSVC." << std::endl;
#else
	std::cout << "Compiler is unknow." << std::endl;
#endif


#if BOOST_COMP_MSVC && BOOST_COMP_MSVC >= BOOST_VERSION_NUMBER(12, 0, 0)
	std::cout << "VC 12" << std::endl;
#elif BOOST_COMP_MSVC && BOOST_COMP_MSVC >= BOOST_VERSION_NUMBER(13, 0, 0)
	std::cout << "VC 13" << std::endl;
#endif

	return 0;
}

