
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


void ShellSort(int *a, int n)
{
	assert(a != nullptr && n > 0);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; ++i)
		{
			int endPos = i - gap;
			int temp = a[i];
			while (endPos >= 0)
			{
				if (a[endPos] < temp)
				{
					break;
				}
				else
				{
					a[endPos + gap] = a[endPos];
					endPos -= gap;
				}
			}
			a[endPos + gap] = temp;
		}
	}
}


void TestShellSort()
{
	int a[] = { 2, 5, 4, 9, 3, 6, 8, 7, 1, 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	ShellSort(a, sz);
	PrintArray(a, sz);
}

int main()
{
	TestShellSort();
	return 0;
}



