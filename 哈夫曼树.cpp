#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;
using   uint = unsigned int;

class HuffmanTree
{
public:
	HuffmanTree()
		:root(nullptr)
	{
	}

	//´´½¨¹þ·òÂüÊ÷
	void create(string str)
	{
		unordered_map<char, uint>dataMap;

		for (char s : str)
		{
			dataMap[s]++;
		}
		for (auto pair : dataMap)
		{
			p_que.push(new Node(pair.first, pair.second));

		}
		while (p_que.size() > 1)
		{
			Node* n1 = p_que.top();
			p_que.pop();

			Node* n2 = p_que.top();
			p_que.pop();

			Node* node = new Node('\0', n1->weight + n2->weight);
			node->left = n1;
			node->right = n2;
			p_que.push(node);
		}
		root = p_que.top();

		p_que.pop();
	}


	//Êä³ö¹þ·òÂü±àÂë
	void huffMancode()
	{
		if (root == nullptr)
		{
			return;
		}

		string code;
		huffMancode(root, code);
		for (auto pair : mp)
		{
			cout << pair.first << ": " << pair.second << endl;
		}

	}


private:
	struct Node
	{
		Node(char data, uint w)
			:m_data(data)
			, weight(w)
			, left(nullptr)
			, right(nullptr)
		{
		}
		bool operator>(const Node*& a)
		{
			return weight > a->weight;
		}
		char m_data;
		uint weight;
		Node* left;
		Node* right;
	};



	Node* root;
	unordered_map<char, string>mp;
	using minHeap = priority_queue < Node*, vector<Node*>, greater<Node*> >;
	minHeap p_que;


private:
	void huffMancode(Node* node, string code)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			mp.emplace(node->m_data, code);
			return;
		}

		huffMancode(node->left, code + '0');


		huffMancode(node->right, code + '1');


	}
};

int main()
{
	HuffmanTree ht;
	ht.create("ABACDAEFDEG");
	ht.huffMancode();
}