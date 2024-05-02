
#include <iostream>
#include <atomic>

int main()
{
	std::cout << "bool      : ";
	if( ATOMIC_BOOL_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_BOOL_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;


	std::cout << "char      : ";
	if( ATOMIC_CHAR_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_CHAR_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;


	std::cout << "char16_t      : ";
	if( ATOMIC_CHAR16_T_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_CHAR16_T_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;


	std::cout << "char32_t      : ";
	if( ATOMIC_CHAR32_T_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_CHAR32_T_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	
	
	std::cout << "wchar_t      : ";
	if( ATOMIC_WCHAR_T_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_WCHAR_T_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	

	std::cout << "short      : ";
	if( ATOMIC_SHORT_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_SHORT_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;

	
	std::cout << "int      : ";
	if( ATOMIC_INT_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_INT_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	

	std::cout << "long      : ";
	if( ATOMIC_LONG_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_LONG_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	

	std::cout << "long long      : ";
	if( ATOMIC_LLONG_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_LLONG_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	

	std::cout << "T*      : ";
	if( ATOMIC_POINTER_LOCK_FREE == 2 ) 
	  std::cout << "락 프리로 동작" << std::endl;
	else
	  std::cout << ATOMIC_POINTER_LOCK_FREE << " 0이면 락 프리 아님, 1이면 일 수도 있음" << std::endl;
	

	return 0;
}


