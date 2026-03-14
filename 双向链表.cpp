//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<time.h>
//using namespace std;
//
//struct Node
//{
//	Node(int val = 0)
//		:data(val)
//		, next(nullptr)
//		, pre(nullptr)
//	{
//	}
//	int data;
//	Node* next;
//	Node* pre;
//
//};
//class DoubleLink
//{
//public:
//	DoubleLink()
//	{
//		head = new Node();
//
//	}
//	~DoubleLink()
//	{
//		Node* p = head;
//		while (p != nullptr)
//		{
//			head = head->next;
//
//			delete p;
//			p = head;
//
//
//		}
//	}
//public:
//	void InsertHead(int val)//Í·²å
//	{
//		Node* node = new Node(val);
//		Node* p = head;
//		node->next = p->next;
//		if (p->next != nullptr)
//		{
//			p->next->pre = node;
//		
//			node->pre = head;
//		}
//		head->next = node;
//		
//
//	}
//
//	void TailInsert(int val)//Î²²å
//	{
//		Node* node = new Node(val);
//		Node* p = head;
//		while (p->next != nullptr)
//		{
//			p = p->next;
//		}
//		p->next = node;
//		node->pre = p;
//
//	}
//
//	void Remove(int val)//É¾³ý
//	{
//		Node* p = head->next;
//		if (p == nullptr)
//			return;
//		while (p->data != val)
//		{
//			p = p->next;
//			if (p == nullptr)
//			{
//				return;
//			}
//		}
//		p->pre->next = p->next;
//		if (p->next != nullptr)
//		{
//			p->next->pre = p->pre;
//		}
//		delete p;
//
//		
//
//	}
//
//	bool Find(int val)//²éÕÒ
//	{
//		Node* p = head->next;
//		if (p == nullptr)
//			return false;
//		while (p->data != val)
//		{
//			p = p->next;
//			if (p == nullptr)
//				return false;
//		}
//		return true;
//
//	}
//
//	void show()//´òÓ¡
//	{
//		Node* p = head->next;
//		while (p != nullptr)
//		{
//			cout << p->data << " ";
//			p = p->next;
//
//		}
//		cout << endl;
//	}
//
//private:
//	Node* head;
//};
//
//int main()
//{
//	DoubleLink dlink;
//	srand(time(nullptr));
//	for (size_t i = 0; i < 10; i++)
//	{
//		dlink.InsertHead(rand() % 9);
//
//	}
//	dlink.show();
//	dlink.TailInsert(11);
//	dlink.show();
//	cout << dlink.Find(11) << endl;
//
//	dlink.Remove(11);
//	dlink.show();
//}
