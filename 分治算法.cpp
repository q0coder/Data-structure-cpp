#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;

//分治算法：二分搜索
//bool binarySearch(vector<int>vec, int i, int j, int val)
//{
//	int mid = (i + j) / 2;
//	if (i > j)
//	{
//		return false;
//	}
//	if (vec[mid]==val)
//	{
//		return true;
//	}
//	else if (val < vec[mid])
//	{
//		return binarySearch(vec, 0, mid - 1, val);
//	}
//	else
//	{
//		return binarySearch(vec, mid + 1, vec.size() - 1, val);
//	}
//	
//}
//
//int main()
//{
//	vector<int>vec;
//	int val=4;
//	for (size_t i = 0; i <= 10; i++)
//	{
//		vec.push_back(rand() % 10);
//	}
//	sort(vec.begin(), vec.end());
//	bool result=binarySearch(vec, 0, vec.size() - 1, val);
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << result << endl;
//}


//分治算法：快速排序
//int partation(vector<int>& vec, int i, int j)
//{
//	int val = vec[i];
//	while (i < j)
//	{
//		while (vec[j] > val&&i<j)
//		{
//			j--;
//		}
//		if (i<j)
//		{
//			vec[i] = vec[j];
//			i++;
//		}
//		while (vec[i] < val && i < j)
//		{
//			i++;
//		}
//		if (i<j)
//		{
//			vec[j] = vec[i];
//			j--;
//		}
//		
//
//	}
//	vec[i] = val;
//	return i;
//}
//
//void quickSort(vector<int>&vec, int i, int j)
//{
//	if (i >= j)
//	{
//		return;
//	}
//	int pos = partation(vec, i, j);
//	quickSort(vec, i, pos - 1);
//	quickSort(vec, pos+1, j);
//}
//
//int main()
//{
//	vector<int>vec;
//	for (size_t i = 0; i < 11; i++)
//	{
//		vec.push_back(rand()%100);
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	quickSort(vec, 0, vec.size() - 1);
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}

//分治算法：快排分割求TopK问题
//int partation(vector<int>& vec, int i, int j)
//{
//	int val = vec[i];
//	while (i < j)
//	{
//		while (vec[j] > val && i < j)
//		{
//			j--;
//		}
//		if (i < j)
//		{
//			vec[i] = vec[j];
//			i++;
//		}
//		while (vec[i] < val && i < j)
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			vec[j] = vec[i];
//			j--;
//		}
//
//
//	}
//	vec[i] = val;
//	return i;
//}
//
//int selectTopK(vector<int>vec,int i,int j,int k)
//{
//	int pos=partation(vec, i, j);
//	if (pos == vec.size()-k)
//	{
//		return vec[pos];
//	}
//	else if (pos < vec.size()-k)
//	{
//		return selectTopK(vec, pos + 1, j, k);
//	}
//	else
//	{
//		return selectTopK(vec, i, pos - 1, k);
//	}
//}
//
//
//int main()
//{
//	vector<int>vec;
//	for (size_t i = 0; i < 21; i++)
//	{
//		vec.push_back(rand() % 100);
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	int k = 10;
//	int result=selectTopK(vec, 0, vec.size() - 1, k);
//	cout << result << endl;
//	return 0;
//}

//分治算法：归并排序

//void merge(vector<int>&vec, int i, int j,int mid)
//{
//	vector<int>temp;
//	temp.reserve(j - i + 1);
//	int r = mid + 1;
//	int l = i;
//	while (l<=mid&&r<=j)
//	{
//		if (vec[l] < vec[r])
//		{
//			temp.push_back(vec[l]);
//			l++;
//		}
//		else
//		{
//			temp.push_back(vec[r]);
//			r++;
//		}
//	}
//	
//	while (l <= mid)
//	{
//		temp.push_back(vec[l++]);
//	}
//	while (r <= j)
//	{
//		temp.push_back(vec[r++]);
//	}
//	for (size_t k = i; k <= j; k++)
//	{
//		vec[k] = temp[k - i];
//	}
//}
//
//void mergeSort(vector<int>&vec, int i, int j)
//{
//	if (i >= j)
//	{
//		return;
//	}
//	int mid = (i + j) / 2;
//	mergeSort(vec, i, mid);
//	mergeSort(vec, mid + 1, j);
//
//	merge(vec, i, j,mid);
//}
//
//int main()
//{
//	vector<int>vec;
//	for (size_t i = 0; i < 11; i++)
//	{
//		vec.push_back(rand() % 100);
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	mergeSort(vec, 0, vec.size() - 1);
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	return 0;
//}


