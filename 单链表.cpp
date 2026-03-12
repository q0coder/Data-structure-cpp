#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
using namespace std;

//单链表
struct Node
{
	Node(int data = 0) :Data(data), Next(nullptr) {};
	int Data;
	Node* Next;
};

class clink
{
public:
	clink()
	{
		head = new Node();
	}
	~clink()
	{
		Node* p = head;

		while (p != nullptr)
		{
			head = head->Next;
			delete p;
			p = head;
		}
		head = nullptr;
	}
public:
	void InsertTail(int val)//尾插
	{
		Node* p = head;
		while (p->Next != nullptr)
		{
			p = p->Next;
		}
		Node* node = new Node(val);

		p->Next = node;


	}

	void InsertHead(int val)//头插
	{
		Node* node = new Node(val);
		node->Next = head->Next;
		head->Next = node;

	}

	void Remove(int val)//单删
	{
		Node* q = head;
		Node* p = head->Next;
		while (p != nullptr)
		{
			if (p->Data == val)
			{
				q->Next = p->Next;
				delete p;
				return;
			}
			else
			{
				q = p;
				p = p->Next;
			}
		}

	}

	void RemoveOut(int val)//多删
	{
		Node* q = head;
		Node* p = head->Next;
		while (p != nullptr)
		{
			if (p->Data == val)
			{
				q->Next = p->Next;
				delete p;
				p = q->Next;

			}
			else
			{
				q = p;
				p = p->Next;
			}
		}
	}

	bool find(int val)//查找
	{
		Node* p = head->Next;
		while (p != nullptr)
		{
			if (p->Data == val)
			{
				return true;
			}

			p = p->Next;
		}
		return false;

	}

	void Reserve()//逆序
	{
		Node* p = head->Next;

		head->Next = nullptr;
		while (p != nullptr)
		{
			Node* q = p->Next;
			p->Next = head->Next;
			head->Next = p;
			p = q;
			if (q != nullptr)
				q = q->Next;

		}
	}

	void show()//打印
	{
		Node* p = head->Next;
		while (p != nullptr)
		{
			cout << p->Data << " ";
			p = p->Next;
		}
		cout << endl;
	}

	friend void Reservelink(clink& link);
	friend bool GetLastNode(clink& link, int k, int& val);
	friend void MergeLink(clink& link1, clink& link2);


private:

	Node* head;
};


void Reservelink(clink& link)//c方法逆序
{
	Node* p = link.head->Next;
	link.head->Next = nullptr;
	while (p != nullptr)
	{
		Node* q = p->Next;

		p->Next = link.head->Next;
		link.head->Next = p;

		p = q;

	}
}

bool  GetLastNode(clink& link, int k, int& val)//求倒数第k个节点的值
{

	if (k < 1)
		return false;
	Node* p = link.head->Next;
	Node* q = link.head->Next;
	for (size_t i = 0; i < k; i++)
	{
		if (p == nullptr)
		{
			return false;
		}
		p = p->Next;
	}
	while (p != nullptr)
	{
		p = p->Next;
		q = q->Next;
	}
	val = q->Data;
	return true;

}

void MergeLink(clink& link1, clink& link2)//有序单链表合并
{
	Node* p = link1.head->Next;
	Node* q = link2.head->Next;
	Node* last=link1.head;
	//link2.head->Next = nullptr;
	while (p != nullptr && q != nullptr)
	{
		if (p->Data > q->Data)
		{
			last->Next = q;
			q = q->Next;
			last = last->Next;

		}
		else
		{
			last->Next = p;
			p = p->Next;
			last = last->Next;
		}
	}

}

int main()
{
	//int kval;
	/*srand(time(0));
		clink c;
		for (size_t i = 0; i < 10; i++)
		{
			int val = rand() % 9;
			c.InsertTail(val);

		}*/
	clink c1;
	int arr1[] = { 2,4,6,8,10 };
	int arr2[] = { 1,3,5,7,9 };
	for (int v : arr1)
	{
		c1.InsertTail(v);
	}
	c1.show();

	clink c2;
	for (int v : arr2)
	{
		c2.InsertTail(v);
	}
	c2.show();
	MergeLink(c1, c2);
	c1.show();

	/*Reservelink(c);
	c.show();
	cout<<GetLastNode(c,0,kval)<<endl;
	cout << kval << endl;*/
}

//int main()
//{
//	srand(time(0));
//	clink c;
//	for (size_t i = 0; i < 10; i++)
//	{
//		int val = rand() % 9;
//		c.InsertTail(val);
//		cout << val << " ";
//		
//	}
//	cout << endl;
//	c.show();
//	c.InsertHead(10);
//	c.show();
//	
//	c.InsertTail(11);
//	c.InsertTail(11);
//	c.InsertTail(11);
//
//	c.show();
//	c.Remove(11);
//	
//	c.show();
//	c.RemoveOut(11);
//	c.show();
//	cout << c.find(12) << endl;
//	
//	c.Reserve();
//	c.show();
//}

