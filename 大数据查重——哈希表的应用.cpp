//#include<iostream>
//#include<time.h>
//#include<unordered_set>//底层为哈希表
//#include<unordered_map>
//#include<string>
//#include<list>
//#include<vector>
//using namespace std;

//int main()
//{
//	srand(time(NULL));
//	vector<int>vec;
//	unordered_set<int>un_set;
//	unordered_set<int>un_set1;
//
//	for (size_t i = 0; i < 10000; i++)
//	{
//		vec.push_back(rand()%10000);
//	}
//
//	//查找第一个重复的数字（）
//	/*for (auto key : vec)
//	{
//		auto it = un_set.find(key);
//		if (it == un_set.end())
//		{
//			un_set.insert(key);
//		}
//		else
//		{
//			cout << key << endl;
//			break;
//		}
//	}*/
//
//	//查找全部重复的数字
//	/*for (auto key : vec)
//	{
//		auto it = un_set.find(key);
//		if (it == un_set.end())
//		{
//			un_set.insert(key);
//		}
//		else if(it!=un_set.end()&&un_set1.find(key)==un_set1.end())
//		{
//			un_set1.insert(key);
//			cout << key << endl;
//			
//		}
//	}*/
//
//	//统计重复出现的数字及其重复次数
//	/*unordered_map<int,int>un_map;
//	for (auto key : vec)
//	{
//		auto it = un_map.find(key);
//		if (it == un_map.end())
//		{
//			un_map.emplace( key,1 );
//		}
//		else
//		{
//			it->second++;
//			
//		}
//	}
//	for (auto pair : un_map)
//	{
//		if (pair.second > 1)
//		{
//			cout << pair.first << " : " << pair.second << endl;
//		}
//		
//	}*/
//
//	//去除重复的数字
//	//unordered_map<int, int>un_map;//unordered_map本身就不允许重复
//	//for (auto key : vec)
//	//{
//	//	un_map.emplace(key);
//	//}
//
//	//找出第一个没有重复出现的字符
//
//	/*string str = "jjdrrsattuuhhdtyy";
//	unordered_map<char, int>un_map;
//	for (char ch : str)
//	{
//		un_map[ch]++;
//	}
//	for (char ch : str)
//	{
//		if (un_map[ch] == 1)
//		{
//			cout << ch << endl;
//			return 0;
//		}
//	}
//	cout << "wu" << endl;
//	return 0;*/
//
//}