#include "BInaryTreeThread.h"

void Test()
{
	int array[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTreeThread<int> tree(array, sizeof(array) / sizeof(array[0]), '#');
	tree.InOrderThreading();
	tree.InOrder();
	//tree.PreOrderThreading();
	//tree.PreOrder();
}

void Test1()
{
	int array[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTreeThread<int> tree(array, sizeof(array) / sizeof(array[0]), '#');
	tree.InOrderThreading();
	tree.InOrder();
	//tree.PreOrderThreading();
	//tree.PreOrder();
}

int main()
{
	Test();
	Test1();
	return 0;
}
