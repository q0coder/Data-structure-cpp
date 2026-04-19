//#include<iostream>
//using namespace std;
//
//const int SIZE = 9;
//
//class UnionFind
//{
//private:
//	//定义数组
//	int parent[SIZE];
//	int rank[SIZE];
//public:
//	UnionFind()
//	{
//		//初始数组
//		for (int i = 0; i < SIZE; i++)
//		{
//			parent[i] = i;
//			rank[i] = 1;
//		}
//	}
//public:
//	//查询操作
//	//int find(int x)
//	//{
//	//	while (parent[x] != x)//当parent[x]=x时，遍历到根节点
//	//	{
//	//		x = parent[x];
//	//	}
//	//	return x;
//	//}
//	//查询操作--优化find
//	int find(int x)
//	{
//		if (parent[x] == x)
//		{
//			return x;
//		}
//		return parent[x] = find(parent[x]);
//	}
//	//合并操作--加权标记
//	void Union(int x,int y)
//	{
//		int x = find(x);
//		int y = find(y);
//		if (x != y)
//		{
//			if (rank[x] > rank[y])
//			{
//				parent[y] = x;
//			}
//			else
//			{
//				if (rank[x] == rank[y])
//				{
//					rank[y]++;
//
//				}
//				parent[x] = y;
//			}
//		}
//	}
//	//void Union(int x, int y)
//	//{
//	//	int x = find(x);
//	//	int y = find(y);
//	//	if (x != y)//不在同一个集合中才合并
//	//	{
//	//		parent[x] = y;
//	//	}
//
//	//}
//
//};
//
//int main()
//{
//
//}
