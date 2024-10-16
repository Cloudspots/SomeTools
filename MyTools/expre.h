#pragma once
#include "toolbase.h"
#include <vector>
#include "bigint.h"
_BEGIN_TOOLS
template<typename T>
class expre
{
public:
	std::vector<T> as;
	template<typename T> friend expre<T> operator+(expre<T>& x, expre<T>& y);
	template<typename T> friend expre<T> operator-(expre<T>& x, expre<T>& y);
	template<typename T> friend expre<T> operator*(expre<T>& x, expre<T>& y);
	template<typename T> friend expre<T> operator/(expre<T>& x, expre<T>& y);
};

using bigexpr = expre<BigInt>;
_END_TOOLS