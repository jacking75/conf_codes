#pragma once

#include <boost/bind.hpp>
#include <boost/asio.hpp>

class Session 
{
public:
	Session(boost::asio::io_service& io_service)
		: m_Socket(io_service)
	{
	}

	boost::asio::ip::tcp::socket& Socket()
	{
		return m_Socket;
	}

	void PostReceive();
	

private:
	void handle_write(const boost::system::error_code& /*error*/, size_t /*bytes_transferred*/)
	{
	}

	void handle_receive( const boost::system::error_code& error, size_t bytes_transferred );
	

	boost::asio::ip::tcp::socket m_Socket;
	std::string m_WriteMessage;
	std::array<char, 128> m_ReceiveBuffer;
};