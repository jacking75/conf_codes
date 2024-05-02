// ������ ��� ��Ȳ Ȯ��
// ��ó: https://sites.google.com/site/boostjp/tips/circular_buffer


#include <iostream>
#include <boost/circular_buffer.hpp>

void disp( char x ) 
{ 
	std::cout << x << ' '; 
}

int main()
{
    boost::circular_buffer<char> c_buf( 3 );

    c_buf.set_capacity( 7 );                            // ������ ��� ����� '7'�� Ȯ��

    std::cout << c_buf.size() << std::endl;             // ����� ��� �����Ƿ� ������� '0'
    std::cout << c_buf.capacity() << std::endl;         // ������ ��� ������� '7'
    if( c_buf.empty() ){                                // empty()==true
        std::cout << "buffer empty." << std::endl;
    }

    c_buf.push_front( 'a' );
    std::cout << c_buf.size() << std::endl;             // 1�� �־ ������� '1'

    c_buf.set_capacity( 5 );                            // ��� ����� '5'�� �۰� �����

    // ��� ���� �� ���� �� �ִ��� ����
    std::cout << c_buf.reserve()  << std::endl;         // capacity()-size() �ǹ�

    c_buf.push_front( 'b' );
    c_buf.push_front( 'c' );
    c_buf.push_front( 'd' );
    c_buf.push_front( 'e' );

    if( c_buf.full() ){                               // full()==true�� ���۰� �� á��
        std::cout << "buffer full." << std::endl;
    }
                                                        //  ___ ___ ___ ___ ___
    std::for_each( c_buf.begin(), c_buf.end(), disp );  // |_e_|_d_|_c_|_b_|_a_|
    std::cout << std::endl;
    std::cout << c_buf.size() << std::endl;             // ������� '5'


    c_buf.set_capacity( 3 );                            // ������ ���� �� �־ '3'���� ���� �� �ִ�
                                                        //  ___ ___ ___ 
    std::for_each( c_buf.begin(), c_buf.end(), disp );  // |_e_|_d_|_c_|
    std::cout << std::endl;
    std::cout << c_buf.size() << std::endl;             // ������� '3'

    return 0;
}