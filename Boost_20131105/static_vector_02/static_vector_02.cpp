#include <iostream>
#include <boost/container/static_vector.hpp>

int main()
{
    boost::container::static_vector<int, 5> v;

    // ��� �߰�
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
	v.push_back(4);
    
	std::cout << "������: " << v.size() << ", ���ũ��:" << v.capacity() << std::endl;
	std::for_each( v.begin(), v.end(), [] (int data) { std::cout << data << ' '; });
	std::cout << std::endl;


    v.resize(3);
	std::cout << "������: " << v.size() << ", ���ũ��:" << v.capacity() << std::endl;
	std::for_each( v.begin(), v.end(), [] (int data) { std::cout << data << ' '; });
	std::cout << std::endl;
}