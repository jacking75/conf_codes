#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class User
{
	public:
	User() : m_bDie(false) {}
	~User() {}

	void SetIndex(int index) { m_Index = index; }
	int GetIndex() { return m_Index; }
	void SetDie() { m_bDie = true; }
	bool IsDie() { return m_bDie; }

	private:
	int m_Index;
	bool m_bDie;
};

int main()
{
	vector< User > Users;
	User tUser1;
	tUser1.SetIndex(1);
	Users.push_back(tUser1);

	User tUser2;
	tUser2.SetIndex(2);
	tUser2.SetDie();
	Users.push_back(tUser2);

	User tUser3;
	tUser3.SetIndex(3);
	Users.push_back(tUser3);

	auto Iter = find_if( Users.begin(), Users.end(), 
						[](User& tUser) -> bool { return true == tUser.IsDie(); } 
						);

	cout << "found Die User Index : " << Iter->GetIndex() << endl;

	return 0;
}
