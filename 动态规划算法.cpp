#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//选择硬币问题：1，3，5面值的硬币，选出总和11，硬币最少几个

//分治算法解决
//int getNum(int k)
//{
//	if (k == 1 || k == 3 || k == 5)
//	{
//		return 1;
//	}
//	else if (k == 2 || k == 4)
//	{
//		return 2;
//	}
//	else
//	{
//		int n1= getNum(k - 1) + 1;
//		int n2= getNum(k - 3) + 1;
//		int n3= getNum(k - 5) + 1;
//		return min({ n1,n2,n3 });
//	}
//}
//
//int main()
//{
//	int k = 11;
//	vector<int>vec{1,3,5};
//	
//	int result = getNum(k);
//	cout << result << endl;
//	return 0;
//}

//动态规划算法解决

//const int k = 11;
//int dp[k+1]{ 0 };
//int cnt = 0;
//
//int getNum(int k)
//{
//	if (dp[k] > 0)
//	{
//		cnt++;
//		return dp[k];
//	}
//	if (k == 1 || k == 3 || k == 5)
//	{
//		dp[k] = 1;
//		return 1;
//	}
//	else if (k == 2 || k == 4)
//	{
//		dp[k] = 2;
//		return 2;
//	}
//	else
//	{
//		int n1 = getNum(k - 1) + 1;
//		int n2 = getNum(k - 3) + 1;
//		int n3 = getNum(k - 5) + 1;
//		dp[k]= min({ n1,n2,n3 });
//		return dp[k];
//	}
//}
//
//int main()
//{
//	
//
//	int result = getNum(k);
//	cout << result << endl;
//	cout << cnt << endl;
//
//	return 0;
//}


//动态规划算法解决:非递归实现
//状态转移方程：dp[i]=1+dp[i-vj]



//int main()
//{
//	const int k = 11;
//	int dp[k + 1]{ 0 };
//	int cnt = 0;
//	int arr[3]{ 1,3,5 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	for (size_t i = 0; i <= k; i++)
//	{
//		dp[i] = i;
//		for (size_t j = 0; j <length; j++)
//		{
//			if (i >= arr[j] && (dp[i - arr[j]] + 1) < dp[i])
//			{
//				dp[i] = dp[i - arr[j]] + 1;
//			}
//		}
//	}
//	cout << dp[11] << endl;
//	
//
//	return 0;
//}


//分治算法解决斐波那契数列

//int getResult(int k)
//{
//	
//	if (k == 2)
//	{
//		
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return 1;
//	}
//
//  return getResult(k - 1) + getResult(k - 2);
//
//}
//
//int main()
//{
//	const int k = 5;
//	
//
//	int result = getResult(k);
//	cout << result << endl;
//	return 0;
//}


//动态规划算法解决斐波那契数列问题
//const int k = 5;
//int dp[k + 1]{ 0 };
//
//int getResult(int k)
//{
//	if (dp[k] > 0)
//	{
//		return dp[k];
//	}
//	if (k == 2)
//	{
//		dp[k] = 1;
//		return 1;
//	}
//	else if (k == 1)
//	{
//		dp[k] = 1;
//		return 1;
//	}
//
//	dp[k] = getResult(k - 1)+  getResult(k - 2);;
//
//	return dp[k];
//}
//
//int main()
//{
//
//	int result = getResult(k);
//	cout << result << endl;
//	return 0;
//}


//非递归实现动态规划算法解决斐波那契数列问题
//int main()
//{
//	const int k = 5;
//
//	int dp[k + 1]{ 0 };
//	dp[1] = 1;
//	dp[2] = 1;
//	for (size_t i = 3; i <= 5; i++)
//	{
//		dp[i] = dp[i - 1] + dp[i - 2];
//	}
//
//	int result = dp[k];
//	cout << result << endl;
//	return 0;
//}


//求最大子段和:分治算法
//int n = 0;
//int sum = 0;
//int getResult(vector<int>vec,int i,int j)
//{
//	if (i>j)
//	{
//		return max({ 0,n });
//	}
//	else
//	{
//		sum = n;
//		n = 0;
//		for (size_t m = i; m <= j; m++)
//		{
//			n+= vec[m];
//		}
//		n = max(sum, n);
//		sum = 0;
//	}
//	int n1 = getResult(vec, i+1,j);
//	int n2 = getResult(vec, i, j--);
//	return max(n1, n2);
//}
//
//int main()
//{
//
//	vector<int>vec{ -2,11,-4,13,-5,-2 };
//	int result = getResult(vec,0,vec.size()-1);
//	cout << result << endl;
//	
//	
//}
