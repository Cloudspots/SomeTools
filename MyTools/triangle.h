#pragma once
#include "toolbase.h"
_BEGIN_TOOLS
//精度控制
constexpr long double eps = 1e-18;
//圆周率π
constexpr long double PI = 3.141592653589793238462643382795028841971693;
//=>360的角度/<0的角度 -> <360的角度
long double good_angle(long double a);
//角度->弧度
long double a2r(long double d);
//弧度->角度
long double r2a(long double r);
//sin
long double sine(long double r);
//cos
long double cosine(long double r);
//tan
long double tangent(long double r);
//cot
long double cotangent(long double r);
//sec
long double secant(long double r);
//csc
long double cosecant(long double r);
_END_TOOLS