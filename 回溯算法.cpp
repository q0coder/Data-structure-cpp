
#include<iostream>

#include<cmath>
#include<vector>
#include<map>
using namespace std;

//void func(int arr[], int length, int i,int x[])
//{
//	if (length == i)
//	{
//		for (int j = 0; j < length; ++j)
//		{
//			if (x[j] == 1)
//			{
//				cout << arr[j] << " ";
//
//			}
//			
//
//		}
//		cout << endl;
//	}
//	else
//	{
//		x[i] = 1;
//		func(arr, length, i + 1,x);
//		x[i] = 0;
//		func(arr, length, i + 1,x);
//
//	}
//	
//}
//
//
//int main()
//{
//	int arr[]{ 1,2,3 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	int x[3];
//
//	func(arr, length, 0,x);
//}

//整数选择问题
//给定一组整数，从中选择一组整数，使选择的整数和与剩下的整数和的差值最小


//int arr[10]{ 1,2,3,4,5,6,7,8,9,0 };
//int length = sizeof(arr) / sizeof(arr[0]);
//vector<int>x;
//int sum = 0;
//int r = 0;
//vector<int>baseX;
//unsigned int MIN = 0xFFFFFFFF;
//int result = 0;
//
//void getArr(int i)
//{
//	if (i == length)
//	{
//		 result = abs(sum - r);
//		if (result < MIN)
//		{
//			MIN = result;
//			baseX = x;
//		}
//		
//	}
//	else
//	{
//		r -= arr[i];
//		sum += arr[i];
//		x.push_back(arr[i]);
//		getArr(i + 1);
//		sum -= arr[i];
//		r += arr[i];
//
//		x.pop_back();
//		
//		getArr(i + 1);
//	}
//}
//
//int main()
//{
//	for (int val : arr)
//	{
//		r += val;
//	}
//	
//
//	getArr(0);
//	for (int val : baseX)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	cout << MIN << endl;
//
//}

//给定2n整数，从中选择n整数，使选择的整数和与剩下的整数和的差值最小
//int arr[]{ 1,2,3,4,5,6,7,8,9,10 };
//int length = sizeof(arr) / sizeof(arr[0]);
//vector<int>x;
//int sum = 0;
//int r = 0;
//vector<int>baseX;
//unsigned int MIN = 0xFFFFFFFF;
//int result = 0;
//int cnt = 0;
//int Left = length;
//
//void getArr(int i)
//{
//	if (i == length)
//	{
//		++cnt;
//
//		result = abs(sum - r);
//
//		if (MIN > result)
//		{
//			MIN = result;
//			baseX = x;
//		}
//		
//	}
//	else
//	{
//
//		Left--;
//
//		if (x.size() < length / 2)
//		{
//
//			x.push_back(arr[i]);
//			sum += arr[i];
//			r -= arr[i];
//			getArr(i + 1);
//			sum -= arr[i];
//			r += arr[i];
//			x.pop_back();
//		}
//
//		if (Left + x.size() >= length / 2)
//		{
//			getArr(i + 1);
//		}
//
//		Left++;
//		
//	}
//}
//
//int main()
//{
//	for (int val : arr)
//	{
//		r += val;
//	}
//	getArr(0);
//	for (int val : baseX)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//	cout << MIN << endl;
//	cout << cnt << endl;
//}


//挑数子问题
//从一组整数中挑选一组数数字，使其和等于给定值，打印满足条件的解与不满足条件的解
//int arr[]{ 10,14,23,4,45,6,7,8 };
//int val = 14;
//vector<int>x;
//vector<vector<int>>True;
//vector<vector<int>>False;
//vector<int>vec;
//
//int length = sizeof(arr) / sizeof(arr[0]);
//int sum = 0;
//int cnt = 0;
//int r = 0;


//void getNum(int i)
//{
//	if (i == length)
//	{
//		cnt++;
//		if (val == sum)
//		{
//			True.push_back(x);
//
//
//		}
//		else
//		{
//			False.push_back(x);
//		}
//	}
//	else
//	{
//		r -= arr[i];
//
//		if (sum <= val)
//		{
//			x.push_back(arr[i]);
//			sum += arr[i];
//			getNum(i + 1);
//			sum -= arr[i];
//			x.pop_back();
//		}
//		/*x.push_back(arr[i]);
//		sum += arr[i];
//		getNum(i + 1);
//		sum -= arr[i];
//		x.pop_back();*/
//		
//		if (sum + r >= val)
//		{
//			getNum(i + 1);
//
//
//		}
//		r += arr[i];
//
//		//getNum(i + 1);
//
//	}
//
//}
//
//int main()
//{
//	for (int val : arr)
//	{
//		r += val;
//	}
//	getNum(0);
//	for (auto vec : True)
//	{
//		cout << "True:";
//		for (int val : vec)
//		{
//			cout << val << " ";
//		}
//		cout << endl;
//
//	}
//	for (auto vec : False)
//	{
//		cout << "False:";
//		for (int val : vec)
//		{
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//	cout << cnt << endl;
//}


