#include "calculate.h"
#include <cctype>

using namespace std;

_BEGIN_TOOLS

class node
{
public:
	char type;
	int num;
	char op;
	node* l, * r;
};

void gettree(node *root, string str)
{
	int minn = 2147483647;
	int pt = 0;
	for (char ch : str)
	{
		if (ch == '(') pt++;
		else if (ch == ')') pt--;
		else if (pt < minn) minn = pt;
	}
	if(minn) gettree(root, str.substr(minn, str.size() - 2 * minn));
	else
	{
		int khr = 0;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] == ')') khr++;
			if (str[i] == '(') khr--;
			if (khr == 0 && ((str[i] == '+' || str[i] == '-') && i > 0 && (isdigit(str[i-1]) || str[i-1] == ')') || str[i] == '*' || str[i] == '/'))
			{
				root->type = 'O';
				root->op = str[i];
				gettree(root->l = new node, str.substr(0, i));
				gettree(root->r = new node, str.substr(i + 1));
				return;
			}
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(') khr++;
			if (str[i] == ')') khr--;
			if (khr == 0 && str[i] == '^')
			{
				root->type = 'O';
				root->op = str[i];
				gettree(root->l = new node, str.substr(0, i));
				gettree(root->r = new node, str.substr(i + 1));
				return;
			}
		}
		root->type = 'N';
		root->num = stoi(str);
		root->l = root->r = nullptr;
	}
}

static int qpow(int x, int y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	int g = qpow(x, y/2);
	return g * g * ((y & 1) ? x : 1);
}

int calc(node* root)
{
	if (root->type == 'N') return root->num;
	switch (root->op)
	{
	case '+': return calc(root->l) + calc(root->r); break;
	case '-': return calc(root->l) - calc(root->r); break;
	case '*': return calc(root->l) * calc(root->r); break;
	case '/': return calc(root->l) / calc(root->r); break;
	case '^': return qpow(calc(root->l), calc(root->r)); break;
	}
}

int exp_tree(string str)
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
	node* root = new node;
	gettree(root, str);
	return calc(root);
}
_END_TOOLS