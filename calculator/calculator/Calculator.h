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
	std::unique_ptr<Token<T>> solve(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end) {
		for (size_t i = begin; i < end; ++i) {
			if (auto* braket = dynamic_cast<OpeningBracket<T>*>(tokens[i].get())) {
				size_t closingPos = findClosingBracket(tokens, i + 1);
				auto result = solve(tokens, i + 1, closingPos - 1);
				size_t closingPos2 = findClosingBracket(tokens, i + 1);
				end = end - (closingPos - closingPos2);
				tokens[i] = std::move(result);
				tokens.erase(tokens.begin() + i + 1, tokens.begin() + closingPos2 + 1);
				end = end - (closingPos2 - i);
			}
		}
		for (auto rule : rules_) {
			rule(tokens, begin, end);
		}
		if (begin < tokens.size()) {
			return std::move(tokens[begin]);
		}
		throw std::runtime_error("error in solve");
	}

private:
	std::array<ruleFunc<T>, N> rules_;
	size_t findClosingBracket(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin) {
		size_t counter = 1;
		for (size_t i = begin; i < tokens.size(); ++i) {
			if (auto* openingBracket = dynamic_cast<OpeningBracket<T>*>(tokens[i].get())) {
				counter++;
			}
			if (auto* closingBracket = dynamic_cast<ClosingBracket<T>*>(tokens[i].get())) {
				counter--;
			}
			if (counter == 0) {
				return i;
			}
		}
	}
};
