// 출처: http://d.hatena.ne.jp/tullio/20090430/1241102742
// 웹 사이트에 접속하여 헤더와 보디 출력

#include <iostream>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>

using namespace std;

int main()
{
	// 접속할 곳 설정
	Poco::Net::HTTPClientSession client("www.google.co.kr", 80);  
	
	// 접근 방법 설정
	Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, "/");  

	// 결과 받을 오브젝트 
	Poco::Net::HTTPResponse response;  

	// 요청을 보낸다.
	ostream &req = client.sendRequest(request);  
	
	// 결과를 얻는다.
	istream &res = client.receiveResponse(response);  
	
	// 헤더의 Content-Length를 얻는다.
	int len = response.getContentLength();  

	// 보디의 html을 넣을 공간을 확보한다.
	char *resbody = new char[len + 1]; 

	// http 헤더를 출력한다.
	response.write(cout);

	// html 보디를 얻는다.
	res.read(resbody, len);

	// html 보디를 출력한다.
	cout << resbody << endl;

	return 0;
}

