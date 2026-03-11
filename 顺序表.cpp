#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<time.h>
using namespace std;


//顺序表

//class Array
//{
//public:
//	Array(int size = 10) :mCur(0), mCap(size)
//	{
//		mpArr = new int[mCap]();
//	}
//
//	~Array()
//	{
//		if (mpArr != nullptr)
//		{
//			delete[] mpArr;
//			mpArr = nullptr;
//		}
//		
//	}
//public:
//	void push_back(int val)//尾插
//	{
//		if (mCur == mCap)
//		{
//			expand(mCap * 2);
//		}
//		mpArr[mCur++] = val;
//	}
//
//	void pop_back()//尾删
//	{
//		if (mCur == 0)
//		{
//			return;
//		}
//		mCur--;
//	}
//
//	void insert(int pos, int val)//位插
//	{
//		if (pos<0 || pos>mCur)
//		{
//			return;
//		}
//		if (mCur = mCap)
//		{
//			expand(mCap * 2);
//		}
//		for (size_t i = mCur; i > pos; i--)
//		{
//			mpArr[i] = mpArr[i - 1];
//		}
//		mpArr[pos] = val;
//		mCur++;
//	}
//
//	void erase(int pos)//位删
//	{
//		if (pos<0 || pos>mCur)
//		{
//			return;
//		}
//		for (size_t i = mCur-1; i > pos; i--)
//		{
//			mpArr[i-1] = mpArr[i];
//		}
//		mCur--;
//	}
//
//	int find(int val)//查找
//	{
//		for (size_t i = 0; i < mCur; i++)
//		{
//			if (mpArr[i] == val)
//				return i;
//		
//
//		}
//		return -1;
//	}
//public:
//	void show()//打印
//	{
//		for (size_t i = 0; i < mCur; i++)
//		{
//			cout << mpArr[i] <<" ";
//		}
//	}
//private:
//	void expand(int size)//扩容
//	{
//		int* p = new int[size];
//		memcpy(p, mpArr, sizeof(int)*mCap);
//		delete[] mpArr;
//		mpArr = p;
//		mCap = size;
//
//	}
//
//private:
//	int* mpArr;//指向可扩容的地址内存
//	int mCap;//容量
//	int mCur;//元素个数
//
//};
//
//int main()
//{
//	Array arr;
//	srand(time(0));
//	for (size_t i = 0; i < 10; i++)
//	{
//		arr.push_back(rand() % 100);
//
//	}
//	arr.show();
//	cout << endl;
//	arr.insert(2, 11);
//	arr.show();
//	cout << endl;
//	arr.pop_back();
//	arr.show();
//	cout << endl;
//	cout<<arr.find(11)<<endl;
//	arr.erase(2);
//	arr.show();
//
//}



////双指针，数组逆序
//void Reverse(char arr[],int size)
//{
//	char* left = arr;
//	char* right = arr + size - 1;
//	while (left<right)
//	{
//		char temp = *left;
//		*left = *right;
//		*right = temp;
//		left++;
//		right--;
//	}
//
//}
//int main()
//{
//	char arr[] = "HellowWorld";
//	int size = strlen(arr);
//	Reverse(arr, size);
//	for (size_t i = 0; i < size; i++)
//	{
//		cout << arr[i] ;
//	}
//}



////双指针，奇偶数调整
//void Adjust(int arr[],int size)
//{
//	int* left = arr;
//	int* right = arr + size - 1;
//	while (left < right)
//	{
//		while (left < right)
//		{
//			if ((*left & 0x1) == 1)
//			{
//				break;
//				
//
//			}
//			left++;
//		}
//		while (left < right)
//		{
//			if ((*right & 0x1) == 0)
//			{
//				break;
//				
//			}
//			right--;
//		}
//		if (left < right)
//		{
//			int temp = *left;
//			*left = *right;
//			*right = temp;
//			left++;
//			right--;
//		}
//		
//	}
//}
//int main()
//{
//	int arr[10];
//
//	srand(time(0));
//	for (size_t i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 9;
//		
//	}
//	int size = sizeof(arr) / sizeof(arr[0]);
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	Adjust(arr, size);
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << arr[i] << " ";
//	}
//
//}
//

////双指针，移除元素,leetCode
//int removeElement(int* nums, int numsSize, int val) {
//    int count = 0;
//    int* left = nums;
//    int* right = nums + numsSize - 1;
//    while (left < right)
//    {
//        while (left < right)
//        {
//            if (*left == val)
//            {
//                break;
//            }
//            left++;
//        }
//        while (left < right)
//        {
//            if (*left != val)
//            {
//
//                break;
//            }
//            right--;
//        }
//        if (left < right)
//        {
//            int temp = *left;
//            *left = *right;
//            *right = temp;
//            left++;
//            right--;
//
//        }
//        return p - nums;
//    }

//}
