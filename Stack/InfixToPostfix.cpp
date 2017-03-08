#include <iostream>
#include <cmath>
#include <stack>
#include <cctype>
using namespace std;



bool IsOperand(char c)
{
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
		return true;
	else
		return false;
}

char Precede(char lopt, char ropt)
{
	switch (lopt){
	case '+':
	case '-':
		if (ropt == '+' || ropt == '-' || ropt == ')' || ropt == '\0')
			return '>';
		else if (ropt == '*' || ropt == '/' || ropt == '(')
			return '<';
	case '*':
	case '/':
		if (ropt == '+' || ropt == '-' || ropt == '*' || ropt == '/' || ropt == ')' || ropt == '\0')
			return '>';
		else if (ropt == '(')
			return '<';
	case '(':
		if (ropt == '+' || ropt == '-' || ropt == '*' || ropt == '/' || ropt == '(')
			return '<';
		else if (ropt == ')')
			return '=';
	case ')':
		if (ropt == '+' || ropt == '-' || ropt == '*' || ropt == '/' || ropt == ')' || ropt == '\0')
			return '>';
	case '\0':
		if (ropt == '+' || ropt == '-' || ropt == '*' || ropt == '/' || ropt == '(')
			return '<';
		else if (ropt == '\0')
			return '=';
	}
}

void ChangeInfixToPostfix(const char* expression)
{
	stack<char> s;
	s.push('\0');
	int index = 0;
	while (!s.empty())
	{
		if (IsOperand(expression[index]))
		{
			cout << expression[index] << " ";
		}
		else
		{
			char pri = Precede(s.top(), expression[index]);
			switch (pri)
			{
			case '<':
				s.push(expression[index]);
				break;

			case '>':
				{
					while (pri == '>')
					{
						cout << s.top() << " ";
						s.pop();
						pri = Precede(s.top(), expression[index]);
					}
					if (pri == '=')
					{
						s.pop();
					}
					else
					{
						s.push(expression[index]);
					}
				}
				break;
			case '=':
				s.pop();
				break;

			}
		}
		++index;
	}

}

int main()
{
	char expression[] = "a+b*c+(d*e+f)*g";
	//abc*+de*f+g*+
	ChangeInfixToPostfix(expression);
	return 0;
}
