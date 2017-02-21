#include <iostream>
#include <vector>

using namespace std;

// for more details, please go to my csdn
// 
class BitMap
{
public:
	BitMap(size_t num)
	{
		_v.resize((num >> 5) + 1);
	}

	void Set(size_t num) //set 1
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_v[index] |= (1 << pos);
	}

	void ReSet(size_t num) //set 0
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		_v[index] &= ~(1 << pos);
	}

	bool HasExisted(size_t num)//check whether it exists
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		bool flag = false;
		if (_v[index] & (1 << pos))
			flag = true;
		return flag;

	}

private:
	vector<size_t> _v;
}; 


void TestBitMap()
{
	BitMap bm((size_t)-1);//store all unsigned int 
	bm.Set(1);
	bm.Set(111);
	bm.Set(222);
	bm.Set(3333);
	bm.Set(7777);
	bm.Set(9999);
	bm.Set(666666);
	bm.ReSet(1);
	bm.ReSet(666666);

	cout << bm.HasExisted(1) << endl;
	cout << bm.HasExisted(111) << endl;
	cout << bm.HasExisted(222) << endl;
	cout << bm.HasExisted(3333) << endl;
	cout << bm.HasExisted(7777) << endl;
	cout << bm.HasExisted(9999) << endl;
	cout << bm.HasExisted(666666) << endl;
}

int main()
{
	TestBitMap();
	return 0;
 } 
