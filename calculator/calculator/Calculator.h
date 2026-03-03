#pragma once
#include "Rules.h"
#include "ClosingBracket.h"
#include "OpeningBracket.h"
#include <stdexcept>

template <typename T, size_t N>
class Calculator
{
public:
	Calculator(const std::array<ruleFunc<T>, N>& rules) : rules_(rules) {}
	std::unique_ptr<Token<T>> solve(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end);

private:
	std::array<ruleFunc<T>, N> rules_;
	size_t findClosingBracket(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin);
};

#include "Calculator.tcc"