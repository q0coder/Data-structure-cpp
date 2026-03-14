#include<iostream>
#include<time.h>
using namespace std;

//class CircleLink
//{
//public:
//	CircleLink()
//	{
//		head = new Node();
//		tail = head;
//		head->next = head;
//	}
//	~CircleLink()
//	{
//		Node* p = head->next;
//		while (p != head)
//		{
//			head->next = p->next;
//			delete p;
//			p = head->next;
//		}
//		delete head;
//	}
//
//public:
//
//	void TailInsert(int val)//尾插
//	{
//		Node* node=new Node(val);
//		//node->next = tail->next;
//		tail->next = node;
//		tail = node;
//		tail->next = head;
//	}
//
//	void HeadInsert(int val)//头插
//	{
//		Node* node = new Node(val);
//		node->next = head->next;
//		head->next = node;
//		if (node->next == head)
//		{
//			tail = node;
//		}
//
//	}
//
//	void Remove(int val)//删除
//	{
//		Node* p = head;
//		while (p->next->data != val&&p->next!=head)
//		{
//			p = p->next;
//		}
//		if (p->next->data == val)
//		{
//			Node* q = p->next;
//			p->next = p->next->next;
//			delete q;
//		}
//		else
//			return;
//
//	}
//
//	bool Find(int val) const//查找
//	{
//		Node* p = head;
//		while (p->next->data != val )
//		{
//			if (p->next == head)
//			{
//				return false;
//			}
//			
//			p = p->next;
//		}
//		return true;
//
//	}
//
//	void show() const//打印
//	{
//		Node* p = head->next;
//		while (p!= head)
//		{
//			cout << p->data<<" ";
//			p = p->next;
//			
//		}
//		cout << endl;
//	}
//
//
//private:
//	struct Node
//	{
//	
//		Node(int val = 0) :data(val), next(nullptr) {};
//		int data;
//		Node* next;
//	};
//private:
//	Node* head;
//	Node* tail;
//};
//
//int main()
//{
//	CircleLink c;
//	srand(time(0));
//	c.HeadInsert(10);
//	c.show();
//	for (size_t i = 0; i < 10; i++)
//	{
//		c.TailInsert(rand() % 9);
//	}
//	c.show();
//	c.HeadInsert(11);
//	c.show();
//	c.TailInsert(12);
//	c.show();
//	c.Remove(12);
//	c.show();
//	cout << c.Find(11) << endl;
//
//}

struct Node
{

	Node(int val = 0) :data(val), next(nullptr) {};
	int data;
	Node* next;
};

void Joseph(Node* head, int k, int m)//约瑟夫环问题
{
	Node* p = head;
	Node* q = head;
	for (size_t i = 1; i < k; i++)
	{
		p = p->next;
		q = q->next;
	}
	while (q->next != head)
	{
		q = q->next;
	}
	while (1)
	{

		for (size_t i = 1; i < m; i++)
		{
			q = p;
			p = p->next;
		}

		cout << p->data << endl;
		if (p == q)
		{
			delete p;
			break;

		}
		q->next = p->next;

		delete p;

		p = q->next;
		
		

		



		

	}



}

int main()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n1;
	int k = 1;
	int m = 1;
	Joseph(n1, k, m);
}