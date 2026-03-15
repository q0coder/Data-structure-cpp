//#include<iostream>
//#include<time.h>
//using namespace std;
//
//struct Node
//{
//	Node(int val=0)
//		:data(val)
//		,next(nullptr)
//	{ }
//	int data;
//	Node* next;
//};
//
//class LinkStack
//{
//public:
//	LinkStack()
//	{
//		head = new Node();
//	}
//	~LinkStack()
//	{
//		Node* p = head;
//		while (p != nullptr)
//		{
//			head = head->next;
//			delete p;
//			p = head;
//		}
//		head = nullptr;
//	}
//
//public:
//
//	void push(int val)//入栈(头插)
//	{
//		Node* node = new Node(val);
//		node->next = head->next;
//		head->next = node;
//	}
//
//	void pop()//出栈
//	{
//		if (head->next == nullptr)
//			throw "stack is empty";
//		Node* p = head->next;
//		head->next = p->next;
//		delete p;
//		p = nullptr;
//	}
//
//	int top() const//获取栈顶(的元素)
//	{
//		if (head->next == nullptr)
//			throw "stack is empty";
//		return head->next->data;
//	}
//
//	bool empty() const//判断栈是否为空
//	{
//		return head->next == nullptr;
//	}
//
//	int size() const//获取栈(元素)的大小
//	{
//		int num = 0;
//		Node* p = head->next;
//		while (p != nullptr)
//		{
//			p = p->next;
//			num++;
//		}
//		return num;
//	}
//
//	void show() const//打印
//	{
//		Node* p = head->next;
//		while (p != nullptr)
//		{
//			cout << p->data << " ";
//			p = p->next;
//		}
//		cout << endl;
//	}
//
//private:
//	Node* head;
//	
//};
//
//int main()
//{
//	LinkStack ls;
//	srand(time(nullptr));
//	cout << ls.empty() << endl;
//	for (size_t i = 0; i < 10; i++)
//	{
//		ls.push(rand() % 9);
//	}
//	ls.show();
//	ls.push(11);
//	ls.show();
//	ls.pop();
//	ls.show();
//	cout << ls.top() << endl;
//	cout << ls.size() << endl;
//}