#pragma once
#include<iostream>
#include<stack>
#include<string>
#include<cmath>
const int MAXSIZE=50;
using namespace std;

class Calculator{
private:
	stack<int> operand_stack;//������ջ 
	stack<char> operator_stack;//������ջ 
	stack<char> operator_stack_tmp;//��ʱջ�������ַ�ת��Ϊ���� 
public:
	bool isOperator(char opt);
	char precede(char lopt,char ropt);
	int calculate(int x,char opt,int y);
	int getTop(stack<int> &s);//���������ջ����ȡջ��Ԫ����POP 
	char getTop(stack<char> &s);//��������ջ����ȡջ��Ԫ����POP 
	int toNum(stack<char> &tmp);//����ʱջ�ڵ��ַ�ת��Ϊint���� 
	int output();//������ 
}; 




