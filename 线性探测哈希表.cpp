//#include<iostream>
//#include<time.h>
//using namespace std;
//
////桶的状态
//enum State
//{
//	STATE_UNUSE,//桶从未被使用过
//	STATE_USING,//桶正在被使用
//	STATE_DEL//桶元素被删除了
//
//};
//
////桶的类型
//struct Bucket
//{
//	Bucket(int key = 0, State state = STATE_UNUSE)
//		:m_key(key)
//		, m_state(state)
//	{
//	}
//	int m_key;//存储的元素
//	State m_state;//桶的状态
//};
//
////线性探测哈希表
//class HashTable
//{
//public:
//	HashTable(int size = prime[0], double loadFactor = 0.75)
//		: m_loadFactor(loadFactor)
//		, m_useBucketnum(0)
//		, primeIdx(0)
//	{
//
//		if (size != prime[0])
//		{
//			for (; primeIdx < PRIME_SIZE; primeIdx++)
//			{
//				if (prime[primeIdx] > size) {
//					size = prime[primeIdx];
//					break;
//				}
//				if (primeIdx == PRIME_SIZE)
//				{
//					primeIdx--;
//				}
//			}
//		}
//		m_tableSize = prime[primeIdx];
//		m_table = new Bucket[m_tableSize];
//
//	}
//	~HashTable()
//	{
//		delete[] m_table;
//		m_table = nullptr;
//	}
//
//public:
//	//插入元素(key可重复)
//	bool insert(int key)
//	{
//		//扩容
//		double factor = m_useBucketnum*1.0 / m_tableSize;
//		if (factor >= m_loadFactor)
//		{
//			expend();
//		}
//		int idx = key % m_tableSize;
//		int i = idx;
//		do
//		{
//			if (m_table[i].m_state!= STATE_USING)
//			{
//				m_table[i].m_state = STATE_USING;
//				m_table[i].m_key = key;
//				m_useBucketnum++;
//				return true;
//			}
//			i = (i + 1) % m_tableSize;
//		} while (i!=idx);
//		return false;
//	}
//
//	//删除(同值的全部元素)
//	bool erase(int key)
//	{
//		if (m_useBucketnum == 0)
//		{
//			throw "HashTable is empty";
//		}
//		else
//		{
//			bool flag = false;
//			int idx = key % m_tableSize;
//			int i = idx;
//			do
//			{
//				if (m_table[i].m_state== STATE_USING&&m_table[i].m_key==key)
//				{
//					m_table[i].m_state = STATE_DEL;
//					m_useBucketnum--;
//					flag = true;
//				}
//				i = (i + 1) % m_tableSize;
//			} while (i!=idx&&m_table[i].m_state!= STATE_UNUSE);
//			return flag;
//		}
//	}
//
//	//查找
//	bool find(int key)
//	{
//		if(m_tableSize==0)
//			throw "HashTable is empty";
//		else
//		{
//			int idx = key % m_tableSize;
//			int i = idx;
//			do
//			{
//				if (m_table[i].m_state == STATE_USING && m_table[i].m_key == key)
//				{
//					return true;
//
//
//				}
//				i = (i + 1) % m_tableSize;
//			} while (i != idx && m_table[i].m_state != STATE_UNUSE);
//			return false;
//		}
//		
//	}
//
//private:
//	//扩容
//	void expend()
//	{
//		primeIdx++;
//		if (primeIdx == PRIME_SIZE)
//		{
//			throw "HashTable is too large can not expend";
//		}
//		else
//		{
//			
//
//			Bucket* new_m_table = new Bucket[prime[primeIdx]];
//			for (size_t i = 0; i < m_tableSize; i++)
//			{
//				if (m_table[i].m_state== STATE_USING)
//				{
//					int idx =m_table[i].m_key % prime[primeIdx];
//					int k = idx;
//					do
//					{
//						if (new_m_table[k].m_state != STATE_USING)
//						{
//							new_m_table[k].m_key = m_table[i].m_key;
//							new_m_table[k].m_state = STATE_USING;
//							break;
//						}
//						k = (k + 1) % prime[primeIdx];
//					} while (k!=idx);
//				}
//			}
//			m_tableSize = prime[primeIdx];
//			delete[] m_table;
//			m_table = nullptr;
//			m_table = new_m_table;
//
//		}
//		
//	}
//
//private:
//	Bucket* m_table;//指向动态开辟的哈希表
//	int m_tableSize;//哈希表的长度
//	int m_useBucketnum;//已经使用的桶的个数
//	double m_loadFactor;//装载因子
//
//	static const int PRIME_SIZE = 10;//素数表元数个数
//	static  int prime[PRIME_SIZE];//素数表
//	int primeIdx;//当前使用的素数表中的下标
//
//};
//int HashTable::prime[PRIME_SIZE] = { 3,7,23,47,97,251,443,911,1471,42773 };
//
//int main()
//{
//	srand(time(NULL));
//	HashTable hashTable;
//	for (size_t i = 0; i < 10; i++)
//	{
//		int val = rand() % 100 + 1;
//		hashTable.insert(val);
//		cout << val << " ";
//	}
//	hashTable.insert(10);
//	cout << endl;
//	cout<<hashTable.erase(10)<<endl;
//	cout << hashTable.find(50) << endl;
//	
//}