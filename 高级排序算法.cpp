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

	QuickSort(arr, size);
	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	

}