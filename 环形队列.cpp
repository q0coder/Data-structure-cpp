//#include<iostream>
//#include<time.h>
//using namespace std;
//
//class Queue//环形队列
//{
//public:
//	Queue(int cap = 10)
//		:m_cap(cap)
//		,m_front(0)
//		,m_rear(0)
//		,m_size(0)
//	{
//		pQue = new int[cap];
//	}
//	~Queue()
//	{
//		delete[]pQue;
//		pQue = nullptr;
//	}
//public:
//	void push(int val)//入队
//	{
//		if ((m_rear + 1) % m_cap == m_front)
//		{
//			expend(2 * m_rear);
//		}
//		pQue[m_rear] = val;
//		m_rear = (m_rear + 1) % m_cap;
//		m_size++;
//	}
//
//	void pop()//出队
//	{
//		if (m_rear == m_front)
//			throw "Queue is empty";
//		m_front = (m_front + 1) % m_cap;
//		m_size--;
//	}
//
//	int front() const//获取队头元素
//	{
//		if (m_rear == m_front)
//			throw "Queue is empty";
//		return pQue[m_front];
//	}
//
//	int back() const//获取队尾元素
//	{
//		if (m_rear == m_front)
//			throw "Queue is empty";
//		return pQue[(m_rear-1+m_cap)%m_cap];
//	}
//
//	bool empty() const//判断是否为空
//	{
//		return m_front == m_rear;
//	}
//
//	int size() const//获取元素个数
//	{
//		return m_size;
//
//	}
//
//	void show()const//打印
//	{
//		int p = m_front;
//		while (p != m_rear)
//		{
//			cout << pQue[p] << " ";
//			p = (p + 1) % m_cap;
//		}
//		cout << endl;
//	}
//
//private:
//	void expend(int val)//扩容
//	{
//		int p = m_front;
//		int* q = new int(val);
//		int i = 0;
//		while (p != m_rear)
//		{
//			q[i] = pQue[p];
//			p = (p + 1) % m_cap;
//			i++;
//		}
//		delete[] pQue;
//		pQue = q;
//		m_cap = val;
//		m_front = 0;
//		m_rear = i;
//	}
//
//private:
//	int* pQue;
//	int m_cap;
//	int m_front;
//	int m_rear;
//	int m_size;
//};
//
//int main()
//{
//	Queue que;
//	cout << que.empty() << endl;
//	srand(time(nullptr));
//	for (size_t i = 0; i < 10; i++)
//	{
//		que.push(rand() % 10);
//	}
//	que.show();
//	que.push(11);
//	que.show();
//	que.pop();
//	que.show();
//	cout << que.front() << endl;
//	cout << que.size() << endl;
//	cout << que.back() << endl;
//}