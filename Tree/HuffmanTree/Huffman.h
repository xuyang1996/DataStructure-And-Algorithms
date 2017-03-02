#include "Heap.h"

template<class T>
struct HuffmanTreeNode
{
	T _weight;
	HuffmanTreeNode<T> *_left;
	HuffmanTreeNode<T> *_right;
	HuffmanTreeNode<T> *_parent;
	HuffmanTreeNode(const T& x)
		: _weight(x)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
	{}
};

template<class T>
struct Less<HuffmanTreeNode<T> *>
{
	bool operator()(const HuffmanTreeNode<T> *lhs, const HuffmanTreeNode<T> *rhs)
	{
		return lhs->_weight < rhs->_weight;
	}
};


template<class T>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	HuffmanTree()
		: _root(nullptr)
	{}

	HuffmanTree(T *a, size_t n, const T& invalid)
	{
		//build the heap
		Heap<Node *, Less<Node *> > minHeap;
		for (size_t i = 0; i < n; ++i)
		{
			if (a[i] != invalid)
			{
				minHeap.Insert(new Node(a[i]));
			}
		}
		//build the huffmantree
		while (minHeap.Size() > 1)
		{
			Node *leftNode = minHeap.Top();
			minHeap.DelTop();
			Node *rightNode = minHeap.Top();
			minHeap.DelTop();
			Node *parentNode = new Node(leftNode->_weight + rightNode->_weight);

			leftNode->_parent = parentNode;
			rightNode->_parent = parentNode;
			parentNode->_left = leftNode;
			parentNode->_right = rightNode;

			minHeap.Insert(parentNode);
		}
		_root = minHeap.Top();
	}

	~HuffmanTree()
	{
		_destroy(_root);
	}

	Node *GetRoot()
	{
		return _root;
	}

private:
	void _destroy(Node *root)
	{
		if (root == nullptr)
			return;
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
		root = nullptr;
	}

private:
	Node *_root;
};



//void TestHuffmanTree()
//{
//	int a[] = { 1, 5, 2, 4, 3 };
//	size_t sz = sizeof(a) / sizeof(a[0]);
//	HuffmanTree<int> tree(a, sz, '#');
//}
