
#include <unordered_map>
#include <iostream>
#include <string>
 
struct UDP_IP_INFO 
{
    std::string IP;
    int port;
};
 
struct KeyHash 
{
	std::size_t operator()(const UDP_IP_INFO& k) const
	{
		return std::hash<std::string>()(k.IP) ^ (std::hash<int>()(k.port) << 1);
	}
};
 
struct KeyEqual 
{
	bool operator()(const UDP_IP_INFO& lhs, const UDP_IP_INFO& rhs) const
	{
		return lhs.IP == rhs.IP && lhs.port == rhs.port;
	}
};
 
int main()
{
	std::unordered_map<UDP_IP_INFO, std::string, KeyHash, KeyEqual> UdpClients;

	UDP_IP_INFO udpinfo1 = {"201.200.0.1", 235};
	UdpClients.insert(std::pair<UDP_IP_INFO, std::string>(udpinfo1, "test1"));
	
	UDP_IP_INFO udpinfo2 = {"201.200.0.1", 234};
	UdpClients.insert(std::pair<UDP_IP_INFO, std::string>(udpinfo2, "test2"));
	

	UDP_IP_INFO udpinfoKey1 = {"201.200.0.1", 235};
	auto FindIter1 = UdpClients.find(udpinfoKey1);
	
	if( UdpClients.end() != FindIter1 )
	{
		std::cout << "IP: " << FindIter1->first.IP << ".  Port: " << FindIter1->first.port << std::endl;
	}
	else 
	{
		std::cout << "IP: 201.200.0.1.  Port: 235 는 없습니다" << std::endl; 
	}


	UDP_IP_INFO udpinfoKey2 = {"201.200.0.1", 233};
	auto FindIter2 = UdpClients.find(udpinfoKey2);
	
	if( UdpClients.end() != FindIter2 )
	{
		std::cout << "IP: " << FindIter2->first.IP << ".  Port: " << FindIter2->first.port << std::endl;
	}
	else 
	{
		std::cout << "IP: 201.200.0.1.  Port: 233 은 없습니다" << std::endl; 
	}

	return 0;
}