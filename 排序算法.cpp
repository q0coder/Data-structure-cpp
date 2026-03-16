#include<iostream>
#include<time.h>
using namespace std;


//冒泡排序(多轮比较相邻的两个元素，每轮将最大的数置于数组底)（O（n^2））//稳定
void BubbleSort(int arr[], int size)
{
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1])
			{
				int temp=arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}
	}
}

//选择排序（假定第一个为最小，与后面的比较，找到最小的，交换）(O(n^2),比冒泡排序效率高)//不稳定
void ChoiceSort(int arr[], int size)
{
	
	for (size_t i = 0; i < size-1; i++)
	{
		int min = arr[i];
		int k = i;
		for (size_t j = i+1; j < size ; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				k = j;
			}
		}
		if (k != i)
		{
			int temp = arr[i];
			arr[i] = arr[k];
			arr[k] = temp;
		}
	}
}


//插入排序(假定第一个元素有序，将第二个元素与第一个比较插入）
void InsertSort(int arr[], int size)
{
	for (size_t i = 1; i < size; i++)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] <val)
			{
				break;
			}
			arr[j+1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

int main()
{
	srand(time(NULL));
	int arr[10];
	int size = sizeof(arr) / sizeof(arr[0]);
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << arr[i] << " ";
	}
	cout << endl;
	//BubbleSort(arr, size);
	//ChoiceSort(arr, size);
	InsertSort(arr, size);
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}