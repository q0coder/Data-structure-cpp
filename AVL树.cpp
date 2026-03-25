#include<iostream>
#include<cmath>
using namespace std;

template<typename T>
class AVLTree
{
public:
	AVLTree()
		:root(nullptr)
	{ }
	~AVLTree(){}

	//AVL树插入操作
	void insert(const T&val )
	{
		root=insert(val, root);
	}

	//删除操作
	void remove(const T& val)
	{
		root = remove(val,root);
	}

private:
	struct Node
	{
		Node(T data=T())
			:m_data(data)
			,left(nullptr)
			,right(nullptr)
			,height(1)
		{ }
		


		T m_data;
		Node* left;
		Node* right;
		int height;
	};

	//获取节点高度
	int getHeight(Node* node)
	{
		return node == nullptr ? 0 : node->height;
	}

	//右旋转操作
	Node* rightRotate(Node* node)
	{
		Node* child = node->left;
		node->left = child->right;
		child->right = node;

		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		child->height = max(getHeight(child->left), getHeight(child->right)) + 1;
		return child;

	}

	//左旋转操作
	Node* leftRotate(Node* node)
	{
		Node* child = node->right;
		node->right = child->left;
		child->left = node;

		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
		child->height = max(getHeight(child->left), getHeight(child->right)) + 1;
		return child;

	}

	//左平衡操作(左-右)
	Node* leftBalance(Node* node)
	{
		node->left= leftRotate(node->right);
		return rightRotate(node);


	}

	//右平衡操作(右-左)
	Node* rightBalance(Node* node)
	{
		node->right= rightRotate(node->left);

		 return leftRotate(node);


	}

	Node* insert(const T& val,Node* node)
	{
		if (node == nullptr)
		{
			return new Node(val);

		}
		if (node->m_data == val)
		{
			return node;
		}
		else if (node->m_data > val)
		{
			node->left = insert(val, node->left);
			if ((getHeight(node->left) - getHeight(node->right))>1)
			{
				if (getHeight(node->left->left) >= getHeight(node->left->right))
				{
					node = rightRotate(node);
				}
				else 
				{
					node = rightBalance(node);
				}
			}
			

		}
		else
		{
			node->right = insert(val, node->right);
			if ((getHeight(node->right) - getHeight(node->left)) > 1)
			{
				if (getHeight(node->right->right) >= getHeight(node->right->left))
				{
					node = leftRotate(node);
				}
				else
				{
					node = leftBalance(node);
				}
			}
		}
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;


		return node;
	}

	Node* remove(const T& val, Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->m_data > val)
		{
			node->left = remove(val, node->left);
			if ((getHeight(node->right) - getHeight(node->left)) > 1)
			{
				if (getHeight(node->right->right) >= getHeight(node->right->left))
				{
					node = leftRotate(node);
				}
				else
				{
					node = leftBalance(node);
				}
			}
			
		}
		else if(node->m_data < val)
		{
			node->right = remove(val, node->right);
			if ((getHeight(node->left) - getHeight(node->right)) > 1)
			{
				if (getHeight(node->left->left) >= getHeight(node->left->right))
				{
					node = rightRotate(node);
				}
				else
				{
					node = rightBalance(node);
				}
			}
		}
		else
		{
			if (node->left != nullptr && node->right != nullptr)
			{
				if (getHeight(node->left) >= getHeight(node->right))
				{
					Node* pre = node->left;
					while (pre->right != nullptr)
					{
						pre = pre->right;
					}
					node->m_data = pre->m_data;
					
					node->left = remove( pre->m_data, node->left);
				}
				else
				{
					Node* last = node->right;
					while (last->left != nullptr)
					{
						last = last->left;
					}
					node->m_data = last->m_data;
					node->right = remove( last->m_data, node->right);

				}
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
		node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

		return node;

	}

	Node* root;
};

int main()
{
	AVLTree<int> avl;
	for (size_t i = 1; i <= 10; i++)
	{
		avl.insert(i);
	}
	
	avl.remove(10);
	return 0;
}