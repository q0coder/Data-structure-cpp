#include<iostream>
#include<time.h>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class HashTable
{
public:

	HashTable(int size = prime[0], double  loadFactor = 0.75)
		:m_useBucketnum(0)
		, m_loadFactor(loadFactor)
		, primeIdx(0)
	{
		if (size != prime[0])
		{
			for (; primeIdx < PRIME_SIZE; primeIdx++)
			{
				if (prime[primeIdx] > size) {
					size = prime[primeIdx];
					break;
				}
				if (primeIdx == PRIME_SIZE)
				{
					primeIdx--;
				}
			}
		}
		m_table.resize(size);
	}

	//增加元素（key不可重复)
	void insert(int key)
	{
		double factor = m_useBucketnum * 1.0 / m_table.size();
		if (factor >= m_loadFactor)
		{
			expend();
		}
		int idx = key % m_table.size();
		if (m_table[idx].empty())
		{
			m_useBucketnum++;
			m_table[idx].emplace_front(key);
		}
		else
		{
			auto it = ::find(m_table[idx].begin(), m_table[idx].end(), key);
			if (it == m_table[idx].end())
			{
				m_table[idx].emplace_front(key);
			}
		}
	}

	//删除
	void erase(int key)
	{
		if (m_useBucketnum == 0)
			throw "HashTable is empty";
		else
		{
			int idx = key % m_table.size();
			auto it = ::find(m_table[idx].begin(), m_table[idx].end(), key);
			if (it != m_table[idx].end())
			{
				m_table[idx].erase(it);
				if (m_table[idx].empty())
					m_useBucketnum--;
			}
		}

	}

	//查找
	bool find(int key)
	{
		if (m_useBucketnum == 0)
			throw "HashTable is empty";
		else
		{
			int idx = key % m_table.size();

			auto it = ::find(m_table[idx].begin(), m_table[idx].end(), key);
			if (it != m_table[idx].end())
			{
				return true;
			}
			else
				return false;
		}

	}

private:
	//扩容
	void expend()
	{
		if (primeIdx + 1 == PRIME_SIZE)
		{
			throw "HashTable is too large can not expend";

		}
		else
		{
			primeIdx++;
			m_useBucketnum = 0;
			vector<list<int>>new_m_table;
			m_table.swap(new_m_table);
			m_table.resize(primeIdx);
			for (auto list:new_m_table)
			{
				for (auto key:list)
				{
					int idx = key % m_table.size();
					if (m_table[idx].empty())
					{
						m_useBucketnum++;
					}
					m_table[idx].emplace_front(key);

				}
			}
			
		}
	}

private:
	vector<list<int>>m_table;//哈希表数据结构
	int m_useBucketnum;//记录使用的桶的个数
	double m_loadFactor;//装载因子

	static const int PRIME_SIZE = 10;//素数表元数个数
	static  int prime[PRIME_SIZE];//素数表
	int primeIdx;//当前使用的素数表中的下标

};
int HashTable::prime[PRIME_SIZE] = { 3,7,23,47,97,251,443,911,1471,42773 };


int main()
{
	srand(time(NULL));
	HashTable hashTable;
	for (size_t i = 0; i < 10; i++)
	{
		int val = rand() % 100 + 1;
		hashTable.insert(val);
		cout << val << " ";
	}
	hashTable.insert(10);
	cout << endl;
	cout << hashTable.find(50) << endl;
	
}