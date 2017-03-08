#include"Calculator.h"

bool Calculator::isOperator(char opt)
{
	switch(opt){
		case '+':
		case '-':
		case '/':
		case '*':
		case '#':
		case '(':
		case ')':
			return true;
		default:
			return false;
	}	
} 

char Calculator::precede(char lopt,char ropt)
{
	switch(lopt){
		case '+':
		case '-':
			if(ropt=='+'||ropt=='-'||ropt==')'||ropt=='#')//#为表达式的结束符 
				return '>';
			else if(ropt=='*'||ropt=='/'||ropt=='(')
				return '<';
		case '*':
		case '/':
			if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt==')'||ropt=='#')
				return '>';
			else if(ropt=='(')
				return '<';
		case '(':
			if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='(')
				return '<';
			else if(ropt==')')
				return '=';
		case ')':
			if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt==')'||ropt=='#')
				return '>';
		case '#':
			if(ropt=='+'||ropt=='-'||ropt=='*'||ropt=='/'||ropt=='(')
				return '<';
			else if(ropt=='#')
				return '=';				
	}	
} 

int Calculator::calculate(int x,char opt,int y)
{
	switch(opt){
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':return x/y;
	}
}

int Calculator::getTop(stack<int> &s)
{
	int num=s.top();
	s.pop();
	return num;
}

char Calculator::getTop(stack<char> &s)
{
	char ch=s.top();
	s.pop();
	return ch;
}

int Calculator::toNum(stack<char> &tmp)
{
	int n=0;
	int num=0;
	while(!tmp.empty()){
		char ch=getTop(tmp);
		num+=(ch-'0')*pow(10,n++);
	}
	return num;
}

int Calculator::output()
{
	operator_stack.push('#');
	char c=getchar();
	while(c!='#'||operator_stack.top()!='#'){
		if(!isOperator(c)){
			operator_stack_tmp.push(c);//数字入临时栈 
			c=getchar();
		}else{
			if(!operator_stack_tmp.empty())
				operand_stack.push(toNum(operator_stack_tmp));
			switch(precede(operator_stack.top(),c)){
				case '<':
					operator_stack.push(c);
					c=getchar();
					break;
				case '=':
					operator_stack.pop();
					c=getchar();
					break;
				case '>':
					int x=getTop(operand_stack);
					int y=getTop(operand_stack);
					char opt=getTop(operator_stack); //运算符出栈   
					operand_stack.push(calculate(y,opt,x));
					break;
			}
		}
	}
	cout<<"result="<<getTop(operand_stack)<<endl;
}
