#include <iostream>
#include <cmath>
#include <stack>
#include <cstdio> 
#include <cstring>
using namespace std;

//it's about the application of the stack

void RadixConversion(int num, int base)
{
	stack<char> s;
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
							'A', 'B', 'C', 'D', 'E', 'F', };
	do {
		s.push(digit[num % base]);
		num /= base;
	} while (num != 0);

	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

bool Match(const char paren[])//match {},(),[]
{
	int len = (int)strlen(paren);
	stack<char> s;
	for (int i = 0; i < len; ++i)
	{
		if (paren[i] == '(' || paren[i] == '[' || paren[i] == '{')
			s.push(paren[i]);
		else if (paren[i] == ')' || paren[i] == ']' || paren[i] == '}')
		{
			if (s.empty())
				return false;
			else
			{
				switch (paren[i])
				{
				case ')':
					if (s.top() == '(')
						s.pop();
					else
						return false;
					break;

				case ']':
					if (s.top() == '[')
						s.pop();
					else
						return false;
					break;

				case '}':
					if (s.top() == '{')
						s.pop();
					else
						return false;
					break;
				default:
					return false;
				}
			}
		}
		else {} //ignore other characters
	}
	return s.empty();
}

bool MatchWithCounter(const char paren[])//only has one kind of (, if mixed with {,[, it is invalid
{
	int count = 0;
	int len = (int)strlen(paren);
	for (int i = 0; i < len; ++i)
	{
		if (paren[i] == '(')
			count++;
		else if (paren[i] == ')')
			count--;
		else {} //ignore other characters
	}
	return count == 0;
}

bool CheckStackPermutation(const int *first, const int *second, int n)
{
	//assert(first != nullptr && second != nullptr && n > 0);
	if (first == nullptr && second == nullptr && n <= 0)
		return false;
	stack<int> s;
	int firstPos = 0;
	int secondPos = 0;
	while (secondPos != n)
	{
		while (s.empty() || s.top() != second[secondPos])
		{
			if (firstPos == n)
			{
				return false;
			}			
			s.push(first[firstPos++]);
		}
		s.pop();
		++secondPos;
	}
	return true;
}



int main()
{
	//char *a = "((sdasd)526(165*7/*())(++6))";
	//cout << Match(a) << endl; 
	//char *b = "{()[(5+)]{2515}[sadad]}";
	//cout << Match(b) << endl;

	//const int a[] = { 1, 2, 3, 4, 5 };
	//const int b[] = { 4, 5, 3, 2, 1 };
	//const int c[] = { 4, 3, 5, 1, 2 };
	//CheckStackPermutation(a, b, 5);
	//CheckStackPermutation(a, c, 5);

	return 0;
}
