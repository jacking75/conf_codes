#include <iostream>
#include <string>
#include "Session.h"



const unsigned short PORT_NUMBER = 31400;

class TCP_Server
{
public:
	TCP_Server( boost::asio::io_service& io_service )
		: m_acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), PORT_NUMBER))
	{
		m_pSession = nullptr;
		StartAccept();
	}

	~TCP_Server()
	{
		if( m_pSession != nullptr )
		{
			delete m_pSession;
		}
	}

private:
	void StartAccept()
	{
		std::cout << "클라이언트 접속 대기....." << std::endl;

		m_pSession = new Session(m_acceptor.get_io_service());
		
		m_acceptor.async_accept( m_pSession->Socket(),
								 boost::bind(&TCP_Server::handle_accept, 
												this, 
												m_pSession,
												boost::asio::placeholders::error)
								);
	}

	void handle_accept(Session* pSession, const boost::system::error_code& error)
	{
		if (!error)
		{	
			std::cout << "클라이언트 접속 성공" << std::endl;
			
			pSession->PostReceive();
		}
	}

	int m_nSeqNumber;
	boost::asio::ip::tcp::acceptor m_acceptor;
	Session* m_pSession;
};

int main()
{
	boost::asio::io_service io_service;
    
	TCP_Server server(io_service);
    
	io_service.run();
  

	std:: cout << "네트웍 접속 종료" << std::endl;

	getchar();
	return 0;
}


