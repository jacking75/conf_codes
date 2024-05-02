// 출처: http://codeit.blog.fc2.com/blog-entry-6.html
// 간단 TCP 서버

#include <stdio.h>
#include <stdlib.h>
#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/TCPServer.h>
#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/TCPServerConnectionFactory.h>

using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::TCPServer;
using Poco::Net::TCPServerConnection;
using Poco::Net::TCPServerConnectionFactory;

class MyConnection : public TCPServerConnection 
{
public:    
	MyConnection(const StreamSocket &socket) : TCPServerConnection(socket)    {    }    
	virtual ~MyConnection()    {    }    
	
	virtual void run()    
	{        
		static const char message[] = "This is TCP server sample\n";        
		socket().sendBytes(message, sizeof(message) - 1);    
	}
};

class MyConnectionFactory : public TCPServerConnectionFactory 
{
public:    
	MyConnectionFactory()    {    }    
	virtual ~MyConnectionFactory()    {    }    
	
	virtual TCPServerConnection* createConnection(const StreamSocket &socket)    
	{        
		return new MyConnection(socket);    
	}
};


int main(int, char**) 
{    
	static const Poco::UInt16 SERVER_PORT = 8888;    
	
	ServerSocket sock(SERVER_PORT);    sock.listen();        
	TCPServer server(new MyConnectionFactory(), sock);        
	
	printf("Simple TCP Server Application.\n");    
	printf("command:\n");    
	printf("  q | quit : Quit application.\n");    
	printf("\n");    server.start();    
	
	bool running = true;    
	while(running) 
	{        
		char buff[256];        
		if(fgets(buff, sizeof(buff), stdin) == NULL) 
		{            
			running = false;        
		} 
		else 
		{            
			buff[strlen(buff) - 1] = '\0';            
			
			if(strcmp(buff, "quit") == 0 || strcmp(buff, "q")    == 0)            
			{                
				printf(">> QUIT command accepted.\n");                
				running = false;            
			} 
			else 
			{                
				printf(">> UNKNOWN command.\n");            
			}        
		}    
	}    
	
	server.stop();    
	return 0;
}





