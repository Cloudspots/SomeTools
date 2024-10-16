#include "lglrcz.h"

using namespace std;

_BEGIN_TOOLS

string lglrcz(vector<pair<double, double>> points)
{
	int n = points.size();
	string ans;
	for (int i = 0; i < points.size(); i++)
	{
		if (i != 0) ans += '+';
		ans += to_string(points[i].second);
		ans += " \\times \\frac{";
		for (int j = 0; j < points.size(); j++)
		{
			if (i == j) continue;
			ans += "(x"s + " - "s + to_string(points[j].first) + ")"s;
		}
		ans += "}{";
		for (int j = 0; j < points.size(); j++)
		{
			if (i == j) continue;
			ans += "("s + to_string(points[i].first) + " - "s + to_string(points[j].first) + ")"s;
		}
		ans += "}";
	}
	return ans;
}
_END_TOOLS