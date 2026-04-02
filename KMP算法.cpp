#include<iostream>
#include<vector>
#include<string>
#include<memory>
using namespace std;

int* getNext(string str)
{
	int* next = new int[str.size()];
	int j = 0;
	int k = -1;
	next[j] = k;

	while (j < str.size() - 1)
	{
		if (k==-1||str[k] == str[j])
		{
			j++;
			k++;
			if (str[k] == str[j])
			{
				next[j] = next[k];
			}
			else
			{
				next[j] = k;

			}
		}
		else
		{
			k = next[k];
		}
	}
	return next;
}

int KMP(string s, string t)
{

	int j = 0;
	int i = 0;

	int* next = getNext(t);
	unique_ptr<int[]>ptr(next);

	int size1 = s.length();
	int size2 = t.length();
	while ( i < size1 && j <size2)
	{
		if (j == -1||s[i] == t[j])   {
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}


	if (j == t.length())
	{
		return i - j;
	}
	else
	{
		return -1;
	}

}

int main()
{
	string s = "ABCDCABDEFG";
	string t = "ABD";
	cout << KMP(s, t) << endl;
	return 0;
}
