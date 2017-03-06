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



void _mergeSort(vector<int>& v, int* temp, int left, int right)
{
	assert(v.size() > 0);
	if (left >= right)
		return;
	int mid = left + ((right - left) >> 1);
	_mergeSort(v, temp, left, mid);
	_mergeSort(v, temp, mid + 1, right);
	//merge [left,mid] and [mid+1,right]
	int beg1 = left;
	int beg2 = mid + 1;
	int index = left;
	while (beg1 <= mid && beg2 <= right)
	{
		if (v[beg1] < v[beg2])
			temp[index++] = v[beg1++];
		else
			temp[index++] = v[beg2++];
	}
	while (beg1 <= mid)
	{
		temp[index++] = v[beg1++];
	}
	while (beg2 <= right)
	{
		temp[index++] = v[beg2++];
	}
	//write back
	int i = left;
	while (i <= right)
	{
		v[i] = temp[i];
		++i;
	}
}

void MergeSort(vector<int>& v)
{
	int left = 0; 
	int right = (int)v.size() - 1;
	int* temp = new int[v.size()];
	_mergeSort(v, temp, left, right);
	delete[] temp;
	temp = nullptr;
}


void TestMergeSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	MergeSort(v);
	PrintVector(v);
}

int main()
{
	TestMergeSort();
	return 0;
 } 
