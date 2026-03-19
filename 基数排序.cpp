//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdlib.h>
//#include<time.h>
//using namespace std;
//
////»ùÊýÅÅÐò
//void RadixSort(int arr[], int size)
//{
//	int maxData = arr[0];
//	for (size_t i = 1; i < size; i++)
//	{
//		if (maxData<abs(arr[i]))
//		{
//			maxData = abs(arr[i]);
//		}
//	}
//	int len = to_string(maxData).size();
//	vector<vector<int>>vecs;
//	int mod = 10;
//	int dev = 1;
//	for (size_t i = 0; i < len; mod*=10,dev*=10,i++)
//	{
//		vecs.resize(20);
//		for (size_t j = 0; j < size; j++)
//		{
//			int index = arr[j] % mod / dev+10;
//			
//			vecs[index].push_back(arr[j]);
//		}
//		int idx = 0;
//		for (auto vec : vecs)
//		{
//			for (int v:vec)
//			{
//				arr[idx++] = v;
//			}
//		}
//		vecs.clear();
//	}
//}
//
//int main()
//{
//	srand(time(NULL));
//	int arr[10];
//	for (size_t i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 100-200;
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	RadixSort(arr, size);
//	for (size_t i = 0; i < 10; i++)
//	{
//		
//		cout << arr[i] << " ";
//	}
//}