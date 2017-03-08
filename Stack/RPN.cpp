#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

enum Type {
	OPERATOR,//ÔËËã·û
	OPERAND,//ÔËËãÊý
	ADD,
	SUB,
	MUL,
	DIV,
};

struct Cell {
	Type _type;
	int _value;
};

int CountRPN(Cell *exp, size_t n)
{
	stack<int> s;
	for (size_t i = 0; i < n; ++i)
	{
		if (exp[i]._type == OPERAND)
		{
			s.push(exp[i]._value);
		}
		else if (exp[i]._type == OPERATOR)
		{
			int right = s.top();
			s.pop();
			int left = s.top();
			s.pop();
			int result = 0;
			switch (exp[i]._value)
			{
			case ADD:
				result = left + right;
				break;
			case SUB:
				result = left - right;
				break;
			case MUL:
				result = left * right;
				break;
			case DIV:
				if (right == 0)
				{
					assert(false);
					//throw logic_error("the divisor can not be zero\n");
				}			
				result = left / right;
				break;
			default:
				//assert(false);
				cout << "can not support this calculation apart from +-/*" << endl;
				break;
			}
			s.push(result);
		}
		else
		{
			assert(false);
			//throw std::invalid_argument("the expression you input is wrong\n");
		}
	}
	return s.top();
}


int main()
{

	Cell rpn[] = {
		{ OPERAND, 12 },
		{ OPERAND, 3 },
		{ OPERAND, 4 },
		{ OPERATOR, ADD },
		{ OPERATOR, MUL },
		{ OPERAND, 6 },
		{ OPERATOR, SUB },
		{ OPERAND, 8 },
		{ OPERAND, 2 },
		{ OPERATOR, DIV },
		{ OPERATOR, ADD },
	};
	//12 3 4 + * 6 - 8 2 / +
	// 12 * 7 - 6 + 4 = 84 - 2 =82
	int size = sizeof(rpn) / sizeof(rpn[0]);
	cout << CountRPN(rpn, size) << endl;
	return 0;
}
