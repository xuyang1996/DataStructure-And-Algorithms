#include "BTree.h"

void TestBtree()
{
	BTree<int, int> t;
	int a[] = { 53, 75, 139, 49, 145, 36, 101 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		t.Insert(make_pair(a[i], i));
	}

	t.InOrder();
}

int main()
{
	TestBtree();
	return 0;
}
