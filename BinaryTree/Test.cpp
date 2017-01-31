#include "BinaryTree.h"

void TestBinaryTree()
{
	int a[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6};
	BinaryTree<int> t1(a, sizeof(a) / sizeof(a[0]), '#');
	t1.PreOrder();
	t1.InOrder();
	t1.PostOrder();
	t1.LevelOrder();
	cout << endl;
	t1.PreOrderNonRecursion();
	t1.InOrderNonRecursion();
	t1.PostOrderNonRecursion();

	cout << "size is " << t1.Size() << endl;
	cout << "size is " << t1.Depth() << endl;
	cout << "getLeafSize is " << t1.GetLeafSize() << endl;
	
	cout << t1.GetKLevelSize(1) << " : "; t1.PrintKLevelNode(1);
	cout << t1.GetKLevelSize(2) << " : "; t1.PrintKLevelNode(2);
	cout << t1.GetKLevelSize(3) << " : "; t1.PrintKLevelNode(3);
}


int main()
{
	TestBinaryTree();
	return 0;
}
