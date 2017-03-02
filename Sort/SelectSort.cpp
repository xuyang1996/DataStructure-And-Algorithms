#include <iostream>
#include <vector>
#include <assert.h>
#include <stack>
using namespace std;

//sort the data in an ascending order
void PrintVector(const vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
}

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void SelectSort(vector<int>& v)
{
	assert(v.size() > 0);
	const int n = (int)v.size();
	for (int i = 0; i < n; ++i)
	{
		int minIndex = i;
		for (int j = minIndex + 1; j < n; ++j)
		{
			if (v[j] < v[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			swap(v[minIndex], v[i]);
		}
	}
}

void SelectSortOptimization(vector<int>& v)
{
	assert(v.size() > 0);
	const int n = (int)v.size();
	int left = 0;
	int right = n - 1;
	for (; left < right; ++left, --right)
	{
		int minIndex = left;
		int maxIndex = right;
		for (int j = left; j <= right; ++j)
		{
			if (v[j] < v[minIndex])
			{
				minIndex = j;
			}
			if (v[j] > v[maxIndex])
			{
				maxIndex = j;
			}
		}
		swap(v[minIndex], v[left]);
		if (maxIndex == left)
		{
			maxIndex = minIndex;
		}
		swap(v[maxIndex], v[right]);
	}
}

void TestSelectSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	SelectSort(v);
	PrintVector(v);
}

void TestSelectSortOptimization()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	//PrintVector(v);
	SelectSortOptimization(v);
	PrintVector(v);
}

int main()
{
	TestSelectSort();
	TestSelectSortOptimization();
	return 0;
}
