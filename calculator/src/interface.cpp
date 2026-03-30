#include "interface.h"
Interface::Interface() {
	std::vector<RuleFunc<int>> rules = { &multiplyDivideRule<int>, &plusMinusRule<int> };
	std::vector<ParsingFunc<int>> parsingFunc = 
	{ &parsingPlus<int>, &parsingMinus<int>, &parsingOpenBracket<int>,  &parsingCloseBracket<int>, 
	&parsingMultiply<int>, & parsingDivision<int> };
	basicCalculator_ = IntCalc(rules, parsingFunc);
}

void Interface::process() {
	std::string input;
	std::cout << "Enter expression" << '\n';
	std::getline(std::cin, input);
	auto tokens = basicCalculator_.parse(input);
	auto result = basicCalculator_.solve(*tokens, 0, tokens->size() - 1);
	if (auto* num = dynamic_cast<Number<int>*>(result.get())) {
		num->printValue();
	}
}