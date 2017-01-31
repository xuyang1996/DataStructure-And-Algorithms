#pragma once
#include <iostream>
#include <assert.h>
#include <queue>
#include <stack>
using namespace std;


template<class T>
struct BinaryTreeNode //define the BinaryTreeNode
{
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
	BinaryTreeNode(const T& x)
		:_data(x)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class T>
class BinaryTree
{
	using Node = BinaryTreeNode<T>;
	//typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		: _root(nullptr)
	{}

	BinaryTree(T *a, size_t n, const T& invalid = T())//create the tree using recursion
	{
		assert(a);
		size_t index = 0;
		_root = _createTree(a, n, invalid, index);
	}

	BinaryTree(const BinaryTree<T>& other)
	{
		_root = _copy(other._root);
	}

	BinaryTree& operator=(const BinaryTree<T>& other)
	{
		if (this != &other)
		{
			Node *tempRoot = _copy(other._root);
			_destroy(_root);
			_root = tempRoot;
		}
		return *this;
	}

	//BinaryTree& operator=(BinaryTree<T> other)
	//{
	//	swap(_root, other._root);
	//	return *this;
	//}

	~BinaryTree()
	{
		_destroy(_root);
		_root = nullptr;
	}

	void PostOrder()
	{
		_postOrder(_root);
		cout << endl;
	}

	void InOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

	void PreOrder()
	{
		_preOrder(_root);
		cout << endl;
	}

	void LevelOrder()
	{
		queue<Node *> q;
		if (_root)
			q.push(_root);
		while (!q.empty())
		{
			Node *front = q.front();
			cout << front->_data << " ";
			q.pop();
			if (front->_left)
				q.push(front->_left);
			if (front->_right)
				q.push(front->_right);
		}
		cout << endl;
	}

	void PreOrderNonRecursion()
	{
		stack<Node *> stk;
		Node *cur = _root;
		while (!stk.empty() || cur)
		{
			while (cur)
			{
				// preorder traverse
				// print data of the node then push node until the node is nullptr
				cout << cur->_data << " ";
				stk.push(cur);
				cur = cur->_left;
			}
			// access the node then pop which indicates that
			// this node and its left subtree have been accessed 
			// so we try to access its right subtree
			Node *tempRoot = stk.top();
			stk.pop();
			//go to the subproblem
			cur = tempRoot->_right;
		}
		cout << endl;
	}

	void InOrderNonRecursion()
	{
		stack<Node *> stk;
		Node *cur = _root;
		while (!stk.empty() || cur)
		{
			// inorder traverse
			// just push the node until its left subtree is nullptr
			while (cur)
			{
				stk.push(cur);
				cur = cur->_left;
			}
			// access the stack's top and print which indiactes that temporary root and left subtree have been accessed 
			Node *tempRoot = stk.top();
			cout << tempRoot->_data << " ";
			stk.pop();
			// then go to its right subtree
			cur = tempRoot->_right;
		}
		cout << endl;
	}

	void PostOrderNonRecursion()
	{
		stack<Node *> stk;
		Node *cur = _root;
		Node *prev = nullptr;
		while (!stk.empty() || cur)
		{
			while (cur)
			{
				stk.push(cur);
				cur = cur->_left;
			}

			Node *tempRoot = stk.top();
			if (tempRoot->_right == nullptr || tempRoot->_right == prev)
			{
				cout << tempRoot->_data << " ";
				prev = tempRoot;
				stk.pop();
			}
			else
			{
				cur = tempRoot->_right;
			}
		}
		cout << endl;
	}

	Node* Find(Node* root, const T& x)
	{
		if (root == nullptr)
			return nullptr;
		if (root->_data == x)
			return root;
		Node* ret = Find(root->_left, x);
		if (ret == nullptr)
			ret = Find(root->_right, x);
		return ret;
	}

	size_t Size()
	{
		return _size(_root);
	}

	size_t Depth()
	{
		return _depth(_root);
	}

	size_t GetLeafSize()
	{
		size_t k = 0;
		_getLeafSize(_root, k);
		return k;
	}

	size_t GetKLevelSize(size_t level)
	{
		assert(level > 0 || level <= Depth());
		return _getKLevelSize(_root, level);
	}

	void PrintKLevelNode(size_t level)
	{
		assert(level > 0 || level <= Depth());
		_printKLevelNode(_root, level);
		cout << endl;
	}

private:
	Node *_createTree(T *a, size_t n, const T& invalid, size_t& index)
	{
		Node *root = nullptr;
		if (index < n && a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _createTree(a, n, invalid, ++index);
			root->_right = _createTree(a, n, invalid, ++index);
		}
		return root;
	}

	Node *_copy(Node *root)
	{
		if (root == nullptr)
			return nullptr;
		Node *cur = new Node(root->_data);
		cur->_left = _copy(root->_left);
		cur->_right = _copy(root->_right);
		return cur;
	}

	void _destroy(Node *root)
	{
		if (root == nullptr)
			return;
		_destroy(root->_left);
		_destroy(root->_right);
		delete root;
	}

	void _inOrder(Node *root)
	{
		if (root == nullptr)
			return;
		_inOrder(root->_left);
		cout << root->_data << " ";
		_inOrder(root->_right);
	}

	void _preOrder(Node *root)
	{
		if (root == nullptr)
			return;
		cout << root->_data << " ";
		_preOrder(root->_left);
		_preOrder(root->_right);
	}

	void _postOrder(Node *root)
	{
		if (root == nullptr)
			return;
		_postOrder(root->_left);
		_postOrder(root->_right);
		cout << root->_data << " ";
	}

	size_t _size(Node *root)
	{
		if (root == nullptr)
			return 0;
		int leftSize = _size(root->_left);
		int rightSize = _size(root->_right);
		return leftSize + rightSize + 1;
	}

	size_t _depth(Node *root)
	{
		if (root == nullptr)
			return 0;
		int leftDepth = _depth(root->_left);
		int rightDepth = _depth(root->_right);
		return leftDepth > rightDepth ? (leftDepth + 1) : (rightDepth + 1);
	}

	void _getLeafSize(Node *root, size_t& k)
	{
		if (root == nullptr)
			return;
		if (root->_left == nullptr && root->_right == nullptr)
			++k;
		_getLeafSize(root->_left, k);
		_getLeafSize(root->_right, k);
	}

	size_t _getKLevelSize(Node *root, size_t level)
	{
		if (root == nullptr)
			return 0;
		if (level == 1)
			return 1;
		return _getKLevelSize(root->_left, level - 1) + _getKLevelSize(root->_right, level - 1);
	}

	void _printKLevelNode(Node *root, size_t level)
	{
		if (root == nullptr)
			return;
		if (level == 1)
			cout << root->_data << " ";
		_printKLevelNode(root->_left, level - 1);
		_printKLevelNode(root->_right, level - 1);
	}
private:
	Node *_root;
};
