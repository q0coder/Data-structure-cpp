#include<iostream>
using namespace std;

//int BinarySearch(int arr[], int size, int val)//¶þ·ÖËÑË÷£¨·ÇµÝ¹é£©
//{
//	int left = 0;
//	int right = size - 1;
//	int	middle = (left + right)/2;
//	while (left <= right)
//	{
//		if (val == arr[middle])
//		{
//			return middle;
//		}
//		else if (val < arr[middle])
//		{
//			right = middle - 1;
//			middle = (left + right) / 2;
//		}
//		else
//		{
//			left = middle + 1;
//			middle = (left + right) / 2;
//		}
//	}
//	return -1;
//
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int val = 3;
//	cout << BinarySearch(arr, size, val) << endl;
//
//
//}
//



//int get(int val)
//{
//	if (val == 1||val==0)
//	{
//		return 1;
//	}
//	else
//	{
//		return val * get(val - 1);
//	}
//	
//}
//int main()
//{
//	cout << get(3) << endl;
//}

//¶þ·ÖËÑË÷£¨µÝ¹é£©
//int BinarySearch(int arr[], int val,int i,int j)
//{
//	int mid = (i + j) / 2;
//	if (i > j)
//	{
//		return -1;
//	}
//	else if(val<arr[mid])
//	{
//		return BinarySearch(arr, val, i, mid - 1);
//	}
//	else if (val > arr[mid])
//	{
//		return BinarySearch(arr, val, mid+1, j);
//
//	}
//	else if (val == arr[mid])
//	{
//		return mid;
//	}
//
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int val = 3;
//	cout << BinarySearch(arr, val, 0,size-1) << endl;
//
//}