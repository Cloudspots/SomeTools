#pragma once
#include "toolbase.h"
#include "fraction.h"

_BEGIN_TOOLS

template<typename T>
T power(const T& x, const T& y);

long long power(const long long& x, const long long& y);

/*
a^b = e^(b ln a)

d/dx ln x = x^-1
d/dx x^-1 = -x^-2
d/dx -x^-2 = x^-3
d/dx x^-3 = -x^-4
(d/dx)^n ln x = (-1)^n*-x^-n

*/
_END_TOOLS