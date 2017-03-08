#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
const int MAXSIZE=50;
using namespace std;

class Calculator{
private:
	stack<int> operand_stack;//操作数栈 
	stack<char> operator_stack;//操作符栈 
	stack<char> operator_stack_tmp;//临时栈用来将字符转换为数字 
public:
	bool isOperator(char opt);
	char precede(char lopt,char ropt);
	int calculate(int x,char opt,int y);
	int getTop(stack<int> &s);//针对运算数栈，获取栈顶元素再POP 
	char getTop(stack<char> &s);//针对运算符栈，获取栈顶元素再POP 
	int toNum(stack<char> &tmp);//将临时栈内的字符转换为int数字 
	int output();//输出结果 
}; 




