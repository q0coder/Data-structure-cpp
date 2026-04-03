#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class TireTree
{
public:
	TireTree()
	{
		root = new TireNode('\0', 0);
	}

public:

	//添加操作
	void add(const string& str)
	{
		add(root, str);
	}

	//查询操作
	int query(const string& str)
	{
		return query(root, str);
	}

	//排序应用：字典序打印存储的所有字符串
	//前序遍历:VLR
	void Preorder()

	{
		string word;
		vector<string>vec;
		  Preorder(root, word,vec);
		for (auto v : vec)
		{
			cout << v << endl;
		}
		cout << endl;
	}

	//前缀搜索
	void queryPrefix(const string& prefix)
	{
		vector<string>str;
		string word;
		queryPrefix(root, prefix, str);
		for (auto s : str)
		{
			cout << s << endl;
		}
		cout << endl;
	}
private:


	struct TireNode
	{
		TireNode(char data, int freq)
			:m_data(data)
			, m_freq(freq)
		{
		}
		char m_data;
		int m_freq;
		map<char, TireNode*>mp;
	};

	TireNode* root;
	void add(TireNode* node, const string& str)
	{
		TireNode* p = node;
		for (size_t i = 0; i < str.length(); i++)
		{
			auto childit = p->mp.find(str[i]);
			if (childit == p->mp.end())
			{
				TireNode* childNode = new TireNode(str[i], 0);
				p->mp.insert({ str[i], childNode });
				p = childNode;

			}
			else
			{
				p = childit->second;
			}

		}
		p->m_freq++;

	}
	int query(TireNode* node, const string& str)
	{
		TireNode* p = node;
		for (size_t i = 0; i < str.length(); i++)
		{
			auto childit = p->mp.find(str[i]);
			if (childit != p->mp.end())
			{
				p = childit->second;
			}
			else
			{
				return 0;
			}

		}
		return p->m_freq;
	}
	 void Preorder(TireNode* node, string word, vector<string>&vec)
	{
		
		TireNode* p = node;
		if (p != nullptr)
		{
			word.push_back(p->m_data);
		}
		if (p->m_freq > 0)
		{
			vec.push_back(word);
		}

		for (auto s : p->mp)
		{
			Preorder(s.second, word,vec);
		}
		
	}
	 void queryPrefix(TireNode* node, string prefix, vector<string>& str)
	 {
		 TireNode* p = node;
		 for (size_t i = 0; i < prefix.length(); i++)
		 {
			 auto childit = p->mp.find(prefix[i]);
			 if (childit == p->mp.end())
			 {
				 return;
			 }
			 else
			 {
				 p = childit->second;
			 }

		 }
		 Preorder(p, prefix.substr(0, prefix.length() - 1), str);
	 }
};


int main()
{
	TireTree Tr;
	Tr.add("Hello");
	cout << Tr.query("Hello") << endl;
	Tr.Preorder();
	Tr.queryPrefix("He");

	return 0;
}