//分治算法：合并n个有序单链表



//
//struct ListNode
//{
//	ListNode* next;
//	int m_data;
//	ListNode(int data)
//		:m_data(data)
//		, next(nullptr)
//	{
//	}
//};
//
//ListNode* init_link(initializer_list<int>list)
//{
//	ListNode* head = nullptr;
//	ListNode* p = nullptr;
//	for (int v : list)
//	{
//		if (head == nullptr)
//		{
//			head = new ListNode(v);
//			p = head;
//		}
//		else
//		{
//			p->next = new ListNode(v);
//			p = p->next;
//		}
//	}
//	return head;
//}
//
//ListNode* mergeTwolink(ListNode*& left, ListNode*& right)
//{
//
//	ListNode* p1 = left;
//	ListNode* p2 = right;
//	ListNode* result = nullptr;
//
//	if (p1->m_data <= p2->m_data)
//	{
//		result = p1;
//		p1 = p1->next;
//	}
//	else
//	{
//		result = p2;
//		p2 = p2->next;
//
//	}
//	ListNode* last = result;
//	
//	while (p1 != nullptr && p2 != nullptr)
//	{
//		if (p1->m_data <= p2->m_data)
//		{
//			last->next = p1;
//			last = last->next;
//			p1 = p1->next;
//
//
//		}
//		else
//		{
//			last->next = p2;
//			last = last->next;
//			p2 = p2->next;
//		}
//
//
//	}
//	if (p1 != nullptr)
//	{
//		last->next = p1;
//	}
//	else
//	{
//		last->next = p2;
//	}
//	return result;
//
//
//}
//
//ListNode* merge(vector<ListNode*> vec, int i, int j)
//{
//	if (i >= j)
//	{
//		return vec[i];
//	}
//	int mid = (i + j) / 2;
//	ListNode* left = merge(vec, i, mid);
//	ListNode* right = merge(vec, mid + 1, j);
//
//	return mergeTwolink(left, right);
//
//}
//
//
//
//int main()
//{
//
//	ListNode* p1 = init_link({ 3,2,5,7 });
//	ListNode* p2 = init_link({ 1,2,4,6,8 });
//
//	vector<ListNode*>vec;
//	vec.push_back(p1);
//	vec.push_back(p2);
//	ListNode* p = merge(vec, 0, vec.size() - 1);
//	while (p != nullptr)
//	{
//		cout << p->m_data << " ";
//		p = p->next;
//	}
//	cout << endl;
//	return 0;
//}


//对数时间求两个有序数组的中位数




double middleValue(vector<int>vec1, vector<int>vec2)
{
	if (vec1.size() > vec2.size())
	{
		return middleValue(vec2, vec1);
	}
	int k = (vec1.size() + vec2.size()+1)/2;
	int begin = 0;
	int i = 0;
	int j = 0;
	int end = vec1.size();
	while (begin <= end)
	{
		 i = (begin + end) / 2;

		 j = k - i;
		if (i > 0 && j<vec2.size() && vec1[i - 1]>vec2[j])
		{
			end=i-1;
		}
		if (j > 0 && i<vec1.size() && vec2[j - 1]>vec1[i])
		{
			begin = i + 1;
		}
		else
		{
			break;
		}
	}
	


	int left = max(vec1[i-1], vec2[j-1]);
	if (i == 0)
	{
		left = vec2[j-1];
	}
	else if (j == 0)
	{
		left = vec1[i - 1];
	}
	int right = min(vec1[i], vec2[j]);
	if (i = vec1.size())
	{
		right = vec2[j];
	}
	else if (i = vec2.size())
	{
		right = vec1[i];
	}

	if (((vec1.size() + vec2.size()) & 1) == 0)
	{
		return (left+right) / 2.0;
	}
	else
	{
		return left;
	}
}

int main()
{
	vector<int>vec1{7,68,44,39};
	vector<int>vec2{23,56,12,85,91};
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	double result=middleValue(vec1, vec2);
	cout << result << endl;

	return 0;
}