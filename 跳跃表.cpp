//#include<iostream>
//#include<time.h>
//using namespace std;
//
//class SkipList
//{
//public:
//	SkipList()
//	{
//		m_head = new HeadNode(1);
//	}
//	~SkipList()
//	{
//		for (size_t i = 0; i < m_head->m_level; i++)
//		{
//			Node* cur = m_head->next;
//			while (cur != nullptr)
//			{
//				Node* temp = cur->next;
//				delete cur;
//				cur = temp;
//			}
//			cur = m_head;
//			m_head = static_cast<HeadNode*>(cur->down);
//
//			delete cur;
//
//			
//		}
//	}
//public:
//	//搜索操作
//	bool find(int val)
//	{
//		Node* cur = m_head->next;
//		Node* pre = m_head;
//
//		while (1)
//		{
//			if (cur != nullptr)
//			{
//				if (cur->m_data < val)
//				{
//					pre = cur;
//					cur = pre->next;
//					continue;
//				}
//				else if (cur->m_data == val)
//				{
//					return true;
//				}
//
//			}
//			if (pre->down == nullptr)
//			{
//				break;
//			}
//
//			pre = pre->down;
//			cur = pre->next;
//
//
//		}
//		return false;
//	}
//
//	//插入操作
//	void add(int val)
//	{
//		if (find(val))
//		{
//			return;
//		}
//		int level = getLevel();
//		if (level > m_head->m_level)
//		{
//			level = m_head->m_level + 1;
//			HeadNode* hhead = new HeadNode(level);
//			hhead->down = m_head;
//			m_head = hhead;
//		}
//		Node** nodelist = new Node*[level];
//		for (size_t i = 0; i < level; i++) // 修正循环范围，初始化所有 nodelist 元素
//		{
//			nodelist[i] = new Node(val);
//			if (i > 0)
//			{
//				nodelist[i]->down = nodelist[i - 1];
//			}
//		}
//		Node* head = m_head;
//		for (size_t i = m_head->m_level; i > level; i--)
//		{
//			head = head->down;
//		}
//		Node* pre = head;
//		Node* cur = pre->next;
//		for (size_t i = 0; i < level; i++)
//		{
//			while (cur != nullptr && val > cur->m_data) {
//				pre = cur;
//				cur = cur->next;
//			}
//			nodelist[level - i - 1]->next = cur; // 修正下标，防止越界
//			pre->next = nodelist[level - i - 1];
//			pre = pre->down;
//			if (pre != nullptr)
//			{
//				cur = pre->next;
//			}
//		}
//		delete[] nodelist;
//	}
//
//	//打印操作
//	void show()const
//	{
//		Node* h = m_head;
//
//		while (h!=nullptr)
//		{
//			Node* node = h->next;
//
//			while (node!=nullptr)
//			{
//				cout << node->m_data << " ";
//				node = node->next;
//			}
//			cout << endl;
//			h = h->down;
//			
//
//		}
//		cout << endl;
//	}
//
//	//删除操作
//	void remove(int val)
//	{
//		Node* cur = m_head->next;
//		Node* pre = m_head;
//
//		while (1)
//		{
//			if (cur != nullptr)
//			{
//				if (cur->m_data < val)
//				{
//					pre = cur;
//					cur = pre->next;
//					continue;
//				}
//				else if (cur->m_data == val)
//				{
//					while (cur != nullptr)
//					{
//						pre->next = cur->next;
//						cur = cur->down;
//					}
//					
//				}
//
//			}
//			if (pre->down == nullptr)
//			{
//				break;
//			}
//
//			pre = pre->down;
//			cur = pre->next;
//
//
//		}
//		return ;
//	}
//
//private:
//	int getLevel()
//	{
//		int level = 1;
//		while (rand()%2==1)
//		{
//			level++;
//		}
//		return level;
//	}
//private:
//
//	struct Node
//	{
//		Node(int data = int())
//			:m_data(data)
//
//			, next(nullptr)
//			, down(nullptr)
//		{
//		}
//		int m_data;
//		Node* next;
//		Node* down;
//
//	};
//	struct HeadNode :public Node
//	{
//		HeadNode(int level)
//			:m_level(level)
//		{
//		}
//		int m_level;
//	};
//	HeadNode* m_head;
//};
//
//int main()
//{
//	SkipList sl;
//	srand(time(NULL));
//	for (size_t i = 0; i < 20; i++)
//	{
//		sl.add(rand() % 100+10);
//
//	}
//	sl.add(11);
//	sl.remove(11);
//	cout << sl.find(11) << endl;
//	sl.show();
//}
//
