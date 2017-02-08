#include <iostream> 

using namespace std;

void HeapSort(int *a, int n);
void DownReheapify(int *a, int n, int k);
void Print(int *a, int n);
void TestHeapSort();

int main()
{
	return 0;
}

void TestHeapSort()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int size = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size);
	Print(a, size);
}

void HeapSort(int *a, int n)
{	
	//build the greatest heap 
	int lastNonLeaf = (n - 1 - 1) / 2;
	for (int i = lastNonLeaf; i >= 0; --i)
		DownReheapify(a, n, i);
		
	//sort
	while (n >= 1)
	{
		swap(a[0], a[n - 1]);
		n--;
		DownReheapify(a, n, 0);
	}
}

void DownReheapify(int *a, int n, int k)
{
	int child = 2 * k + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[k])
		{
			swap(a[child], a[k]);
			k = child;
			child = 2 * k + 1;
		}
		else
			break;
	}
}


void Print(int *a, int n)
{
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}


