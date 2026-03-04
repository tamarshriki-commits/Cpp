#pragma once
#include "IntCalc.h"
#include <iostream>
class Interface
{
public:
	Interface();
	void process();
private:
	IntCalc basicCalculator_;
};

