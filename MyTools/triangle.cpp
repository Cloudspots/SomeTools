#include "triangle.h"
_BEGIN_TOOLS
long double good_angle(long double a) { return (a + 360) - int((a + 360) / 360) * 360; };
long double a2r(long double a) { return good_angle(a) * PI / 180; }
long double r2a(long double r) { return good_angle(r * 180 / PI); }
long double sine(long double r)
{
	long double e = r, ans = 0;
	for (int i = 2; (e > 0 ? e : -e) > eps; i += 2)
	{
		ans += e;
		e = -(e * r * r / i / (i + 1));
	}
	return ans;
}
long double cosine(long double r)
{
	long double e = 1, ans = 0;
	for (int i = 1; (e > 0 ? e : -e) > eps; i += 2)
	{
		ans += e;
		e = -(e * r * r / i / (i + 1));
	}
	return ans;
}
long double tangent(long double r) { return sine(r) / cosine(r); }
long double cotangent(long double r) { return 1 / tangent(r); }
long double secant(long double r) { return 1 / cosine(r); }
long double cosecant(long double r) { return 1 / sine(r); }
_END_TOOLS