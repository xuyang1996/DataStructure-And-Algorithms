#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;


template<class T>
struct Greater
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs > rhs;
	}
};

template<class T>
struct Less
{
	bool operator()(const T& lhs, const T& rhs)
	{
		return lhs < rhs;
	}
};



template<class T, class Compare = Greater<T> >
class Heap
{
public:
	Heap()
	{}

	Heap(T *a, size_t n)
	{
		for (size_t i = 0; i < n; ++i)
		{
			_v.push_back(a[i]);
		}
		//从最后一个非叶子结点调整
		int lastNonLeaf = ((n - 1) - 1) / 2;
		for (int i = lastNonLeaf; i >= 0; --i)
			DownReheapify(i);
	}

	void Insert(const T& x)
	{
		_v.push_back(x);
		UpReheapify(_v.size() - 1);
	}

	void DelTop()
	{
		swap(_v[0], _v[_v.size() - 1]);
		_v.pop_back();
		DownReheapify(0);
	}

	T& Top()
	{
		assert(!_v.empty());
		return _v[0];
	}

	const T& Top() const 
	{
		assert(!_v.empty());
		return _v[0];
	}

	size_t Size() const
	{
		return _v.size();
	}

	bool Empty() const
	{
		return _v.empty();
	}

private:
	void UpReheapify(size_t k)//向上调整
	{
		Compare compare;
		size_t parent = (k - 1) / 2;
		while (k > 0)
		{
			if (compare(_v[k], _v[parent])) //比较孩子和父亲的大小
			{
				swap(_v[k], _v[parent]);
				k = parent;
				parent = (k - 1) / 2;
			}
			else
				break;
		}
	}

	void DownReheapify(size_t k)//向下调整
	{
		Compare compare;
		size_t child = 2 * k + 1;
		while (child < _v.size())
		{
			//找到左右孩子中大的那个
			if (child + 1 < _v.size() && compare(_v[child + 1], _v[child]))
				++child;
			//交换孩子和父亲的值
			if (compare(_v[child], _v[k]))
			{
				swap(_v[child], _v[k]);
				k = child;
				child = 2 * k + 1;
			}
			else
				break;
		}
	}

private:
	vector<T> _v;
};
