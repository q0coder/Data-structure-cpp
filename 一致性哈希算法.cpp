/*#include<iostream>
#include<set>
#include<string>
#include<list>

using namespace std;
using uint = unsigned int;

class VirtualHost
{
public:
	VirtualHost(string ip, PhsicalHost* p)
		:m_ip(ip)
		, m_phsicalHost(p)
	{
		m_md5 = ::getMD5(m_ip.c_str());
	}
	bool operator<(const VirtualHost& host)const
	{
		return m_md5 < host.m_md5;
	}
	bool operator==(const VirtualHost& host)const
	{
		return m_ip == host.m_ip;
	}
	uint getMD5()const
	{
		return m_md5;
	}
	PhsicalHost* getPhsicalHost()const
	{
		return m_phsicalHost;
	}
private:
	string m_ip;
	uint m_md5;
	PhsicalHost* m_phsicalHost;
};

class PhsicalHost
{
public:
	PhsicalHost(string ip, int vnumber)
		:m_ip(ip)
	{
		for (size_t i = 0; i < vnumber; i++)
		{
			v_list.emplace_back(ip + "#" + to_string(i), this);

		}
	}


	string getIp()const
	{
		return m_ip;
	}
	const list< VirtualHost>& getVirtualHosts()const
	{
		return v_list;
	}

private:
	string m_ip;
	list< VirtualHost> v_list;
};

class ConsistentHash
{
public:
	void addHost(PhsicalHost& host)
	{
		auto list = host.getVirtualHosts();
		for (auto host : list)
		{
			m_hashCircle.insert(host);
		}
	}
	void delHost(PhsicalHost& host)
	{
		auto list = host.getVirtualHosts();
		for (auto host : list)
		{
			auto it = m_hashCircle.find(host);
			if (it != m_hashCircle.end())
			{
				m_hashCircle.erase(it);
			}
		}


	}
	string getHost(string clientip)const
	{
		uint md5 = ::getMD5(clientip.c_str());
		for (auto host : m_hashCircle)
		{
			if (md5 > host.getMD5())
			{
				return host.getPhsicalHost()->getIp();
			}
		}
		return m_hashCircle.begin()->getPhsicalHost()->getIp();
	}
private:
	set< VirtualHost> m_hashCircle;
};*/

