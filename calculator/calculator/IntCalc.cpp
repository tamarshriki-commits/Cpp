#include "IntCalc.h"
std::unique_ptr<std::vector<std::unique_ptr<Token<int>>>> IntCalc::parse(std::string& input) {
	auto tokens = std::make_unique<std::vector<std::unique_ptr<Token<int>>>>();
	removeWhitespace_(input);
	for (char c : input) {
		bool isNum = true;
		for (auto parse : parsingFunc_) {
			if (auto token = parse(c)) {
				tokens->push_back(std::move(token));
				isNum = false;
				break;
			}
		}
		if (isNum) {
			int value = c - '0';
			tokens->push_back(std::make_unique<Number<int>>(value));
		}
	}
	if (auto* minus = dynamic_cast<Minus<int>*>((*tokens)[0].get())) {
		tokens->insert(tokens->begin(), std::make_unique<Number<int>>(0));
	}

	for (size_t i = 1; (i + 1) < tokens->size(); ++i) {
		auto* minus = dynamic_cast<Minus<int>*>((*tokens)[i].get());
		auto* left = dynamic_cast<Number<int>*>((*tokens)[i - 1].get());
		auto* right = dynamic_cast<Number<int>*>((*tokens)[i + 1].get());
		if (minus && !left && right) {
			tokens->insert(tokens->begin() + i, std::make_unique<OpeningBracket<int>>());
			++i;
			tokens->insert(tokens->begin() + i, std::make_unique<Number<int>>(0));
			++i;
			if (i + 3 > tokens->size()) {
				tokens->push_back(std::make_unique<ClosingBracket<int>>());
			}
			else {
				tokens->insert(tokens->begin() + i + 2, std::make_unique<ClosingBracket<int>>());
			}
		}
	}

	for (size_t i = tokens->size(); i-- > 0;) {
		auto* num = dynamic_cast<Number<int>*>((*tokens)[i].get());
		if (!num) continue;
		size_t j = 0;
		while (i > 0) {
			auto* prevNum = dynamic_cast<Number<int>*>((*tokens)[i - 1].get());
			if (!prevNum) break;
			j++;
			num->addValue(prevNum->getValue() * std::pow(10, j));
			tokens->erase(tokens->begin() + i - 1);
			i--;
		}
	}
	return std::move(tokens);
}