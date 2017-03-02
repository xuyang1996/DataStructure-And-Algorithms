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


void BubbleSort(vector<int>& v)
{
	assert(v.size() > 0);
	const int n = (int)v.size();
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n - 1 - j; ++i)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
			}
		}
	}
}

void BubbleSortOptimization(vector<int>& v)
{
	assert(v.size() > 0);
	const int n = (int)v.size();
	for (int j = 0; j < n; ++j)
	{
		bool flag = true;
		for (int i = 0; i < n - 1 - j; ++i)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				flag = false;
			}
		}
		if (flag == true)
			break;
	}
}

void TestBubbleSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	BubbleSort(v);
	PrintVector(v);
}

void TestBubbleSortOptimization()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	BubbleSortOptimization(v);
	PrintVector(v);
}


int main()
{
	TestBubbleSort();
	TestBubbleSortOptimization();
	return 0;
} 
