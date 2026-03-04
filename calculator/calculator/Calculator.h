#pragma once
#include "Rules.h"
#include "Parsing.h"
#include "ClosingBracket.h"
#include "OpeningBracket.h"
#include <stdexcept>
#include <string>

template <typename T>
class Calculator
{
public:
	Calculator() = default;
	Calculator(const std::vector<RuleFunc<T>>& rules, const std::vector<ParsingFunc<T>>& parsingFunc)
		: rules_(rules), parsingFunc_(parsingFunc) {}
	virtual std::unique_ptr<std::vector<std::unique_ptr<Token<T>>>> parse(std::string& input) = 0;
	std::unique_ptr<Token<T>> solve(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end);

protected:
	std::vector<ParsingFunc<T>> parsingFunc_;
	std::vector<RuleFunc<T>> rules_;
	void removeWhitespace_(std::string& s);
	size_t findClosingBracket_(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin);
};

#include "Calculator.tcc"