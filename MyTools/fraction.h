#pragma once
#include "toolbase.h"
#include <cmath>
#include <exception>
#include <stdexcept>
#include "bigint.h"
_BEGIN_TOOLS
template<typename T = long long>
inline T gcd(T x, T y)
{
	return y ? gcd(y, x % y) : std::abs(x);
}
template<typename T = long long>
class fract
{
protected:
	T fz = 0;
	T fm = 1;
	static inline T getgcd(T x, T y) { return gcd(x, y) * (y > 0 ? 1 : -1); }
public:
	fract() noexcept : fz(0), fm(1) {};
	fract(const fract& x) noexcept : fz(x.fz), fm(x.fm) {};
	fract(fract&& x) noexcept : fz(x.fz), fm(x.fm) {};
	//x/y
	fract(T x, T y) { if (y == 0) throw std::range_error("The denominator of a fraction mustn't be zero!!\n"); long long g = getgcd(x, y); fz = x / g; fm = y / g; };
	friend fract operator+(const fract& x, const fract& y) { return { x.fz * y.fm + x.fm * y.fz, x.fm * y.fm }; }
	friend fract operator-(const fract& x, const fract& y) { return { x.fz * y.fm - x.fm * y.fz, x.fm * y.fm }; }
	friend fract operator*(const fract& x, const fract& y) { return { x.fz * y.fz, x.fm * y.fm }; }
	friend fract operator/(const fract& x, const fract& y) { return { x.fz * y.fm, x.fm * y.fz }; }
	fract& operator+=(const fract& x) { return *this = *this + x; }
	fract& operator-=(const fract& x) { return *this = *this - x; }
	fract& operator*=(const fract& x) { return *this = *this * x; }
	fract& operator/=(const fract& x) { return *this = *this / x; }
	friend fract operator-(const fract& x) { return { -x.fz, x.fm }; }
	fract& operator=(const fract& x) noexcept { fz = x.fz; fm = x.fm; return *this; }
	fract& operator=(fract&& x) noexcept { fz = x.fz; fm = x.fm; return *this; }
	T& getfz() { return fz; }
	T& getfm() { return fm; }
	const T getfz() const { return fz; }
	const T getfm() const { return fm; }

};

using bigfrac = fract<BigInt>;
_END_TOOLS