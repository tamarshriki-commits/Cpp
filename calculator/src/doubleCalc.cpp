#include "doubleCalc.h"
std::unique_ptr<std::vector<std::unique_ptr<Token<double>>>> DoubleCalc::parse(std::string& input) {
	auto tokens = std::make_unique<std::vector<std::unique_ptr<Token<double>>>>();
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
			tokens->push_back(std::make_unique<Number<double>>(value));
		}
	}

	for (size_t i = 0; i + 1 < tokens->size(); ) {
		auto* num = dynamic_cast<Number<double>*>((*tokens)[i].get());
		if (!num) {
			i++;
			continue;
		}
		auto* dot = dynamic_cast<Dot<double>*>((*tokens)[i + 1].get());
		if (!dot) {
			i++;
			continue;
		}
		tokens->erase(tokens->begin() + i + 1);
		int j = 0;
		while (i + 1 < tokens->size()) {
			auto* nextNum = dynamic_cast<Number<double>*>((*tokens)[i + 1].get());
			if (!nextNum) break;
			j++;
			num->addValue(nextNum->getValue() * std::pow(10.0, -j));
			tokens->erase(tokens->begin() + i + 1);
		}
		i++;
	}

	for (size_t i = tokens->size(); i-- > 0;) {
		auto* num = dynamic_cast<Number<double>*>((*tokens)[i].get());
		if (!num) continue;
		size_t j = 0;
		while (i > 0) {
			auto* prevNum = dynamic_cast<Number<double>*>((*tokens)[i - 1].get());
			if (!prevNum) break;
			j++;
			num->addValue(prevNum->getValue() * std::pow(10, j));
			tokens->erase(tokens->begin() + i - 1);
			i--;
		}
	}

	if (auto* minus = dynamic_cast<Minus<double>*>((*tokens)[0].get())) {
		tokens->insert(tokens->begin(), std::make_unique<Number<double>>(0));
	}

	for (size_t i = 1; (i + 1) < tokens->size(); ++i) {
		auto* minus = dynamic_cast<Minus<double>*>((*tokens)[i].get());
		auto* left = dynamic_cast<Number<double>*>((*tokens)[i - 1].get());
		auto* right = dynamic_cast<Number<double>*>((*tokens)[i + 1].get());
		if (minus && !left && right) {
			tokens->insert(tokens->begin() + i, std::make_unique<OpeningBracket<double>>());
			++i;
			tokens->insert(tokens->begin() + i, std::make_unique<Number<double>>(0));
			++i;
			if (i + 3 > tokens->size()) {
				tokens->push_back(std::make_unique<ClosingBracket<double>>());
			}
			else {
				tokens->insert(tokens->begin() + i + 2, std::make_unique<ClosingBracket<double>>());
			}
		}
	}
	return std::move(tokens);
}