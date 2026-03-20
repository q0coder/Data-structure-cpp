#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

int Partaion(vector<int>vec, int begin, int end)
{
	int i = begin;
	int j = end;
	int val = vec[i];
	while (i < j)
	{
		while (i<j && vec[j]>val)
			j--;
		if (i < j)
		{
			vec[i] = vec[j];
			i++;
		}
		while (i < j && vec[i] < val)
			i++;
		if (i < j )
		{
			vec[j] = vec[i];
			j--;
		}
	}
	vec[i] = val;
	return i;
}

void SelectTopk(vector<int>vec,int begin,int end,int k)
{
	int pos = Partaion(vec, begin, end);
	if (pos == k - 1)
	{
		return;
	}
	else if (pos > k - 1)
	{
		SelectTopk(vec, begin, pos - 1,k);
	}
	else
	{
		SelectTopk(vec, pos + 1, end,k);
	}
}
int main()
{
	vector<int>vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back( rand() % 10);
		cout << vec.at(i) << " ";
	}
	cout << endl;
	int k=3;
	SelectTopk(vec, 0, vec.size() - 1,k);
	for (size_t i = 0; i < k; i++)
	{
		cout << vec.at(i) << " ";
	}
}