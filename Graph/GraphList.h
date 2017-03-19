#pragma once

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include "UnionFind.h"

using namespace std;

template<class W>
struct VertexNode
{
	int _src; //其他点连通自己，他们的下标
	int _dst; //自己的下标
	W _weight;// 权值
	VertexNode<W>* _next;

	VertexNode(int otherIndex, int selfIndex, const W& weight)
		: _src(otherIndex)
		, _dst(selfIndex)
		, _weight(weight)
		, _next(nullptr)
	{}
};


template<class V, class W>
class GraphList
{
	typedef VertexNode<W> Node;
public:
	GraphList()
	{}

	GraphList(V* a, int n, bool isDirected = false)
		: _vertex(a, a+n)
		, _isDirected(isDirected)
	{
		_table.resize(n, nullptr);	
	}

	int GetVertexIndex(const V& v)
	{
		int i = 0;
		for (; i < (int)_vertex.size(); ++i)
		{
			if (_vertex[i] == v)
				break;
		}
		return i;
	}

	void AddEdge(const V& v1, const V& v2, const W& weight)
	{
		int src = GetVertexIndex(v1);
		int dst = GetVertexIndex(v2);
		_addEdge(src, dst, weight);
		if (_isDirected == false)
			_addEdge(dst, src, weight);
	}

	void BFS(const V& v) // 宽度优先遍历 
	{ 
		vector<bool> visited;
		visited.resize(_vertex.size(), false);

		queue<int> q;
		int index = GetVertexIndex(v);
		q.push(index);
		visited[index] = true;

		while (!q.empty())
		{
			int front = q.front();
			q.pop();
			cout << _vertex[front] << "  ";

			Node* cur = _table[front];
			while (cur != nullptr)
			{
				if (!visited[cur->_dst])
				{
					q.push(cur->_dst);
					visited[cur->_dst] = true;
				}
				cur = cur->_next;
			}
		}
		cout << endl;
	}

	void DFS(const V& v) // 深度优先遍历 
	{
		vector<bool> visited;
		visited.resize(_vertex.size(), false);

		int index = GetVertexIndex(v);

		_dfs(index, visited);
		cout << endl;
	}

	void Kruskal(GraphList<V, W>& g)
	{
		//create the graph with no edge
		g._isDirected = _isDirected;
		g._vertex = _vertex;
		g._table.resize(g._vertex.size(), nullptr);

		struct Compare
		{
			bool operator()(const Node* l, const Node* r)
			{
				return l->_weight > r->_weight;
			}
		};
		priority_queue<Node*, vector<Node*>, Compare> q; //build the min heap based on the weight
		for (int i = 0; i < (int)_table.size(); ++i)
		{
			Node* cur = _table[i];
			while (cur != nullptr)
			{
				if (cur->_src < cur->_dst)
					q.push(cur);
				cur = cur->_next;
			}
		}
		//each time chose the min edge

		UnionFind uf(g._vertex.size());//prevent the circle
		int count = 0;
		for (;;)
		{
			Node* top = q.top();
			q.pop();
			W weight = top->_weight;
			
			if (!uf.Connected(top->_src, top->_dst))
			{
				g.AddEdge(g._vertex[top->_src], g._vertex[top->_dst], weight); //add edge
				uf.Union(top->_src, top->_dst);//union these two vertex
				++count;
				if (count == g._vertex.size() - 1)
					break;
			}

		}
	}

	void Prim()
	{

	}

private:
	void _dfs(int index, vector<bool>& visited)
	{
		if (!visited[index])
		{
			cout << _vertex[index] << "  ";
			visited[index] = true;
		}
		Node* cur = _table[index];
		while (cur != nullptr)
		{
			if (!visited[cur->_dst])
			{
				_dfs(cur->_dst, visited);
			}
			cur = cur->_next;
		}
	}

	void _addEdge(int src, int dst, const W& weight)
	{
		//头插
		Node* temp = new Node(src, dst, weight);
		temp->_next = _table[src];
		_table[src] = temp;
	}

private:
	vector<V> _vertex; //顶点集合 
	vector<Node*> _table; //邻接表
	bool _isDirected; //有向图还是无向图
};


void TestGraphList()
{
	string num[] = { "1", "2", "3", "4", "5", "6", "7", "8" };
	GraphList<string, double> g1(num, sizeof(num) / sizeof(num[0]));
	g1.AddEdge("1", "2", 1.2);
	g1.AddEdge("1", "3", 1.3);
	g1.AddEdge("2", "4", 2.4);
	g1.AddEdge("2", "5", 2.5);
	g1.AddEdge("3", "6", 3.6);
	g1.AddEdge("3", "7", 3.7);
	g1.AddEdge("4", "8", 4.8);
	g1.AddEdge("5", "8", 5.8);
	g1.AddEdge("6", "7", 6.7);
	g1.BFS("1");
	//g1.DFS("1");
	GraphList<string, double> minTree;
	g1.Kruskal(minTree);
	minTree.BFS("1");
}