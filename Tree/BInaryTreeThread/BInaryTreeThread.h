#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

enum PointerTag { LINK,THREAD };

template<class T>
struct BinaryTreeThreadNode
{
	T _data;  
	BinaryTreeThreadNode<T>* _left;//left pointer
	BinaryTreeThreadNode<T>* _right;//right pointer
	PointerTag _leftTag;  
	PointerTag _rightTag;

	BinaryTreeThreadNode(const T& x = T())
		: _data(x)
		, _left(nullptr)
		, _right(nullptr)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{}
};



template<class T>
class BinaryTreeThread
{
	typedef BinaryTreeThreadNode<T> Node;
public:
	BinaryTreeThread()
		: _root(nullptr)
	{}

	BinaryTreeThread(T *a, size_t n, const T& invalid = T())
	{
		assert(a);
		size_t index = 0;
		_root = _createTree(a, n, index, invalid);
	}

	void InOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

	void InOrderNonR()
	{
		Node *cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
				cur = cur->_left;
			cout << cur->_data << " ";
			while (cur && cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				if (cur)
					cout << cur->_data << " ";
			}
			if (cur->_rightTag == LINK)
				cur = cur->_right;
		}
		cout << endl;
	}

	void InOrderThreading()
	{
		Node *prev = nullptr;
		_inOrderThreading(_root, prev);
	}

	void PreOrder()
	{
		_preOrder(_root);
		cout << endl;
	}

	void PreOrderNonR()
	{
		Node *cur = _root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			cur = cur->_right;

			//
			//while (cur && cur->_rightTag == THREAD)
			//{
			//	cur = cur->_right;
			//	if (cur)
			//		cout << cur->_data << " ";
			//}
			//if (cur->_rightTag == LINK)
			//	cur = cur->_right;
		}
		cout << endl;
	}

	void PreOrderThreading()
	{
		Node *prev = nullptr;
		_preOrderThreading(_root, prev);
	}

	
private:
	Node *_createTree(T *a, size_t n, size_t& index, const T& invalid = T())
	{
		Node *root = nullptr;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _createTree(a, n, ++index, invalid);
			root->_right = _createTree(a, n, ++index, invalid);
		}
		return root;
	}

	void _inOrderThreading(Node *cur, Node *& prev)
	{
		if (cur == nullptr)
			return;
		//left subtree threading
		if (cur->_leftTag == LINK)
			_inOrderThreading(cur->_left, prev);
		//root threading
		if (cur->_left == nullptr)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}
		if (prev && prev->_right == nullptr)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		prev = cur;
		//right subtree threading
		if (cur->_rightTag == LINK)
			_inOrderThreading(cur->_right, prev);
	}

	void _preOrderThreading(Node *cur, Node *& prev)
	{
		if (cur == nullptr)
			return;
		//root threading
		if (cur->_left == nullptr)
		{
			cur->_left = prev;
			cur->_leftTag = THREAD;
		}
		if (prev && prev->_right == nullptr)
		{
			prev->_right = cur;
			prev->_rightTag = THREAD;
		}
		prev = cur;
		//left subtree threading
		if (cur->_leftTag == LINK)
			_preOrderThreading(cur->_left, prev);
		//right subtree threading
		if (cur->_rightTag == LINK)
			_preOrderThreading(cur->_right, prev);
	}

	void _inOrder(Node* root)
	{
		if (root == NULL)
			return;

		if (root->_leftTag == LINK)
			_inOrder(root->_left);

		cout << root->_data << " ";

		if (root->_rightTag == LINK)
			_inOrder(root->_right);
	}

	void _preOrder(Node *root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		if (root->_leftTag == LINK)
			_preOrder(root->_left);
		if (root->_rightTag == LINK)
			_preOrder(root->_right);
	}
private:
	Node *_root;
};

