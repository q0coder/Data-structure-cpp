#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//硬币选择问题
//int main()
//{
//	vector<int>vec{ 1,3,5 };
//	int cnt = 0;
//	int c = 18;
//	for (size_t i =vec.size()-1 ; i >=0;)
//	{
//		if (c == 0)
//		{
//			break;
//		}
//		if (vec[i] <= c) {
//			c -= vec[i];
//			cnt++;
//		}
//		else
//		{
//			i--;
//		}
//	}
//	cout << cnt << endl;
//}

//部分背包问题
//int main()
//{
//	vector<double>w{ 8,6,4,2,5 };
//	vector<double> v{ 6,4,7,8,6 };
//	vector<double>vec;
//	double val = 0;
//	double c = 12;
//	for (size_t i = 0; i < w.size(); i++)
//	{
//		vec.push_back(v[i] / w[i]);
//	}
//	vector<int>index;
//	index.resize(w.size());
//	for (size_t i = 0; i < w.size(); i++)
//	{
//		index[i] = i;
//	}
//	sort(index.begin(), index.end(), [vec](int a, int b)->bool {return vec[a] > vec[b]; });
//	vector<double>w1(w.size());
//	vector<double>v1(w.size());
//
//	for (size_t i = 0; i < w.size(); i++)
//	{
//		w1[i] = w[index[i]];
//		v1[i] = v[index[i]];
//
//	}
//	sort(vec.begin(), vec.end(), [](int a, int b)->bool {return a>b; });
//	/*for (auto v : w1)
//	{
//		cout << v << endl;
//	}*/
//	
//	for (size_t i = 0; i <w.size() ; i++)
//	{
//		if (c > w1[i])
//		{
//			val += v1[i];
//			c -= w1[i];
//		}
//		else if(c>0)
//		{
//			val+= vec[i]*c;
//			c = 0;
//		}
//		else if(c==0)
//		{
//			break;
//		}
//	}
//	cout << val << endl;
//	
//	cout << endl;
//
//
//
//
//}


//柜台提供服务问题
//vector<int>m{ 1,2,3,4,5 };
//vector<int> t{ 6,2,7,8,6 };
//class Table
//{
//	public:
//		int m_;
//		int t_;
//};
//
//int main()
//{
//	
//	vector<Table>vec(m.size());
//	int r = 7;
//	int x[5]{ 0 };
//	for (size_t i = 0; i < m.size(); i++)
//	{
//		vec[i].m_ = m[i];
//		vec[i].t_ = t[i];
//	}
//	sort(vec.begin(), vec.end(), [](Table a, Table b)->bool {return a.t_ < b.t_; });
//	/*for (auto v : vec)
//	{
//		cout << v.m_ << endl;
//	}*/
//	int mintue = 0;
//	for (size_t i = 0; i < r; i++)
//	{
//		int time = vec[0].t_ * (x[0] + 1);
//		int j = 1;
//		for (; j < m.size(); j++)
//		{
//			int T = vec[j].t_*(x[j]+1);
//			if (T < time)
//			{
//				x[j]++;
//				if (T > mintue)
//				{
//					mintue = T;
//				}
//				break;
//			}
//				
//
//		}
//		if (j == m.size())
//		{
//			x[0]++;
//			mintue = vec[0].t_ * x[0];
//		}
//	}
//	cout << mintue << endl;
//	for (size_t i = 0; i < m.size(); i++)
//	{
//		cout << vec[i].m_ << ": " << x[i] << " ";
//	}
//	cout << endl;
//
//}

