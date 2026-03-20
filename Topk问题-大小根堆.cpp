//#include<iostream>
//#include<vector>
//#include<queue>
//#include<time.h>
//#include<functional>
//#include<unordered_map>
//using namespace std;

//查找vector中值最小的前五个元素
//int main()
//{
//	srand(time(NULL));
//	vector<int>vec;
//	for (size_t i = 0; i < 1000; i++)
//	{
//		vec.push_back(rand()%1000+100);
//		cout << vec.at(i) << endl;
//	}
//	cout << endl;
//	priority_queue<int> maxheap;
//	int k = 5;
//	for (size_t i = 0; i < k; i++)
//	{
//		maxheap.push(vec[i]);
//	}
//
//	for (size_t i = 5; i < 1000; i++)
//	{
//		if (vec[i] < maxheap.top())
//		{
//			maxheap.pop();
//			maxheap.push(vec[i]);
//		}
//	}
//
//	for (size_t i = 0; i < 5; i++)
//	{
//
//		cout << maxheap.top() << " ";
//		maxheap.pop();
//	}
//
//}
//
//

//查找最大的五个元素

//int main()
//{
//	srand(time(NULL));
//		vector<int>vec;
//		for (size_t i = 0; i < 10; i++)
//		{
//			vec.push_back(rand()%10);
//			cout << vec.at(i) << " ";
//		}
//		cout << endl;
//		priority_queue<int,vector<int>,greater<int>> minheap;
//		int k = 5;
//		for (size_t i = 0; i < k; i++)
//		{
//			minheap.push(vec[i]);
//		}
//		for (size_t i = k; i < vec.size(); i++)
//		{
//			if (minheap.top() < vec[i])
//			{
//				minheap.pop();
//				minheap.push(vec[i]);
//			}
//		}
//		while (!minheap.empty())
//		{
//			cout << minheap.top() << " ";
//			minheap.pop();
//		}
//
//}


////查找重复次数最s少的三个元素
//int main()
//{
//	srand(time(NULL));
//	vector<int>vec;
//	for (size_t i = 0; i < 10000; i++)
//	{
//		vec.push_back(rand() % 1000);
//
//	}
//	unordered_map<int, int>un_map;
//	for (auto key : vec)
//	{
//		un_map[key]++;
//	}
//	int k = 3;
//	using Type = pair<int, int>;
//	using Comp = function<bool(Type&, Type)>;
//	priority_queue<Type, vector<Type>, Comp>maxheap([](Type& a, Type b)->bool {return a.second < b.second; });
//	auto it = un_map.begin();
//	for (int i = 0; i < k; i++, ++it)
//	{
//		maxheap.push(*it);
//	}
//	for (int i = k; i < un_map.size(); i++, ++it)
//	{
//		if (maxheap.top().second > it->second)
//		{
//			maxheap.pop();
//			maxheap.push(*it);
//		}
//	}
//	while (!maxheap.empty())
//	{
//		cout << maxheap.top().first << " ：" << maxheap.top().second << " " << endl;;
//		maxheap.pop();
//	}
//}

//查找重复次数最多的三个元素
//int main()
//{
//	srand(time(NULL));
//	vector<int>vec;
//	for (size_t i = 0; i < 10000; i++)
//	{
//		vec.push_back(rand() % 1000);
//
//	}
//	unordered_map<int, int>un_map;
//	for (auto key : vec)
//	{
//		un_map[key]++;
//	}
//	int k = 3;
//	using Type = pair<int, int>;
//	using Comp = function<bool(Type&, Type)>;
//	priority_queue<Type, vector<Type>, Comp>minheap([](Type& a, Type b)->bool {return a.second > b.second; });
//	auto it = un_map.begin();
//	for (int i = 0; i < k; i++, ++it)
//	{
//		minheap.push(*it);
//	}
//	for (int i = k; i < un_map.size(); i++, ++it)
//	{
//		if (minheap.top().second < it->second)
//		{
//			minheap.pop();
//			minheap.push(*it);
//		}
//	}
//	while (!minheap.empty())
//	{
//		cout << minheap.top().first << " ：" << minheap.top().second << " " << endl;;
//		minheap.pop();
//	}
//
//}