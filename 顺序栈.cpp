#include<iostream>
#include<time.h>
#include<string.h>
using namespace std;

//顺序栈
class SeqStack
{
public:
	SeqStack(int size = 10)
		:mtop(0)
		, mcap(size)
	{
		mpStack = new int[mcap];
	}
	~SeqStack()
	{
		delete[]mpStack;
		mpStack = nullptr;
	}
public:
	void push(int val)//入栈
	{
		if (mtop == mcap)
			expend(2 * mcap);
		mpStack[mtop] = val;
		mtop++;
	}

	void pop()//出栈
	{
		if (mtop == 0)
			throw "Stack is empty";
		mtop--;
	}

	int top()const//获取栈顶(的元素)
	{
		if (mtop == 0)
			throw "Stack is empty";
		return mpStack[mtop - 1];
	}

	bool empty()const//判断栈是否为空
	{
		return mtop == 0;
	}

	int size()const//获取栈(元素)的大小
	{
		return mtop;
	}

	void show()const
	{
		for (size_t i = 0; i < mtop; i++)
		{
			cout << mpStack[i] << " ";
		}cout << endl;
	}

private:
	void expend(int val)//扩容
	{
		int* p = mpStack;
		mpStack = new int[val];

		memcpy(mpStack, p, sizeof(int) * mcap);
		delete[]p;
		mcap = val;
	}

private:
	int* mpStack;
	int mtop;
	int mcap;
};

int main()
{
	
	SeqStack stack;
	srand(time(nullptr));
	//stack.top();
	//stack.pop();
	cout<<stack.empty()<<endl;
	for (size_t i = 0; i < 10; i++)
	{
		stack.push(rand()%9);
	}
	stack.show();
	stack.push(11);
	stack.show();
	stack.pop();
	stack.show();
	cout << stack.top() << endl;
	cout << stack.size() << endl;

}