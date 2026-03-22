#include<iostream>
#include<functional>
#include<stack>
#include<queue>
#include<vector>
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
	void n_insert(const T& val)
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
			if (comp(val, cur->m_data))
			{
				parent = cur;
				cur = cur->left;
			}
			else if (comp(cur->m_data, val))
			{
				parent = cur;
				cur = cur->right;
			}
			else//不插入相同的值
				return;
		}
		if (comp(val, parent->m_data))
		{
			parent->left = new Node(val);

		}
		else
		{
			parent->right = new Node(val);
		}

	}

	//递归插入
	void insert(const T& val)
	{
		root = insert(root, val);
	}

	//删除
	void n_remove(const T& val)
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
			else if (comp(cur->m_data, val))
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
		if (cur->left != nullptr && cur->right != nullptr)
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

	//递归删除
	void remove(const T& val)
	{
		root = remove(root, val);
	}

	//查找
	bool n_find(T val)const
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

	//递归查找
	bool find(const T& val)
	{
		return find(root, val);
	}

	//递归前序遍历VLR
	void preOrder()
	{
		preOrder(root);
	}

	//前序遍历非递归实现
	void n_preOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		stack<Node*>s;
		s.push(root);
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			cout << top->m_data << " ";
			if (top->right != nullptr)
			{
				s.push(top->right);
			}
			if (top->left != nullptr)
			{
				s.push(top->left);
			}

		}
	}

	//递归中序遍历LVR(中序遍历是升序)
	void inOrder()
	{
		inOrder(root);
	}

	//中序遍历非递归实现
	void n_inOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		stack<Node*>s;
		Node* cur = root;

		while (cur != nullptr)
		{
			s.push(cur);
			cur = cur->left;
		}
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			cout << top->m_data << " ";
			cur = top->right;
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left;
			}
		}
	}

	//递归后序遍历LRV
	void postOrder()
	{
		postOrder(root);
	}

	//后续遍历的非递归实现
	void n_postOrder()
	{
		if (root == nullptr)
		{
			return;
		}
		stack<Node*>s1;
		stack<Node*>s2;
		s1.push(root);
		while (!s1.empty())
		{
			Node* top = s1.top();
			s1.pop();
			s2.push(top);

			if (top->left != nullptr)
			{
				s1.push(top->left);
			}
			if (top->right != nullptr)
			{
				s1.push(top->right);
			}
		}
		while (!s2.empty())
		{
			Node* cur = s2.top();
			cout << cur->m_data << " ";
			s2.pop();
		}
	}

	//递归层序遍历
	void levelOrder()
	{
		int h = level();
		for (size_t i = 0; i < h; i++)
		{
			levelOrder(root, i);
		}
	}

	//层序遍历非递归实现
	void n_levelOrder()
	{
		if (root == nullptr)
		{
			return;
		}

		queue<Node*>q;
		q.push(root);
		while (!q.empty())
		{
			Node* front = q.front();
			cout << front->m_data << " ";
			q.pop();
			if (front->left != nullptr)
			{
				q.push(front->left);
			}
			if (front->right != nullptr)
			{
				q.push(front->right);

			}

		}
	}

	//求BST树的层数
	int level()
	{
		return level(root);
	}

	//递归求BST树节点个数
	int number()
	{
		return number(root);
	}

	//BST树区间元素搜索问题[i,j](非递归实现)
	void n_findValues(vector<T>& vec, int i, int j)
	{

		if (root == nullptr)
		{
			return;
		}
		stack<Node*>s;
		Node* cur = root;

		while (cur != nullptr)
		{
			s.push(cur);
			cur = cur->left;
		}
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			if (top->m_data >= i && top->m_data <= j)
			{
				vec.push_back(top->m_data);
			}
			cur = top->right;
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left;
			}
		}

	}

	//BST树区间元素搜索问题[i,j](递归实现)
	void findValues(vector<T>& vec, int i, int j)
	{
		findValues(vec, i, j, root);
	}

	//判断一颗二叉树是否是BST树
	bool isBSTtree()
	{
		Node* node = nullptr;
		return isBSTtree(root, node);
	}

	//判断一颗小树是否是大树的子树
	bool isChildtree()
	{

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
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->m_data << " ";
			preOrder(node->left);
			preOrder(node->right);
		}


	}

	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left);
			cout << node->m_data << " ";
			inOrder(node->right);
		}
	}

	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->m_data << " ";

		}
	}

	void levelOrder(Node* node, int i)
	{
		if (node == nullptr)
			return;
		if (i == 0)
		{
			cout << node->m_data << " ";
			return;
		}
		levelOrder(node->left, i - 1);
		levelOrder(node->right, i - 1);
	}

	int level(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = level(node->left);
		int right = level(node->right);

		return left > right ? left + 1 : right + 1;
	}

	int number(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = number(node->left);
		int right = number(node->right);
		return left + right + 1;
	}

	Node* insert(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return new Node(val);

		}
		if (node->m_data == val)
		{
			return node;

		}
		else if (comp(node->m_data, val))
		{
			node->right = insert(node->right, val);
		}
		else
		{
			node->left = insert(node->left, val);
		}
		return node;
	}

	bool find(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return false;

		}
		if (node->m_data == val)
		{
			return true;

		}
		else if (comp(node->m_data, val))
		{
			return find(node->right, val);
		}
		else
		{
			return find(node->left, val);
		}

	}

	Node* remove(Node* node, const T& val)
	{
		if (node == nullptr)
			return nullptr;
		if (node->m_data == val)
		{

			if (node->left != nullptr && node->right != nullptr)
			{
				Node* pre = node->left;
				while (pre->right != nullptr)
				{
					pre = pre->right;
				}
				node->m_data = pre->m_data;
				node->left = remove(node->left, pre->m_data);
			}
			else
			{
				if (node->left != nullptr)
				{
					Node* left = node->left;
					delete node;
					return left;
				}
				else if (node->right != nullptr)
				{
					Node* right = node->right;
					delete node;
					return right;
				}
				else
				{
					delete node;
					return nullptr;
				}
			}

		}
		else if (comp(node->m_data, val))
		{
			node->right = remove(node->right, val);
		}
		else
		{
			node->left = remove(node->left, val);
		}
		return node;
	}

	void findValues(vector<T>& vec, int i, int j, Node* node)
	{
		if (node != nullptr)
		{
			if (node->m_data >= i)
			{
				findValues(vec, i, j, node->left);

			}
			if (node->m_data >= 10 && node->m_data <= 50)
			{
				vec.push_back(node->m_data);
			}
			if (node->m_data <= j)
			{
				findValues(vec, i, j, node->right);

			}
		}
	}

	bool isBSTtree(Node* node, Node* node2)
	{
		if (node == nullptr)
		{
			return true;
		}
		if (!isBSTtree(node->left, node2))
		{
			return false;
		}
		if (node2 != nullptr)
		{
			if (node->m_data < node2->m_data)
			{
				return false;
			}
		}
		node2 = node;
		isBSTtree(node->right,node2);
	}


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
	bst.n_preOrder();
	cout << endl;
	bst.n_inOrder();
	cout << endl;
	bst.n_postOrder();
	cout << endl;
	bst.n_levelOrder();
	bst.insert(12);
	/*vector<int>vec;
	bst.findValues(vec, 10, 50);
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec.at(i) << " ";
	}*/
	cout<<bst.isBSTtree();
	return 0;
}