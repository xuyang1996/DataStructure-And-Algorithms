#pragma once

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;



class UnionFind
{
public:
	UnionFind(int n)
		: _count(n)
	{
		_v.resize(n, -1);
	}

	void Union(int x, int y) //union two sets
	{
		int root1 = FindRoot(x);
		int root2 = FindRoot(y);
		if (root1 == root2)
			return;
		if (abs(_v[root1]) < abs(_v[root2]))
		{
			_v[root2] += _v[root1];
			_v[root1] = root2;
		}
		else
		{
			_v[root1] += _v[root2];
			_v[root2] = root1;
		}
		--_count; 
	}

	int FindRoot(int x)
	{
		while (_v[x] >= 0)
		{
			x = _v[x];
		}
		return x;
	}

	int Count() //the count of the union
	{
		return _count;
	}

	bool Connected(int x, int y) //whether x and y are in the same union set
	{
		return FindRoot(x) == FindRoot(y);
	}

private:
	vector<int> _v;
	int _count;
};


//int Friends(int n, int m, int r[][2])
//{
//	UnionFind ufs(n + 1);
//	for (int i = 0; i < m; ++i)
//	{
//		ufs.Union(r[i][0], r[i][1]);
//	}
//
//	return ufs.Count() - 1;
//}
//
//void TestFriends()
//{
//	const int n = 5;
//	const int m = 4;
//	int r[m][2] = { { 1, 2 }, { 2, 3 }, { 4, 5 }, { 1, 3 } };
//
//	cout << "ÅóÓÑÈ¦µÄ¸öÊý : " << Friends(n, m, r) << endl;
//}