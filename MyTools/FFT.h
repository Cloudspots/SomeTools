#pragma once
#include "toolbase.h"
#include <cstdio>
#include "expre.h"
_BEGIN_TOOLS
template<typename T>
expre<T> operator*(const expre<T>& x, const expre<T>& y);
_END_TOOLS