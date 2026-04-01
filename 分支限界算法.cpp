#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//¬÷¥¨◊∞‘ÿŒ Ã‚

int w[]{ 12,8,15 };
const int n = sizeof(w)/sizeof(w[0]);

int i = 0;
int c = 27;
int cw = 0;
int r = 0;
int bestw = 0;

struct Node
{
	Node(int w,int l,Node* node,bool isleft)
		:weight(w)
		,level(l)
		,parent(node)
		,isLeft(isleft)

	{ }
	int weight;
	int level;
	Node* parent;
	bool isLeft;


};
Node* bestnode = nullptr;

queue<Node*>que;

void addliveNode(int w, int level, Node* parent, bool isLeft)
{
	Node* node =new Node(w, level, parent, isLeft);
	que.push(node);

	if (level == n &&  w == bestw)
	{
		bestnode = node;
	}
}


int maxBound(int level)
{
	int s = 0;
	for (int j = level + 1; j < n; j++)
	{
		s += w[j];
	}
	return s;
}


int main()
{

	Node* node = nullptr;
	while (i < n)
	{
		int wt = cw + w[i];
		if (wt <= c)
		{
			if (wt > bestw)
			{
				bestw = wt;
			}
			//que.push(Node(wt, i + 1));
			addliveNode(wt, i + 1, node, true);
		}
		//que.push(Node(cw, i + 1));
		r = maxBound(i);
		if(cw+r>=bestw)
		addliveNode(cw, i + 1, node, false);


		 node = que.front();
		que.pop();
		cw = node->weight;
		i = node->level;
	}

	

	cout << bestw << endl;
	int bestx[n]{ 0 };
	for (int j = n - 1; j >= 0; --j)
	{
		bestx[j] = bestnode->isLeft ? 1 : 0;
		bestnode = bestnode->parent;
	}
	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << endl;
}