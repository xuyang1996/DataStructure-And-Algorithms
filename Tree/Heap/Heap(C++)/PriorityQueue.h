#pragma once
#include "heap.h"



template<class T, class Compare = Greater<T> >
class PriorityQueue
{
public:
	PriorityQueue()
	{}

	void Push(const T& x)
	{
		_heap.Push(x);
	}

	void Pop()
	{
		_heap.Pop();
	}

	const T& Top() const
	{
		return _heap.Top();
	}

	size_t Size() const
	{
		return _heap.Size();
	}

	bool Empty() const
	{
		return _heap.Empty();
	}

private:
	Heap<T, Compare> _heap;
};
