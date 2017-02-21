#pragma once
#include <string>

using namespace std;

struct HashFun1
{
	size_t operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}

	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
			// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;       
		}
		return hash;
	}
};

struct HashFun2
{
	size_t operator()(const string& key)
	{
		return SDBMHash(key.c_str());
	}

	/// @brief SDBM Hash Function  
	/// @detail 本算法是由于在开源项目SDBM（一种简单的数据库引擎）中被应用而得名，它与BKDRHash思想一致，只是种子不同而已。  
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = 65599 * hash + ch;
			//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
		}
		return hash;
	}
};

struct HashFun3
{
	size_t operator()(const string& key)
	{
		return RSHash(key.c_str());
	}

	/// @detail 因Robert Sedgwicks在其《Algorithms in C》一书中展示而得名。  
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
};

struct HashFun4
{
	size_t operator()(const string& key)
	{
		return APHash(key.c_str());
	}

	size_t APHash(const char *str)
	{
		register size_t hash = 0;
		size_t ch;
		for (long i = 0; ch = (size_t)*str++; i++)
		{
			if ((i & 1) == 0)
			{
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else
			{
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};

struct HashFun5
{
	size_t operator()(const string& key)
	{
		return JSHash(key.c_str());
	}

	size_t JSHash(const char *str)
	{
		if (!*str)       
			return 0;
		register size_t hash = 1315423911;
		while (size_t ch = (size_t)*str++)
		{
			hash ^= ((hash << 5) + ch + (hash >> 2));
		}
		return hash;
	}
};

