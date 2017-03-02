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




//三数取中法
int FindMidIndex(vector<int>& v, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (v[left] > v[mid])
	{
		if (v[mid] > v[right]) //left > mid > right
		{
			return mid;
		}
		else //left > mid  mid <right
		{
			if (v[left] > v[right])
				return right;
			else
				return left;
		}
	}
	else //mid > left
	{
		if (v[left] > v[right]) //mid > left > right
		{
			return left;
		}
		else //mid > left  left < right
		{
			if (v[mid] > v[right])
				return right;
			else
				return mid;
		}
	}
}

//左右指针法--交换
int Partition1(vector<int>& v, int left, int right)
{
	int midIndex = FindMidIndex(v, left, right);
	swap(v[midIndex], v[right]);
	int key = right;
	while (left < right)
	{
		while (left < right && v[left] <= v[key])
		{
			++left;
		}
		while (left < right && v[right] >= v[key])
		{
			--right;
		}
		swap(v[left], v[right]);
	}
	swap(v[key], v[left]);
	return left;
}

//挖坑法
int Partition2(vector<int>& v, int left, int right)
{
	int pivot = v[right];
	while (left < right)
	{
		while (left < right && v[left] <= pivot)
		{
			++left;
		}
		v[right] = v[left];
		while (left < right && v[right] >= pivot)
		{
			--right;
		}
		v[left] = v[right];
	}
	v[left] = pivot;
	return left;
}

//前后指针法
int Partition3(vector<int>& v, int left, int right)
{
	int midIndex = FindMidIndex(v, left, right);
	swap(v[midIndex], v[right]);

	int prev = left - 1;
	int cur = left;
	int temp = v[right];
	while (cur < right)
	{
		if (v[cur] < temp && ++prev != cur)
		{
			swap(v[cur], v[prev]);
		}
		++cur;
	}
	swap(v[cur], v[++prev]);
	return prev;
}


void QuickSort(vector<int>& v, int left, int right)
{
	assert(v.size() > 0);
	if (left >= right)
	{
		return;
	}
	//int div = Partition1(v, left, right);
	int div = Partition3(v, left, right);
	QuickSort(v, left, div - 1);
	QuickSort(v, div + 1, right);
}

void QuickSortNonRecursion(vector<int>& v, int left, int right)
{
	stack<int> s;
	if (left >= right)
	{
		return;
	}
	s.push(right);
	s.push(left);
	while (!s.empty())
	{
		int low = s.top();
		s.pop();
		int high = s.top();
		s.pop();
		int div = Partition2(v, low, high);
		if (low < div - 1)
		{
			s.push(div - 1);
			s.push(low);
		}
		if (high > div + 1)
		{
			s.push(high);
			s.push(div + 1);
		}
	}
}

void TestQuickSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	PrintVector(v);
	QuickSort(v, 0, sz - 1);
	//QuickSortNonRecursion(v, 0, sz - 1);
	PrintVector(v);
}

int main()
{
	TestQuickSort();
	return 0; 
} 
