#pragma once
#include <iostream>

using namespace std;


template<class K, class V, size_t M = 3>
struct BTreeNode
{
	pair<K, V> _kvs[M]; //store data
	BTreeNode<K, V, M>* _subs[M + 1]; //store children
	BTreeNode<K, V, M>* _parent; //current node's parent
	size_t _size; //current size of the node

	BTreeNode()
		: _size(0)
		, _parent(nullptr)
	{
		for (size_t i = 0; i < M; ++i)
		{
			_kvs[i] = pair<K, V>(); //use the default value
			_subs[i] = nullptr;
		}
		_subs[M] = nullptr;
	}
};


template<class K, class V, size_t M = 3>
class BTree
{
	typedef BTreeNode<K, V, M> Node;
public:
	BTree()
		: _root(nullptr)
	{}

	pair<Node*, int> Find(const K& key)
	{
		Node *cur = _root;
		Node *parent = nullptr;
		while (cur != nullptr)
		{
			size_t i = 0;
			while (i < cur->_size)
			{
				if (key < cur->_kvs[i].first)
					break;
				else if (key > cur->_kvs[i].first)
					++i;
				else
					return make_pair(cur, i); //find and return its position
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return make_pair(parent, -1); // not found and return -1 
	}

	bool Insert(const pair<K, V>& it)
	{
		if (_root == nullptr)
		{
			_root = new Node();
			_root->_kvs[0] = it;
			_root->_size = 1;
			return true;
		}
		pair<Node*, int> ret = Find(it.first);
		if (ret.second != -1) //this tree has had this key , no need to insert key
		{
			return false;
		}
		//we should insert now
		Node *cur = ret.first;
		Node *sub = nullptr;
		pair<K, V> kv = it;
		while (true)
		{
			_insertKV(cur, kv, sub);

			//according to current node's size, if it < M, there is nothing to do 
			if (cur->_size < M)
			{
				return true;
			}
			//else we need to adjust the node
			else
			{
				//将M/2往后的值复制到temp结点中
				size_t mid = cur->_size / 2;
				Node* temp = new Node();
				size_t tempPos = 0;
				size_t sz = cur->_size;
				for (size_t i = mid + 1; i < sz; ++i)
				{
					temp->_kvs[tempPos] = cur->_kvs[i];
					cur->_kvs[i] = pair<K, V>();
					temp->_subs[tempPos] = cur->_subs[i];
					if (cur->_subs[i] != nullptr)
						cur->_subs[i]->_parent = temp;
					++temp->_size;
					++tempPos;
				}
				temp->_subs[tempPos] = cur->_subs[sz];
				if (cur->_subs[sz] != nullptr)
					cur->_subs[sz]->_parent = temp;
				cur->_size -= (temp->_size + 1);

				if (cur->_parent == nullptr)
				{
					_root = new Node();
					_root->_kvs[0] = cur->_kvs[mid];
					cur->_kvs[mid] = pair<K, V>();
					_root->_size = 1;
					_root->_subs[0] = cur;
					_root->_subs[1] = temp;

					temp->_parent = _root;
					cur->_parent = _root;
					return true;
				}
				else
				{
					kv = cur->_kvs[mid];
					cur->_kvs[mid] = pair<K, V>();
					cur = cur->_parent;
					sub = temp;
				}

			}
		}

	}

	void InOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

private:
	void _inOrder(Node* root) 
	{
		if (root == nullptr)
			return;
		for (size_t i = 0; i < root->_size; ++i)
		{
			_inOrder(root->_subs[i]);
			cout << root->_kvs[i].first << " ";
		}
		_inOrder(root->_subs[root->_size]);
	}

	void _insertKV(Node *cur, const pair<K, V>& kv, Node* sub)
	{
		int sz = cur->_size;
		int i = sz - 1;
		while (i >= -1)
		{
			if (i == -1 || kv.first > cur->_kvs[i].first)
			{
				cur->_kvs[i + 1] = kv;
				cur->_subs[i + 2] = sub;
				++cur->_size;
				return;
			}
			else
			{
				cur->_kvs[i + 1] = cur->_kvs[i];
				cur->_subs[i + 2] = cur->_subs[i + 1];
			}
			--i;
		}
	}

private:
	Node* _root;
};
 
