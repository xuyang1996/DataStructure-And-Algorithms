#pragma once

#include <iostream>
#include <assert.h>
#include <vector>
#include <map>

using namespace std;


template<class V, class W>
class GraphMatrix
{
public:
	GraphMatrix(V* a, int n, const W& invalid = W(), bool isDirected = false) // undirected graph by default
		: _isDirected(isDirected)
		, _invalid(invalid)
	{
		assert(a != nullptr && n > 0);
		//_matrix = new W*[_vertex.size()];
		//for (int i = 0; i < n; ++i)
		//{
		//	matrix[i] = new W[n];
		//	for (int j = 0; j < n; ++j)
		//	{
		//		_matrix[i][j] = invalid;
		//	}
		//}
		vector<vector<W>> newMatrix(n, vector<W>(n, _invalid));
		//vector<vector<W>> newMatrix(n);
		//for (int i = 0; i < newMatrix.size(); ++i)
		//{
		//	newMatrix[i].resize(n);
		//}
		_matrix = newMatrix;
		for (int i = 0; i < n; ++i) //��ÿ��Ԫ��ӳ��Ϊһ���±꣨�������룩
		{
			_indexMap[a[i]] = i;
		}
	}

	int GetVertexIndex(const V& v)
	{
		return _indexMap[v];
	}

	void AddEdge(const V& v1, const V& v2, const W& weight)
	{
		int src = GetVertexIndex(v1);
		int dst = GetVertexIndex(v2);
		_matrix[src][dst] = weight;
		if (_isDirected == false)
			_matrix[dst][src] = weight;
	}

	void RemoveEdge(const V& v1, const V& v2)
	{
		int src = GetVertexIndex(v1);
		int dst = GetVertexIndex(v2);
		_matrix[src][dst] = _invalid;
		if (_isDirected == false)
			_matrix[dst][src] = _invalid;
	}

	~GraphMatrix()
	{
		//for (int i = 0; i < _vertex.size(); ++i)
		//{
		//	delete[] _matrix[i];
		//	_matrix[i] = nullptr;
		//}
		//delete[] _matrix;
		//_matrix = nullptr;
	}

private:
	//vector<V> _vertex; 
	//W** _matrix; //�ڽӾ���
	vector<vector<W>> _matrix; //�ڽӾ���
	map<V, int> _indexMap; //�����
	W _invalid;
	bool _isDirected;
};

void TestGraphMatrix()
{
	string city[] = { "����", "����", "�Ӱ�", "μ��", "����" };
	GraphMatrix<string, double> g1(city, sizeof(city) / sizeof(city[0]));
	g1.AddEdge("����", "����", 100.5);
	g1.AddEdge("����", "μ��", 19.5);
	g1.AddEdge("����", "�Ӱ�", 50.5);
	g1.AddEdge("����", "����", 5.5);
}