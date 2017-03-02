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

void DownReheapify(vector<int>& v, int n, int i)
{
	int parent = i;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && v[child + 1] > v[child])
		{
			++child;
		}
		//child is the biggest among the left child and right child
		if (v[child] > v[parent])
		{
			swap(v[child], v[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(vector<int>& v)
{
	assert(v.size() > 0);
	//sort the data in ascending order so we build the great heap
	int n = v.size();
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		DownReheapify(v, n, i);
	}
	//sort
	while (n > 1)
	{
		swap(v[n - 1], v[0]);
		DownReheapify(v, --n, 0);
	}
}


void TestHeapSort()
{
	int a[] = { 9, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	PrintVector(v);
	HeapSort(v);
	PrintVector(v);
}

int main()
{
	TestHeapSort();
	return 0;
}

