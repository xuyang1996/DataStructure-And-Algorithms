#include "GraphList.h"
#include "GraphMatrix.h"
#include "UnionFind.h"

#include <string>

//comparsion between graph_list and graph_matirx �Ա��ڽӱ���ڽӾ���
// 1. �������֪���������ͨ״̬������Ϻã���λ�±꼸����O(1)
// 2. �����֪��һ�����ж����ڽӶ��㣬�ڽӱ�Ϻã��þ���ɨ�輸����O(n)
// 3. �����϶࣬���ߺ��٣��ڽӾ���Ƚ��˷ѿռ䣬��Ϊ������Чֵ

int main()
{
	//TestGraphMatrix();
	TestGraphList();

	//TestFriends();


	return 0;
}