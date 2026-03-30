#pragma once

#include "calculator.h"
#include <cmath>
class DoubleCalc :
    public Calculator<double>
{
public:
    DoubleCalc() = default;
    DoubleCalc(const std::vector<RuleFunc<double>>& rules, const std::vector<ParsingFunc<double>>& parsingFunc)
        : Calculator(rules, parsingFunc) {
    }
    std::unique_ptr<std::vector<std::unique_ptr<Token<double>>>> parse(std::string& input) override;
};

