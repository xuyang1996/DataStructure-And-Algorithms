#include <iostream>
#include <vector>
#include <assert.h>
#include <cmath>
using namespace std;


//sort the data in an ascending order
void PrintVector(const vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
}


int GetDigitOfPos(int num, int pos)
{
	assert(pos >= 1);
	//from the right to left like the num 982 
	//2 is its first pos, 8 is second and so forth
	int ret = 0;
	for (int i = 1; i <= pos; ++i)
	{
		ret = num % 10;
		num /= 10;
	}
	return ret;
}


void RadixSort(vector<int>& v) //also called BucketSort
{
	assert(v.size() > 0);
	vector<vector<int>> digitArray;
	digitArray.resize(10);
	//get the max pos 
	//like 982, maxPos = 3
	int maxPos = 1;
	int base = 10;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		if (v[i] >= base)
		{
			++maxPos;
			base *= 10;
		}
	}

	for (int pos = 1; pos <= maxPos; ++pos)
	{
		for (int i = 0; i < (int)v.size(); ++i)
		{
			int digitOfPos = GetDigitOfPos(v[i], pos);
			digitArray[digitOfPos].push_back(v[i]);
		}
		//write back into the v
		int index = 0;
		for (int i = 0; i < (int)digitArray.size(); ++i)
		{
			for (int j = 0; j < (int)digitArray[i].size(); ++j)
			{
				v[index++] = digitArray[i][j];
			}
			digitArray[i].clear();
		}
		//PrintVector(v);
	}
}


void TestRadixSort()
{
	//int a[50] = { 0 };
	//for (int i = 0; i < sz; ++i)
	//{
	//	a[i] = rand() % 1000 + 1;
	//}
	int a[] = { 999999999, 65, 24, 47, 13, 50, 92, 88, 66, 33, 22445, 10001, 624159, 624158, 624155501 };
	int sz = sizeof(a) / sizeof(a[0]);
	vector<int> v(a, a + sz);
	PrintVector(v);
	RadixSort(v);
	PrintVector(v);
}

int main()
{
	TestRadixSort();
	return 0;
} 
