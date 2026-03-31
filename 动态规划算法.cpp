#include<iostream>
#include<vector>
#include<string>
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


//动态规划算法：最大字段和问题
//int main()
//{
//	int arr[]{ -2,11,-4,13,-5,-2 };
//
//	const int i = sizeof(arr) / sizeof(arr[0]);
//	int dp[i+1]{0};
//	int MAX = dp[0];
//	for (size_t j = 1; j <=i ; j++)
//	{
//		dp[j] = arr[j-1] + dp[j - 1];
//		if (dp[j] < 0)
//		{
//			dp[j] = 0;
//		}
//		else if (dp[j] > MAX)
//		{
//			MAX = dp[j];
//		}
//		
//	}
//	cout << MAX << endl;
//}

//LIS问题：动态规划求序列最长的非降子序列
//int main()
//{
//	int arr[]{ 5,3,4,1,8,7,9,10 };
//	const int length = sizeof(arr) / sizeof(arr[0]);
//	int dp[length + 1]{0};
//	
//	int MAX = dp[0];
//	for (size_t i = 1; i <= length; i++)
//	{
//		dp[i] = 1;
//		for (size_t j = 1; j <= i-1; j++)
//		{
//			if(dp[j]+1>dp[i] && arr[j-1] <= arr[i])
//			dp[i] = 1 + dp[j];
//		}
//		
//		if (MAX < dp[i])
//		{
//			MAX = dp[i];
//		}
//	}
//	cout << MAX << endl;
//}

//LCS问题：求两个序列的最长公共子序列(字符在两个原字符串中的相对顺序保持不变)
//分治算法

//int getLCS(string str1, int i, string str2, int j)
//{
//	if (i < 0 || j < 0)
//	{
//		return 0;
//	}
//	if (str1[i] == str2[j])
//	{
//		return getLCS(str1, i - 1, str2, j - 1)+1;
//	}
//	
//	else
//	{
//		int n1 = getLCS(str1, i - 1, str2, j);
//
//		int n2 = getLCS(str1, i, str2, j-1);
//		return max(n1, n2);
//	}
//}
//
//int main()
//{
//	string str1 = "helloworld";
//	string str2 = "hlweord";
//	int result = getLCS(str1, str1.size() - 1, str2, str2.size() - 1);
//	cout << result << endl;
//	return 0;
//}

//动态规划算法
//string str1 = "helloworld";
//string str2 = "hlweord";
// int l1 = str1.size();
// int l2 = str2.size();
//int** dp = nullptr;
//int** path = nullptr;
//
//int cnt = 0;
//
//int getLCS(string str1, int i, string str2, int j)
//{
//	
//	if (i < 0 || j < 0)
//	{
//		return 0;
//	}
//	if (dp[i][j] >= 0)
//	{
//		return dp[i][j];
//	}
//	 if (str1[i] == str2[j])
//	{
//
//		dp[i][j] = getLCS(str1, i - 1, str2, j - 1) + 1;
//		path[i][j] = 1;
//	
//		return dp[i][j];
//	}
//
//	else
//	{
//		int n1 = getLCS(str1, i - 1, str2, j);
//		
//
//		int n2 = getLCS(str1, i, str2, j - 1);
//		if (n1 >= n2)
//		{
//			path[i][j] = 2;
//			dp[i][j] = n1;
//		}
//		else
//		{
//			path[i][j] = 3;
//			dp[i][j] = n2;
//		}
//		return dp[i][j];
//	}
//}
//
//void printStr(string str1, int i, int j)
//{
//	if (i < 0 || j < 0)
//	{
//		return;
//	}
//	if (path[i][j] == 1)
//	{
//
//		printStr(str1, i - 1, j - 1);
//		cout << str1[i];
//
//	}
//	else if (path[i][j] == 2)
//	{
//		printStr(str1, i - 1, j);
//	}
//	else if (path[i][j] == 3)
//	{
//		printStr(str1, i, j - 1);
//	}
//}
//
//int main()
//{
//    dp = new int* [l1];
//    for (size_t i = 0; i < l1; i++)
//    {
//        dp[i] = new int[l2];
//        for (size_t j = 0; j < l2; j++)
//        {
//            dp[i][j] = -1;
//        }
//    }
//	path = new int* [l1];
//	for (size_t i = 0; i < l1; i++)
//	{
//		path[i] = new int[l2]();
//	
//	}
//    int result = getLCS(str1, l1 - 1, str2, l2 - 1);
//	cout << result << endl;
//	/*for (size_t i = 0; i < l1; i++)
//	{
//		for (size_t j = 0;  j< l2; j++)
//		{
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;*/
//	printStr(str1, l1 - 1, l2 - 1);
//    // 释放内存，防止内存泄漏
//    for (size_t i = 0; i < l1; i++)
//    {
//        delete[] dp[i];
//    }
//    delete[] dp;
//
//    return 0;
//
//}
//
////LCS问题：求两个序列的最长公共子序列(字符在两个原字符串中的相对顺序保持不变)
//非递归实现

//string str1 = "helloworld";
//string str2 = "hlweord";
//int l1 = str1.size();
//int l2 = str2.size();
//int** dp = nullptr;
//
//int LCS(string str1, int i, string str2, int j)
//{
//	for (size_t n = 1; n <= i + 1; n++)
//	{
//		for (size_t m = 1; m <= j + 1; m++)
//		{
//			if (str1[n - 1] == str2[m - 1])
//			{
//				dp[n][m] = 1 + dp[n - 1][m - 1];
//			}
//			else
//			{
//				int len1 = dp[n - 1][m];
//				int len2 = dp[n][m - 1];
//				dp[n][m] = max(len1, len2);
//
//			}
//		}
//	}
//	return dp[i + 1][j + 1];
//}
//
//int main()
//{
//	dp = new int* [l1+1];
//	for (size_t i = 0; i < l1+1; i++)
//	{
//		dp[i] = new int[l2+1];
//		for (size_t j = 0; j < l2+1; j++)
//		{
//			dp[i][j] = 0;
//		}
//	}
//	cout << LCS(str1, l1 - 1, str2, l2 - 1) << endl;
//	
//
//}