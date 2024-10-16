#pragma once
#include "toolbase.h"
#define _DEC
#include <vector>
#include <string>
#include <iostream>
_BEGIN_TOOLS

class BigInt //高精度类
{
public:
	std::vector<int> num = { 0 };
	bool fushu = false;
	BigInt() { num.push_back(0); }
	BigInt(const BigInt& x) : num(x.num), fushu(x.fushu) {}
	BigInt(const std::string& x) { std::string kk = x; if (x[0] == '-') { fushu = true; kk = x.substr(1, x.size() - 1); } for (auto ch : kk) { num.push_back(ch - '0'); } }
	BigInt(const long long& x) : BigInt(std::to_string(x)) {}
	BigInt(const std::vector<int>& x) : num(x) { reverse(); num.push_back(0); reverse(); }
	int size() const { return num.size() - 1; }
	void reverse() { std::reverse(num.begin() + 1, num.end()); }
	operator std::string() { std::string res; if (fushu) res = ' '; for (int i = 1; i <= size(); i++) { res += char(num[i] + '0'); } return res; }
	operator std::vector<int>() { return num; }
	int& operator[](int id) { return num[id]; }
	int operator[](int id) const { return num[id]; }
	const BigInt& operator=(const BigInt& x) { num = x.num; fushu = x.fushu; return *this; }
	const BigInt& operator=(const std::string& x) { *this = BigInt(x); return *this; }
	const BigInt& operator=(const long long& x) { *this = BigInt(x); return *this; }
	const BigInt& operator=(const std::vector<int>& x) { *this = BigInt(x); return *this; }
	friend const BigInt& operator+=(BigInt& x, const BigInt& y) { x = x + y; return x; }
	friend const BigInt& operator-=(BigInt& x, const BigInt& y) { x = x - y; return x; }
	friend const BigInt& operator*=(BigInt& x, const BigInt& y) { x = x * y; return x; }
	friend const BigInt& operator/=(BigInt& x, const BigInt& y) { x = x / y; return x; }
	friend const BigInt& operator%=(BigInt& x, const BigInt& y) { x = x % y; return x; }
	friend const BigInt& operator+=(BigInt& x, int y) { x += BigInt(y); return x; }
	friend const BigInt& operator-=(BigInt& x, int y) { x -= BigInt(y); return x; }
	friend const BigInt& operator*=(BigInt& x, int y) { x *= BigInt(y); return x; }
	friend const BigInt& operator/=(BigInt& x, int y) { x /= BigInt(y); return x; }
	friend const BigInt& operator%=(BigInt& x, int y) { x %= BigInt(y); return x; }
	friend std::istream& operator>>(std::istream& is, BigInt& u) { std::string s; is >> s; u = s; return is; }
	friend std::ostream& operator<<(std::ostream& os, const BigInt& u) { if (u.fushu) os << '-'; for (int i = 1; i <= u.size(); i++) { os << u[i]; } if (u.size() == 0) os << '0'; return os; };
	friend BigInt operator+(BigInt, BigInt);
	friend BigInt operator-(BigInt, BigInt);
	friend BigInt operator*(BigInt, BigInt);
	friend BigInt operator/(BigInt, BigInt);
	friend BigInt operator%(BigInt x, BigInt y) { return x - x / y * y; }
	friend BigInt operator+(BigInt x, int y) { return x + BigInt(y); }
	friend BigInt operator-(BigInt x, int y) { return x - BigInt(y); }
	friend BigInt operator*(BigInt x, int y) { return x * BigInt(y); }
	friend BigInt operator/(BigInt x, int y) { return x / BigInt(y); }
	friend BigInt operator%(BigInt x, int y) { return x % BigInt(y); }
	friend BigInt operator-(BigInt x) { BigInt y = x; y.fushu ^= 1; return y; }
};
bool operator< (const BigInt& x, const BigInt& y);
bool operator==(const BigInt& x, const BigInt& y) { return x.num == y.num; };
bool operator<=(const BigInt& x, const BigInt& y) { return x < y || x == y; };
bool operator!=(const BigInt& x, const BigInt& y) { return !(x == y); };
bool operator>=(const BigInt& x, const BigInt& y) { return !(x < y); };
bool operator> (const BigInt& x, const BigInt& y) { return !(x <= y); };
bool operator< (const BigInt& x, const int& y) { return x < BigInt(y); };
bool operator<=(const BigInt& x, const int& y) { return x < y || x == BigInt(y); };
bool operator==(const BigInt& x, const int& y) { return x == BigInt(y); };
bool operator!=(const BigInt& x, const int& y) { return !(x == y); };
bool operator>=(const BigInt& x, const int& y) { return !(x < y); };
bool operator> (const BigInt& x, const int& y) { return !(x <= y); };

BigInt abs(const BigInt& x);
_END_TOOLS