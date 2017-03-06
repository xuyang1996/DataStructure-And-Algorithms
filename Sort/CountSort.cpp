#include <iostream>
#include <assert.h>
using namespace std;


//sort the data in an ascending order

void PrintArray(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void CountSort(int* a, int n)
{
	assert(a != nullptr && n > 0); 
	//know the range of unsorted array
	//for example, there are 50 numbers and their range is [0, 100]
	const int SIZE = 101;
	int* temp = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
		temp[i] = 0;
	//count its appearing times
	for (int i = 0; i < n; ++i)
	{
		temp[a[i]]++;
	}
	int index = 0;
	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < temp[i]; ++j)
		{
			a[index++] = i;
		}
	}
}

void TestCountSort()
{
	int a[50] = { 0 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < sz; ++i)
	{
		a[i] = rand() % 100 + 1;
	}
	PrintArray(a, sz);
	cout << endl;
	CountSort(a, sz);
	PrintArray(a, sz);
}

int main()
{
	TestCountSort();
	return 0;
}
