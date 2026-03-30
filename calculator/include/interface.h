#pragma once

#include "intCalc.h"
#include "doubleCalc.h"
#include <iostream>
class Interface
{
public:
	Interface();
	void process();
private:
	IntCalc basicCalc_;
	DoubleCalc advancedCalc_;
};

