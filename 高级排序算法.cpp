#include<iostream>
#include<time.h>
using namespace std;

//快排分割函数
int Partation(int arr[], int L, int R)
{
	int val = arr[L];
	while (L < R)
	{
		while (arr[R]>val&&L<R)
		{
			R--;
		}
		if (L < R)
		{
			arr[L] = arr[R];
			L++;
		}
		while (arr[L] < val && L < R)
		{
			L++;
		}
		if (L < R)
		{
			arr[R] = arr[L];
			R--;
		}
	}
	arr[L] = val;
	return L;
}

//快排函数接口
void QuickSort(int arr[], int L, int R)
{
	if (L >= R)
		return;
	int pos = Partation(arr,  L,  R);
	
	//对分割后的两部分分别进行快排
	QuickSort(arr, L, pos - 1);
	QuickSort(arr, pos+1, R);

}

//快排函数
void QuickSort(int arr[],int size)
{
	return QuickSort(arr,0,size-1);
	
}

//归并过程函数
void Merge(int arr[], int l, int m, int r)
{
	int* p = new int[r - l + 1];
	int idx = 0;
	int i = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
		
	}
	while (i <= m)
	{
		p[idx++] = arr[i++];
	}
	while (j <= r)
	{
		p[idx++] = arr[j++];
	}
	//在不合并好的数据拷贝到原始数组中
	for (size_t i = l,j=0; i <=r ; i++,j++)
	{
		arr[i] = p[j];
	}
	delete[]p;
	p = nullptr;

}

//归并排序
void MergeSort(int arr[], int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//先递归
	MergeSort(arr, begin, mid);
	MergeSort(arr, mid + 1, end);
	//再归并
	Merge(arr, begin, mid, end);
}

//堆排下沉操作
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < size  / 2)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		if (val < arr[child])
		{
			arr[i] = arr[child];
			i = child;
		}
		else
			break;
	}
	arr[i] = val;
}

//堆排序
void HeapSort(int arr[], int size)
{
	int n = size - 1;
	//找到每一个非叶子节点
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}
	for (size_t i = n; i > 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		siftDown(arr, 0,i);
	}
}

int main()
{
	srand(time(NULL));
	int arr[10];
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = rand() %100+1;
		cout << arr[i] << " ";
	}
	cout << endl;
	int size = sizeof(arr) / sizeof(arr[0]);

	//QuickSort(arr, size);
	//MergeSort(arr, 0, size - 1);
	HeapSort(arr, size);
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	

}

