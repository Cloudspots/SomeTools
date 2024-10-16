#pragma once
#include "toolbase.h"
_BEGIN_TOOLS
//���ȿ���
constexpr long double eps = 1e-18;
//Բ���ʦ�
constexpr long double PI = 3.141592653589793238462643382795028841971693;
//=>360�ĽǶ�/<0�ĽǶ� -> <360�ĽǶ�
long double good_angle(long double a);
//�Ƕ�->����
long double a2r(long double d);
//����->�Ƕ�
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