#include<iostream>
#include<functional>
#include<time.h>
using namespace std;

//c++优先级队列默认是大根堆，队首优先级最大（入堆，出堆等操作都发生在堆顶），值也最大
class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;
	PriorityQueue(int cap=20,Comp comp=greater<int>())
		:m_size(0)
		,m_cap(cap)
		,m_comp(comp)
	{
		m_que = new int[m_cap];
	}
	/*PriorityQueue( Comp comp = greater<int>())
		:m_size(0)
		, m_cap(20)
		, m_comp(comp)
	{
		m_que = new int[m_cap];
	}*/
	~PriorityQueue()
	{
		delete[]m_que;
		m_que = nullptr;
	}

public:

	//入堆
	void push(int val)
	{
		if (m_size == m_cap)
		{
			expend(2 * m_cap);
		}
		if (m_size == 0)
		{
			m_que[m_size] = val;
		}
		else
		{
			siftUp(m_size, val);
		}
		m_size++;

	}

	//出堆
	void pop()
	{
		if (m_size == 0)
		{
			throw "ProrityQueue is empty";
		}
		
			
		
		m_size--;
		if (m_size > 0)
		{
			siftDown(0,m_que[m_size]);
		}
	}

	//获取堆顶元素
	int top()
	{
		if(m_size==0)
			throw "ProrityQueue is empty";
		else
		return m_que[0];
	}

	//判断堆是否为空
	bool empty()
	{
		return m_size == 0;
	}

	//获取堆中元素个数
	int size()
	{
		return m_size;
	}

	void show()
	{
		for (size_t i = 0; i < m_size; i++)
		{
			cout << m_que[i] << " ";
		}cout << endl;
	}

private:
	//入堆上浮
	void siftUp(int i, int val)
	{
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (m_comp(val, m_que[father]))
			{
				m_que[i] = m_que[father];
				i = father;
			}
			else
			{
				break;
			}

		}
		m_que[i] = val;
	}

	//出堆下沉
	void siftDown(int i,int val)
	{
		
		while (i <= (m_size - 1) / 2)
		{
			int child = 2 * i + 1;
			if (child + 1 < m_size && m_comp(m_que[child + 1], m_que[child]))
			{
				child = child + 1;
			}
			if (m_comp(m_que[child], val))
			{
				m_que[i] = m_que[child];
				i = child;
			}
			else
				break;
			m_que[i] = val;
		}
	}

private:
	//扩容
	void expend(int val)
	{
		int* p = new int[val];
		memcpy(p, m_que, val * sizeof(int));

		delete[] m_que;
		m_que = nullptr;
		m_que = p;
		m_cap = val;

	}
private:
	int* m_que;
	int m_size;
	int m_cap;
	Comp m_comp;
};



int main()
{
	srand(time(NULL));
	PriorityQueue priority_que;
	for (size_t i = 0; i < 10; i++)
	{
		priority_que.push(rand() % 100);
		
	}
	priority_que.show();
	while (!priority_que.empty())
	{
		cout << priority_que.top() << " ";
		priority_que.pop();
	}
	//priority_que.show();
	//cout << priority_que.top() <<endl;

	/*cout << priority_que.top() << endl;
	cout << priority_que.empty() << endl;
	cout << priority_que.size() << endl;*/

}