#pragma once
#include "Calculator.h"
#include <cmath>
class IntCalc :
    public Calculator<int>
{
public:
    IntCalc() = default;
    IntCalc(const std::vector<RuleFunc<int>>& rules, const std::vector<ParsingFunc<int>>& parsingFunc)
        : Calculator(rules, parsingFunc) { }
    std::unique_ptr<std::vector<std::unique_ptr<Token<int>>>> parse(std::string& input) override;
};