//递归枚举
//void getNum(int i, int val)
//{
//	if (val == 0)
//	{
//		for (int v : vec)
//		{
//			cout << v << " ";
//		}
//		cout << endl;
//	}
//	for (size_t j = i; j < length; j++)
//	{
//		if (val > arr[j])
//		{
//			vec.push_back(arr[j]);
//			getNum(j + 1, val - arr[j]);
//			vec.pop_back();
//		}
//		
//
//	}
//}
//
//int main()
//{
//	getNum(0, val);
//}

//0-1背包问题：
//int w[]{ 12,5,8,9,6 };
//int v[]{ 9,11,4,7,8 };
//int c = 20;
//int length_w = sizeof(w) / sizeof(w[0]);
//int sum_w = 0;
//int sum_v = 0;
//int MAX = 0;
//int r = 0;
//vector<int>x_w;
//vector<int>bestx;
//
//
//
//void maxValue(int i)
//{
//	if (i == length_w)
//	{
//
//		if (MAX < sum_v)
//		{
//			MAX = sum_v;
//			bestx = x_w;
//		}
//
//	}
//	else
//	{
//		r -= v[i];
//		if (sum_w + w[i] <= c)
//		{
//			x_w.push_back(w[i]);
//
//			sum_w += w[i];
//			sum_v += v[i];
//			maxValue(i + 1);
//			sum_w -= w[i];
//			sum_v -= v[i];
//
//			x_w.pop_back();
//
//		}
//
//		if (sum_v + r > MAX)
//		{
//			maxValue(i + 1);
//
//		}
//		r += v[i];
//	}
//
//
//
//}
//
//int main()
//{
//	for (int val : v)
//	{
//		r += val;
//	}
//
//	maxValue(0);
//	for (int val : bestx)
//	{
//		cout << val << " ";
//	}
//	cout << endl;
//
//}


//排列树
//int arr[]{ 1,2,3,4 };
//int length = sizeof(arr) / sizeof(arr[0]);
//
//
//void func(int i)
//{
//	if (i == length)
//	{
//		for (int val : arr)
//		{
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (size_t k = i; k < length; k++)
//		{
//			swap(arr[i], arr[k]);
//			func(i + 1);
//			swap(arr[i], arr[k]);
//		}
//	}
//}
//
//int main()
//{
//	func(0);
//}

//八皇后问题
//int arr[]{ 1,2,3,4,5,6,7,8 };
//int length = 8;
//int cnt = 0;
//
//bool judge(int i)
//{
//	for (int j = 0; j < i; j++)
//	{
//		if (i == j || arr[i] == arr[j] || abs(j - i) == abs(arr[i] - arr[j]))
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
//
//void func(int i)
//{
//	if (i == length)
//	{
//		cnt++;
//		for (int val : arr)
//		{
//			cout << val << " ";
//		}
//		cout << endl;
//
//	}
//	else
//	{
//		for (size_t k = i; k < length; k++)
//		{
//			swap(arr[i], arr[k]);
//
//			if (judge(i) )
//			{
//				func(i + 1);
//
//			}
//			swap(arr[i],arr[k]);
//		}
//	}
//}
//
//
//int main()
//{
//	func(0);
//	cout << cnt << endl;
//	return 0;
//}

//基于穷举法的全排列
//int arr[]{ 1,2,3 };
//int length = 3;
//bool state[3];
//vector<int>x;
//
//void func(int i)
//{
//	if (i == length)
//	{
//		for (int val : x)
//		{
//			cout << val << " ";
//		}
//		cout << endl;
//	}
//	else
//	{
//		for (int k = 0; k < length; k++)
//		{
//			if (!state[k])
//			{
//				state[k] = true;
//				x.push_back(arr[k]);
//				func(i + 1);
//				x.pop_back();
//				state[k] = false;
//
//
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	func(0);
//	return 0;
//}