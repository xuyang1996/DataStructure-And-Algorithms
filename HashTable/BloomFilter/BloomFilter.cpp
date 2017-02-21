#include "BitMap.h"
#include "HashFun.h"

// simple BloomFilter for string

class BloomFilter
{
public:
	BloomFilter(size_t num) //the num of string to be inserted
		: _bm(num * 5 * 2) // each string has five hashfun corresponding to 5 bit
		, _size(num * 5 * 2) 
	{}

	void Insert(const string& key)
	{
		size_t hash1 = HashFun1()(key) % _size;
		size_t hash2 = HashFun2()(key) % _size;
		size_t hash3 = HashFun3()(key) % _size;
		size_t hash4 = HashFun4()(key) % _size;
		size_t hash5 = HashFun5()(key) % _size;
		_bm.Set(hash1);
		_bm.Set(hash2);
		_bm.Set(hash3);
		_bm.Set(hash4);
		_bm.Set(hash5);
	}

	bool HasExisted(const string& key)
	{
		size_t hash1 = HashFun1()(key) % _size;
		if (!_bm.HasExisted(hash1))
			return false;
		size_t hash2 = HashFun2()(key) % _size;
		if (!_bm.HasExisted(hash2))
			return false;
		size_t hash3 = HashFun3()(key) % _size;
		if (!_bm.HasExisted(hash3))
			return false;
		size_t hash4 = HashFun4()(key) % _size;
		if (!_bm.HasExisted(hash4))
			return false;
		size_t hash5 = HashFun5()(key) % _size;
		if (!_bm.HasExisted(hash5))
			return false;
		return true;
	}
private:
	BitMap _bm;
	size_t _size;
};

void TestBloomFilter()
{
	BloomFilter bf(1000);
	string s0 = "http://blog.csdn.net/xy913741894/article/details/56301910";
	string s1 = "http://blog.csdn.net/xy913741894/article/details/56301911";
	string s2 = "http://blog.csdn.net/xy913741894/article/details/56301912";

	bf.Insert(s0);
	bf.Insert(s1);
	bf.Insert(s2);

	cout << bf.HasExisted(s0) << endl;
	cout << bf.HasExisted(s1) << endl;
	cout << bf.HasExisted(s2) << endl;

	cout << bf.HasExisted("hello") << endl;
}



int main()
{
	TestBloomFilter();
	return 0;
}
