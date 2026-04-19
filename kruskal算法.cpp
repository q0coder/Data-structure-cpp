#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
	//构建边类
	Edge(int s,int e,int c):
		start(s)
		,end(e)
		,cost(c)
	{ }
	int start;
	int end;
	int cost;


};
const int SIZE = 10;
int parent[SIZE];
int find(int x)
{
	while (x != parent[x])
	{
		x = parent[x];
	}
	return x;
}
int main()
{
	//创建并查集
	
	for (int i = 0; i < SIZE; i++)
	{
		parent[i] = i;
	}
	//添加边数组
	vector<Edge>vec;
	int c;
	char s, e;
	for (int i=0;i<SIZE-1;i++)
	{
		cin >> s >> e >> c;
		vec.emplace_back(s, e, c);
	}
	//按权值升序排序
	sort(vec.begin(), vec.end(), [](auto& a, auto& b)->bool {return a.cost < b.cost; });

	//从小到大选边并和并
	for (int i = 0; i < SIZE - 1; i++)
	{
		int a = find(vec[i].start);
		int b = find(vec[i].end);

		if (a != b)
		{
			parent[a] = b;
		}
	}

}

