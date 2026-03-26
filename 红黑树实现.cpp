#include<iostream>
using namespace std;

template<typename T>
class RbTree
{
public:
	RbTree()
		:root(nullptr)
	{
	}
	~RbTree() {}
	//插入操作
	void insert(const T& val)
	{
		
		if (root == nullptr)
		{
			root = new Node(val);
			return;
		}
		Node* cur = root;
		Node* parent = nullptr;
		
			while (cur != nullptr)
			{
				if (val > cur->m_data)
				{
					parent = cur;
					cur = cur->right;

				}
				else if (val < cur->m_data)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					return;
				}
			}
			Node* node = new Node(val, nullptr, nullptr, RED, parent );
			if (parent->m_data > val)
			{
				parent->left = node;
			}
			else
			{
				parent->right = node;
			}
			if (getColor(parent) == RED)
			{
				fixAfterinsert(node);
			}

		
	}

	//删除操作
	void remove(const T& val)
	{
		if (root == nullptr)
		{

			return;
		}
		
		Node* cur = root;
		while (cur != nullptr)
		{
			if (val< cur->m_data)
			{
				cur = cur->left;
			}
			else if (cur->m_data< val)
			{
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
			Node* pre = cur->left;
			while (pre->right != nullptr)
			{
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
		if (child != nullptr)
		{
			child->parent = cur->parent;
			if (cur->parent == nullptr)
			{
				root = child;
			}
			else
			{
				if (cur->parent->left == cur)
				{
					cur->parent->left = child;
				}
				else
				{
					cur->parent->right = child;

				}
			}
			Color c = getColor(cur);
			delete cur;
			if (c == BLACK)
			{
				fixAfterremove(child);
			}
			
		}
		else
		{
			if (getParent(cur) == nullptr)
			{
				delete cur;
				root = nullptr;
				return;
			}
			else
			{
				if (getColor(cur) == BLACK)
				{
					fixAfterremove(cur);
				}
				if (getLeft(getParent(cur)) == cur)
				{
					cur->parent->left = nullptr;
				}
				else
				{
					cur->parent->right = nullptr;
				}
				delete cur;
			}
		}
		

		
	}
private:

	enum Color
	{
		RED,
		BLACK

	};
	struct Node
	{


		Node(T data = T(), Node* left = nullptr, Node* right = nullptr, Color color = BLACK, Node* parent = nullptr)
			: m_data(data)
			, left(left)
			, right(right)
			, parent(parent)
			, color(color)
		{
		}




		T m_data;
		Node* left;
		Node* right;
		Node* parent;
		Color color;

	};

	//获取节点颜色
	Color getColor(Node* node)
	{
		return node ==nullptr ? BLACK : node->color;
	}
	//设置节点颜色
	void setColor(Node* node, Color color)
	{
		node->color = color;
	}
	//返回节点左孩子
	Node* getLeft(Node* node)
	{
		return node->left;
	}
	//返回节点右孩子
	Node* getRight(Node* node)
	{
		return node->right;
	}
	//返回节点父亲
	Node* getParent(Node* node)
	{
		return node->parent;
	}
	//左旋转操作
	void leftRotate(Node* node)
	{
		Node* child = node->right;
		child->parent = node->parent;
		if (node->parent == nullptr)
		{
			root = child;
		}
		else
		{
			if (node->parent->left == node)
			{
				node->parent->left = child;
			}
			else
			{
				node->parent->right == child;
			}
		}
		node->right = child->left;
		if (child->left != nullptr)
		{
			child->left->parent = node;
		}

		child->left = node;
		node->parent = child;
	}
	//右旋转操作
	void rightRotate(Node* node)
	{
		Node* child = node->left;
		child->parent = node->parent;
		if (node->parent == nullptr)
		{
			root = child;
		}
		else
		{
			if (node->parent->left == node)
			{
				node->parent->left = child;
			}
			else
			{
				node->parent->right == child;
			}
		}
		node->left = child->right;
		if (child->right != nullptr)
		{
			child->right->parent = node;
		}

		child->right = node;
		node->parent = child;
	}
	//插入调整
	void fixAfterinsert(Node* node)
	{
		while (getColor(node->parent) == RED)
		{
			if (getLeft(getParent(getParent(node))) ==getParent(node))
			{
				Node* uncle = getParent(node->parent)->right;
				if (getColor(uncle) == RED)
				{
					setColor(getParent(node->parent), RED);
					setColor(getParent(node), BLACK);
					setColor(uncle, BLACK);
					node = getParent(node->parent);


				}
				else
				{
					if (getParent(node)->left == node)
					{
						setColor(getParent(node->parent), RED);
						setColor(getParent(node), BLACK);
						rightRotate(getParent(node->parent));
						break;
					}
					else
					{
						node = getParent(node);
						leftRotate(node);
						setColor(getParent(node->parent), RED);
						setColor(getParent(node), BLACK);
						rightRotate(getParent(node->parent));
						break;

					}
				}
			}
			else
			{
				Node* uncle = getParent(node->parent)->left;
				if (getColor(uncle) == RED)
				{
					setColor(getParent(node->parent), RED);
					setColor(getParent(node), BLACK);
					setColor(uncle, BLACK);
					node = getParent(node->parent);



				}
				else
				{
					if (getParent(node)->right == node)
					{
						setColor(getParent(node->parent), RED);
						setColor(getParent(node), BLACK);
						leftRotate(getParent(node->parent));
						break;

					}
					else
					{
						node = getParent(node);
						rightRotate(node);
						setColor(getParent(node), BLACK);
						leftRotate(getParent(node->parent));
						break;

					}
				}
			}

		}
		setColor(root, BLACK);
	}
	//删除调整
	void fixAfterremove(Node* node)
	{
		while (getColor(node) == BLACK)
		{
			if (getLeft(getParent(node)) == node)
			{
				Node* brother = getRight(getParent(node));
				if (getColor(brother) == RED)
				{
					setColor(brother, BLACK);
					setColor(getParent(node), RED);
					leftRotate(getParent(node));
					brother = getRight(getParent(node));
				}
				if (getColor(getRight(brother)) == BLACK && getColor(getLeft(brother)) == BLACK)
				{
					setColor(brother, RED);
					node = getParent(node);
				}
				else
				{
					if (getColor(getRight(brother)) != RED)
					{
						setColor(getLeft(brother), BLACK);
						setColor(brother, RED);
						rightRotate(brother);
						brother = getRight(getParent(node));
					}
					setColor(brother, getColor(getParent(node)));
					setColor(getParent(node), BLACK);
					setColor(getRight(brother), BLACK);
					leftRotate(getParent(node));
					break;
				}

			}
			else
			{
				Node* brother = getLeft(getParent(node));
				if (getColor(brother) == RED)
				{
					setColor(brother, BLACK);
					setColor(getParent(node), RED);
					rightRotate(getParent(node));
					brother = getLeft(getParent(node));
				}
				if (getColor(getLeft(brother)) == BLACK && getColor(getRight(brother)) == BLACK)
				{
					setColor(brother, RED);
					node = getParent(node);
				}
				else
				{
					if (getColor(getLeft(brother)) != RED)
					{
						setColor(getRight(brother), BLACK);
						setColor(brother, RED);
						leftRotate(brother);
						brother = getLeft(getParent(node));
					}
					setColor(brother, getColor(getParent(node)));
					setColor(getParent(node), BLACK);
					setColor(getLeft(brother), BLACK);
					rightRotate(getParent(node));
					break;
				}
			}
		}
		setColor(node, BLACK);
	}

	Node* root;
};

int main()
{
	RbTree<int> rbt;
	for (size_t i = 1; i <= 10; i++)
	{
		rbt.insert(i);
	}
	//rbt.remove(9);
	return 0;
}