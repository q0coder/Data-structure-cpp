#include<iostream>
#include<time.h>
using namespace std;

class LinkQueue
{
public:
	LinkQueue()
	{
		head = new Node();
		head->next = head;
		head->pre = head;
	}
	~LinkQueue()
	{
		Node* p = head->next;
		while (p!=head )
		{
			head->next = p->next;
			p->next->pre = head;

			delete p;
			p = head->next;
		
		}
		delete head;
		head = nullptr;
	}
public:
	void push(int val)//入队
	{
		Node* node = new Node(val);
		Node* p = head->pre;
		
		p->next = node;
		node->pre = p;
		node->next = head;
		head->pre = node;
		m_size++;
	}

	void pop()//出队
	{
		if (head->next == head)
			throw "Queue is empty";
		Node* p = head->next;
		head->next = head->next->next;
		delete p;
		head->next->next->pre = head;
	
		m_size--;

	}

	int front() const//获取队头元素
	{
		if (head->next == head)
			throw "Queue is empty";
		return head->next->data;
	}

	int back() const//获取队尾元素
	{
		if (head->next == head)
			throw "Queue is empty";
		
		
		return head->pre->data;
	}

	bool empty() const//判断队列是否为空
	{
		return head->next == head;
	}

	void show()const//打印
	{
		Node* p = head->next;
		while (p->next != head)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	int size() const//获取队列元素个数
	{
		return m_size;
	}

private:

	struct Node
	{
		Node(int val=0)
			:data(val)
			,next(nullptr)
			,pre(nullptr)
		{ }
		int data;
		Node* next;
		Node* pre;
	};
	Node* head;
	int m_size;
};

int main()
{
	LinkQueue lq;
	cout << lq.empty() << endl;
	srand(time(nullptr));
	for (size_t i = 0; i < 10; i++)
	{
		lq.push(rand() % 9);
	}
	lq.show();
	cout << lq.empty() << endl;
	cout << lq.front()<< endl;
	cout << lq.back() << endl;
	lq.pop();
	lq.show();
	cout << lq.size() << endl;



}