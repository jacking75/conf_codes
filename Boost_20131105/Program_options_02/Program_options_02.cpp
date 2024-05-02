// 출처: http://d.hatena.ne.jp/kanetai/20110426/1303824450
// -c test.conf

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<boost/program_options.hpp>
using namespace std;
namespace po = boost::program_options;

class myoption
{
	po::variables_map argmap; // 옵션 값 저장

public:
	myoption(int argc, char* argv[])
	{
		argmap.clear();
		ostringstream oss;
		oss << endl
			<< "Program description:" << endl
			<< "Test program(Boost.Program_options)";
		
		// 옵션 개요
		po::options_description desc(oss.str()); //system description
		po::options_description command_line("Command line");
		po::options_description config_file("Configuration file");
		
		string filename = "no configuration file";
		
		// 커맨드 라인에서 지정할 수 있는 옵션
		command_line.add_options()
			("help,h"	,						"print help message")	// 값을 받지 않는 옵션
			("string,s"	, po::value<string>()->default_value("default"),"input string")	// 기본 값 설정 가능
			("int,i"	, po::value<int>(),				"input int")
			("conf,c"	, po::value<string>(&filename),			"configuration file name");	// option을 저장하는 변수 지정 가능
		
		// 설정 파일에서 지정할 수 있는 옵션
		config_file.add_options()
			("string,s"	, po::value<string>()->default_value("default"),"input string")
			("int,i"	, po::value<int>(),				"input int")
			("debug,d"	,						"debug option")
			("vector,v"	, po::value< vector<int> >(),			"input vector");	//std::vector<*>으로 복수의 값을 받아 들일 수 있도록
		// 머지
		desc.add(command_line).add(config_file);

		// 옵션 해석
		try
		{
			po::store( po::parse_command_line(argc,argv,command_line), argmap);
			
			if( argmap.count("conf") ) // -c가 있다면 conf 파일을 패스 한다
			{  
				ifstream confstream( argmap["conf"].as<string>().c_str() );
				po::store( po::parse_config_file(confstream,config_file), argmap);
			}

			// 헬프 표시가 있고나 혹은 필요 수가 부족한 경우 
			if( argmap.count("help") || !argmap.count("int") ){
				cerr << desc << endl;
				argmap.count("help") ? exit(0) : exit(1);
			}
			
			po::notify(argmap); // 이것을 호출하면 위에 설정한 filename에 값을 넣는다
		}
		catch(std::exception& ex)
		{
			cerr << "option parsing error: " << ex.what() << endl
				 << desc << endl;
			exit(1);
		}	
	}

	string get_string()
	{ 
		return argmap["string"].as<string>(); 
	}
	
	int get_int() 
	{ 
		return (argmap.count("int") ? argmap["int"].as<int>() : -1); 
	}
	
	string get_conffilename() 
	{ 
		return (argmap.count("conf") ? argmap["conf"].as<string>() : "no configuration file" ); 
	}
	
	vector<int> get_vector() 
	{ 
		return (argmap.count("vector") ? argmap["vector"].as< vector<int> >() : vector<int>() ); 
	}

	bool get_debug_option()
	{ 
		return (bool)argmap.count("debug"); 
	}

	void dump()
	{
		ostringstream oss;
		oss 	<< "string: "	<< get_string()		<< endl
			<< "int: "	<< get_int()		<< endl
			<< "conf file: "<< get_conffilename()	<< endl
			<< "vector: ( ";
		
		vector<int> v=get_vector();
		
		for( int i=0; i < v.size(); i++) 
			oss << v[i] <<" ";
		
		oss << ")" << endl
			<< "debug option: " << get_debug_option() << endl;
		cout << oss.str() << endl;
	}

};

int main(int argc, char* argv[])
{
	myoption opt(argc, argv);
	opt.dump();

	return 0;
}