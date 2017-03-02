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



void InsertSort(int *a, int n)
{
	assert(a != nullptr && n > 0);
	
	for (int i = 1; i < n; ++i)
	{
		int endPos = i - 1;
		int temp = a[i];
		while (endPos >= 0)
		{	
			if (temp > a[endPos])
			{
				break;
			}
			else
			{
				a[endPos + 1] = a[endPos];
				--endPos;
			}
		}
		a[endPos + 1] = temp;
	}
}

void TestInsertSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsertSort(a, sz);
	PrintArray(a, sz);
}

int main()
{
	TestInsertSort();
	return 0;
}
