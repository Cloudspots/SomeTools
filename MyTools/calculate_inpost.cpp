#include <stack>
#include <cstdio>
#include <string>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "calculate.h"

using namespace std;

_BEGIN_TOOLS

int youxian[255];

class myc
{
public:
	char type;
	int num;
	char op;
} expr[105], houexp[105];

bool isnum(const string& x)
{
	return isdigit(x[0]) || x.size() > 1 && isdigit(x[1]);
}

int getexp(stringstream& ss)
{
	int len = 0;
	string str;
	while (ss >> str)
	{
		if (isnum(str)) expr[++len] = { 'N', stoi(str), '\0' };
		else expr[++len] = { 'C', -114514, str[0] };
	}
	return len;
}

int zhong2hou(int len) //中缀转后缀
{
	youxian['('] = 1;
	youxian['+'] = youxian['-'] = 2;
	youxian['*'] = youxian['/'] = 3;
	youxian['^'] = 4;
	stack<char> oper;
	myc now;
	int cur = 0;
	for (int i = 1; i <= len; i++)
	{
		now = expr[i];
		if (now.type == 'N') //数字
		{
			houexp[++cur] = now;
			continue;
		}
		if (now.op == '(') oper.push(now.op);
		else if (now.op == ')')
		{
			while (oper.top() != '(') //连续出栈
			{
				houexp[++cur] = { 'C', -114514, oper.top() };
				oper.pop();
			}
			oper.pop(); //出栈'('
		}
		else if (oper.empty() || youxian[now.op] > youxian[oper.top()]) oper.push(now.op);
		else if (now.op == '^')
		{
			while (!oper.empty() && youxian[oper.top()] > youxian[now.op]) //连续出栈
			{
				houexp[++cur] = { 'C', -114514, oper.top() };
				oper.pop();
			}
			oper.push(now.op);
		}
		else
		{
			while (!oper.empty() && youxian[oper.top()] >= youxian[now.op]) //连续出栈
			{
				houexp[++cur] = { 'C', -114514, oper.top() };
				oper.pop();
			}
			oper.push(now.op);
		}
	}
	while (!oper.empty())
	{
		houexp[++cur] = { 'C', -114514, oper.top() };
		oper.pop();
	}
	return cur;
}

int qpow(int x, int y)
{
	int ans = 1, qwq = x;
	while (y)
	{
		if (y & 1) ans *= qwq;
		qwq *= qwq;
		y /= 2;
	}
	return ans;
}

int calc(int len)
{
	stack<int> num;
	myc now;
	for (int i = 1; i <= len; i++)
	{
		now = houexp[i];
		if (now.type == 'N') num.push(now.num);
		else
		{
			char ch = now.op;
			int x = num.top(); num.pop();
			int y = num.top(); num.pop();
			switch (ch)
			{
			case '+': num.push(x + y); break;
			case '-': num.push(y - x); break;
			case '*': num.push(x * y); break;
			case '/': num.push(y / x); break;
			case '^': num.push(qpow(y, x)); break;
			}
		}
	}
	return num.top();
}

int in_post(string str)
{
	int lkh = 0, rkh = 0, kh = 0;
	for (char ch : str)
	{
		if (ch == '(') kh++;
		if (ch == ')') kh--;
		if (kh < 0)
		{
			lkh += -kh;
			kh = 0;
		}
	}
	if (kh < 0)
	{
		lkh += -kh;
		kh = 0;
	}
	if (kh > 0)
	{
		rkh = kh;
		kh = 0;
	}
	str = string(lkh, '(') + str + string(rkh, ')');
	stringstream ss;
	//加空格，好处理。
	//如："(2+2)^(1+1)" 变为 " ( 2 + 2 )  ^  ( 1 + 1 ) "
	for (int i = 0; i < str.size(); i++)
	{
		char ch = str[i];
		bool isoperator = false;
		isoperator |= (ch == '+' || ch == '-') && i != 0 && (isdigit(str[i - 1]) || str[i - 1] == ')');
		isoperator |= ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')';
		if (isoperator) ss << ' ' << ch << ' ';
		else ss << ch;
	}
	return calc(zhong2hou(getexp(ss)));
}
_END_TOOLS