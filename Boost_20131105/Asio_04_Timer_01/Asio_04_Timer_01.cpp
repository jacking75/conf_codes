#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>

void OnTimer1( const boost::system::error_code& error );
void OnTimer2( const boost::system::error_code& error, boost::asio::steady_timer* pTimer );

int nTimer1Count = 0;
int nTimer2Count = 0;

void SetTimer( boost::asio::steady_timer* pTimer )
{
	std::cout << "SetTimer: " << time(NULL) << std::endl;

	pTimer->expires_from_now( boost::chrono::milliseconds(1000)); 

	pTimer->async_wait( OnTimer1 );

    pTimer->async_wait( boost::bind( OnTimer2, 
									boost::asio::placeholders::error, 
									pTimer
								)							
					);
}

void OnTimer1( const boost::system::error_code& error )
{
    if( !error ) 
	{
		++nTimer1Count;
        std::cout << "OnTimer1: " << nTimer1Count << std::endl;
    }
	else
	{
		std::cout << "error No: " << error.value() << " error Message: " << error.message() << std::endl;
	}
}

void OnTimer2( const boost::system::error_code& error, boost::asio::steady_timer* pTimer )
{
    if( !error ) 
	{
		++nTimer2Count;

        std::cout << "OnTimer2: " << nTimer2Count << std::endl;

		if( nTimer2Count < 5 )
		{
			SetTimer( pTimer );
		}
    }
	else
	{
		std::cout << "error No: " << error.value() << " error Message: " << error.message() << std::endl;
	}
}




int main()
{
	boost::asio::io_service io_service;

    boost::asio::steady_timer timer(io_service); 

	SetTimer( &timer );
	   
    io_service.run();

	std::cout << "Á¾·á: " << time(NULL) << std::endl;
	return 0;
}
