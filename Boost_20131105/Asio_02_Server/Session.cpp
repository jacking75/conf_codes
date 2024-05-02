#include "Session.h"


void Session::PostReceive()
{
	memset( &m_ReceiveBuffer, '\0', sizeof(m_ReceiveBuffer) );

	m_Socket.async_read_some
			( 
			boost::asio::buffer(m_ReceiveBuffer), 
			boost::bind( &Session::handle_receive, this, 
											boost::asio::placeholders::error, 
											boost::asio::placeholders::bytes_transferred ) 
				
		);
							
}

void Session::handle_receive( const boost::system::error_code& error, size_t bytes_transferred )
{
	if( error )
	{
		if( error == boost::asio::error::eof )
		{
			std::cout << "Ŭ���̾�Ʈ�� ������ ���������ϴ�" << std::endl;
		}
		else 
		{
			std::cout << "error No: " << error.value() << " error Message: " << error.message() << std::endl;
		}
	}
	else
	{
		const std::string strRecvMessage = m_ReceiveBuffer.data();
		std::cout << "Ŭ���̾�Ʈ���� ���� �޽���: " << strRecvMessage << ", ���� ũ��: " << bytes_transferred << std::endl;

		char szMessage[128] = {0,};
		sprintf_s( szMessage, 128-1, "Re:%s", strRecvMessage.c_str() );
		m_WriteMessage = szMessage;
			
		boost::asio::async_write(m_Socket, boost::asio::buffer(m_WriteMessage),
							boost::bind( &Session::handle_write, this,
								boost::asio::placeholders::error,
								boost::asio::placeholders::bytes_transferred )
							);

			
		PostReceive(); 
	}
}