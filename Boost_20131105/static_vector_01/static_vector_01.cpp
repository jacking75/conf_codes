#include <iostream>
#include <boost/container/static_vector.hpp>

int main()
{
    boost::container::static_vector<int, 3> v;

    // ��� �߰�
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);

    // ��� ��� ���
    for (auto x : v) 
	{
        std::cout << x << std::endl;
    }

    // ������ ������ �Ѿ �߰��� �ϸ� bad_alloc ���� �߻�
	//v.push_back(5);
}