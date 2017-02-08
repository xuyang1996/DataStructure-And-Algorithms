#include "heap.h"

void TestHeap()
{
	int a[] = { 10, 11, 13, 12, 16, 18, 15, 17, 14, 19 };
	int sz = sizeof(a) / sizeof(a[0]);
	Heap<int, Greater<int>> heap(a, sz);
	cout << heap.Top() << endl;
	heap.DelTop();
	cout << heap.Top() << endl;
	heap.Insert(20);
	cout << heap.Top() << endl;
}


int main()
{
	return 0;
}
