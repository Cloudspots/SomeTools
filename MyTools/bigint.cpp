#include "bigint.h"

using namespace std;
_BEGIN_TOOLS

Tools::BigInt operator+(Tools::BigInt x, Tools::BigInt y)
{
	x.reverse();
	y.reverse();
	while (x.size() < y.size())
	{
		x.num.push_back(0);
	}
	while (y.size() < x.size())
	{
		y.num.push_back(0);
	}
	x.reverse();
	y.reverse();
	int jw = 0;
	for (int i = x.size(); i >= 1; i--)
	{
		x[i] = x[i] + y[i] + jw;
		if (x[i] >= 10)
		{
			jw = 1;
			x[i] -= 10;
		}
		else jw = 0;
	}
	if (jw)
	{
		x.reverse();
		x.num.push_back(1);
		x.reverse();
	}
	return x;
}
Tools::BigInt operator-(Tools::BigInt x, Tools::BigInt y)
{
	if (x < y) return -(y - x);
	if (x == y) return 0;
	x.reverse();
	y.reverse();
	while (x.size() < y.size())
	{
		x.num.push_back(0);
	}
	while (y.size() < x.size())
	{
		y.num.push_back(0);
	}
	x.reverse();
	y.reverse();
	int jw = 0;
	for (int i = x.size(); i >= 1; i--)
	{
		x[i] = x[i] - y[i] + jw;
		if (x[i] < 0)
		{
			jw = -1;
			x[i] += 10;
		}
		else jw = 0;
	}
	x.reverse();
	while (x.num.back() == 0 && x.size() >= 1)
		x.num.pop_back();
	// x.num.push_back(0);
	x.reverse();
	return x;
}
Tools::BigInt operator*(Tools::BigInt x, Tools::BigInt y)
{
	//printf("operator* called.\n");
	//cout << x << "*" << y << endl;
	if (x == 0 || y == 0) return 0;
	Tools::BigInt ans = string(x.size() + y.size(), '0');
	for (int i = 1; i <= x.size(); i++)
	{
		for (int j = 1; j <= y.size(); j++)
		{
			ans[i + j - 1] += x[i] * y[j];
		}
	}
	int jw = 0;
	for (int i = ans.size(); i >= 1; i--)
	{
		ans[i] += jw;
		jw = ans[i] / 10;
		ans[i] %= 10;
	}
	ans.reverse();
	do
	{
		ans.num.push_back(jw % 10);
		jw /= 10;
	} while (jw);
	ans.reverse();
	ans.num.pop_back();
	ans.reverse();
	while (ans.num.back() == 0) ans.num.pop_back();
	ans.reverse();
	return ans;
}
Tools::BigInt operator/(Tools::BigInt x, Tools::BigInt y)
{
	if (x < y) return 0;
	if (x == y) return 1;
	Tools::BigInt ans = { 0 };
	int ind = 0;
	Tools::BigInt u = string(y) + string(x.size() - y.size() - ind, '0');
	while (u >= y)
	{
		int m = 0;
		while (x >= u)
		{
			x -= u;
			m++;
		}
		ans.num.push_back(m);
		u.num.pop_back();
	}
	ans.reverse();
	while (ans.num.back() == 0) ans.num.pop_back();
	// ans.num.push_back(0);
	ans.reverse();
	return ans;
}
bool operator< (const Tools::BigInt& x, const Tools::BigInt& y)
{
	if (x.size() != y.size()) return x.size() < y.size();
	for (int i = 1; i <= x.size(); i++)
	{
		if (x[i] != y[i]) return x[i] < y[i];
	}
	return false;
}

Tools::BigInt abs(const Tools::BigInt& x) { return x.num; }
_END_TOOLS