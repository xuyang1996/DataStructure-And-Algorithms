#include <iostream>
#include <assert.h>

using namespace std;


template<class T>
struct BSTreeNode
{
	T _data;
	BSTreeNode<T> *_left;
	BSTreeNode<T> *_right;
	BSTreeNode(const T& key)
		: _data(key)
		, _left(nullptr)
		, _right(nullptr)
	{}

	T operator*()
	{
		return _data;
	}

	friend ostream& operator<<(ostream& _cout, const BSTreeNode<T>& node)
	{
		_cout << node._data;
		return _cout;
	}
};

template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		: _root(nullptr)
	{}

	bool Insert(const T& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur)
		{
			if (cur->_data < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_data > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (parent->_data > key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

	bool Remove(const T& key)
	{
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur)
		{
			if (key < cur->_data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else //equal
			{
				if (cur->_left == nullptr) //left subtree is null
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else if (cur->_data < parent->_data)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
					cur = nullptr;
				}
				else if (cur->_right = nullptr) //right subtre is null
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else if (cur->_data < parent->_data)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
					delete cur;
					cur = nullptr;
				}
				else //left subtree not null and right subtree not null
				{
					//find the max in the left subtree
					Node *leftMax = cur->_left;
					Node *leftMaxParent = cur;
					while (leftMax->_right)
					{
						leftMaxParent = leftMax;
						leftMax = leftMax->_right;
					}
					//make the cur data = leftMax data
					cur->_data = leftMax->_data;
					if (leftMaxParent->_data < leftMax->_data)
					{
						leftMaxParent->_right = nullptr;
					}
					else
					{
						leftMaxParent->_left = nullptr;
					}
					delete leftMax;
					leftMax = nullptr;

				}//end of else
				return true;
			}//end of equal
		}
		return false;
	}

	const Node* Find(const T& key)
	{
		Node *cur = _root;
		while (cur)
		{
			if (key < cur->_data)
				cur = cur->_left;
			else if (key > cur->_data)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}

	Node* FindMax()
	{
		Node  *cur = _root;
		while (cur->_right)
		{
			cur = cur->_right;
		}
		return cur;
	}

	Node* FindMin()
	{
		Node  *cur = _root;
		while (cur->_left)
		{
			cur = cur->_left;
		}
		return cur;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	void _InOrder(Node *root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_data << " ";
		_InOrder(root->_right);
	}

private:
	Node *_root;
};



void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> t;
	size_t sz = sizeof(a) / sizeof(a[0]);
	for (size_t i = 0; i < sz; ++i)
	{
		t.Insert(a[i]);
	}
	t.InOrder();
	BSTreeNode<int> *min = t.FindMin();
	BSTreeNode<int> *max = t.FindMax();
	cout << *min << endl;
	cout << *max << endl;


	t.Remove(0);
	t.Remove(1);
	t.Remove(2);
	t.Remove(3);
	t.Remove(4);
	t.Remove(5);
	t.Remove(6);
	t.Remove(7);
	t.Remove(8);
	t.Remove(9);

	t.InOrder();
}

int main()
{
	TestBSTree();
	return 0;
}
