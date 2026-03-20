//#include<iostream>
//#include<unordered_set>
//#include<time.h>
//#include<vector>
//#include<memory>
//using namespace std;


//int main()
//{
//	vector<int>vec{ 12, 12,78,90,123,8,8,9,9 };
//	int max = vec[0];
//	for (size_t i = 1; i < vec.size(); i++)
//	{
//		if (vec.at(i) > max) {
//			max = vec.at(i);
//		}
//	}
//
//	int* bitmap = new int[max / 32 + 1]();
//	unique_ptr<int[]> ptr(bitmap);
//
//	//找第一个重复出现的数字(或找所有重复出现的数字)
//	/*for (auto key : vec)
//	{
//		int index = key / 32;
//		int offset = key % 32;
//		if ((bitmap[index]&(1<<offset))==0)
//		{
//			bitmap[index] = bitmap[index] | (1 << offset);
//		}
//		else
//		{
//			cout << key << endl;
//		}
//	}*/
//
//	//找第一个不重复出现的数字
//}