#pragma once
#include "toolbase.h"
_BEGIN_TOOLS
template<typename _Input, typename _Output>
class mathfunc
{
public:
	_Output operator()(_Input x);
};
_END_TOOLS