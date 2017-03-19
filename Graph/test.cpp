#include "GraphList.h"
#include "GraphMatrix.h"
#include "UnionFind.h"

#include <string>

//comparsion between graph_list and graph_matirx 对比邻接表和邻接矩阵
// 1. 如果仅想知道两点的连通状态，矩阵较好，定位下标几乎是O(1)
// 2. 如果想知道一个点有多少邻接顶点，邻接表较好，用矩阵扫描几乎是O(n)
// 3. 如果点较多，而边很少，邻接矩阵比较浪费空间，因为都是无效值

int main()
{
	//TestGraphMatrix();
	TestGraphList();

	//TestFriends();


	return 0;
}