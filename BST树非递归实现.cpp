#include<iostream>
#include<functional>
using namespace std;


template<typename T, typename Compare = less<T>>
class BSTtree
{
public:
	BSTtree()
		:root(nullptr)
	{
	}
	~BSTtree() {}
public:
	//插入
	void insert(const T& val)
	{
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}
		Node* parent = nullptr;

		Node* cur = root;

		while (cur != nullptr)
		{
			if (comp(val,cur->m_data))
			{
				parent = cur;
				cur = cur->left;
			}
			else if (comp(cur->m_data,val))
			{
				parent = cur;
				cur = cur->right;
			}
			else//不插入相同的值
				return;
		}
		if (comp(val,parent->m_data))
		{
			parent->left = new Node(val);

		}
		else
		{
			parent->right = new Node(val);
		}

	}

	//删除
	void remove(const T&  val)
	{
		if (root == nullptr)
		{
			return;
		}
		Node* parent = nullptr;
		Node* cur = root;
		while (cur != nullptr)
		{
			if (comp(val, cur->m_data))
			{
				parent = cur;
				cur = cur->left;
			}
			else if(comp(cur->m_data,val))
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				break;
			}
		}
		if (cur == nullptr)
			return;
		if(cur->left!=nullptr&&cur->right!=nullptr)
		{
			parent = cur;
			Node* pre = cur->left;
			while (pre->right != nullptr)
			{
				parent = pre;
				pre = pre->right;
			}
			cur->m_data = pre->m_data;
			cur = pre;
		}

		Node* child = cur->left;
		if (child == nullptr)
		{
			child = cur->right;
		}
		if (parent == nullptr)
		{
			root = child;
		}
		else 
		{
			if (parent->left == cur)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		
		delete cur;
	}

	//查找
	bool find(T val)
	{
		Node* cur = root;
		while (cur != nullptr)
		{
			if (comp(val, cur->m_data))
			{
				cur = cur->left;
			}
			else if (comp(cur->m_data, val))
			{
				cur = cur->right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

private:

	struct Node
	{

		Node(T data = T())
			:m_data(data)
			, left(nullptr)
			, right(nullptr)
		{
		}

		T m_data;
		Node* left;
		Node* right;

	};
	Node* root;
	Compare comp;
};
int main()
{
	int arr[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTtree<int>bst;
	for (int v : arr)
	{
		bst.insert(v);
	}
	
	bst.insert(12);
	cout << bst.find(12) << endl;
	bst.remove(12);
	cout << bst.find(12) << endl;

	return 0;
}