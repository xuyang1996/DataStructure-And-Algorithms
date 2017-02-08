#include <iostream>
#include <vector>


using namespace std;

const int N = 10000;

const int MOD = 1000;

void DownReheapify(vector<int>& a, int pos);
void PrintTopK(const vector<int>& a);


int main()
{
	//read big data into the vector
	vector<int> V;
	for (int i = 0; i < N; ++i)
		V.push_back(rand() % MOD);
	V[10] = 1000;
	V[100] = 10000;
	V[1000] = 33333;
	V[5000] = 9999;
	V[9999] = 66666;


	//find the greatest k number, here make k = 10
	vector<int> a;
	int k = 5;
	for (int i = 0; i < k; ++i)
		a.push_back(V[i]);
	
	//build the small heap
	int lastNonLeaf = (k - 1 - 1) / 2;
	for (int i = lastNonLeaf; i >= 0; --i)
		DownReheapify(a, i);

	int pos = k;
	while (pos < N)
	{
		int next = V[pos];
		if (a[0] < next)
		{
			a[0] = next;
			DownReheapify(a, 0); //reheapify	
		}	
		pos++;
	}

	//print the top k
	vector<int>::iterator it = a.begin();
	while (it != a.end())
		cout << *it++ << " ";


	return 0;
}

void DownReheapify(vector<int>& a, int pos)
{
	int n = a.size();
	int child = 2 * pos + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
			++child;
		if (a[child] < a[pos])
		{
			swap(a[child], a[pos]);
			pos = child;
			child = 2 * pos + 1;
		}
		else
			break;
	}
}

 
 
 
