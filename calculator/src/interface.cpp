#include "interface.h"
Interface::Interface() {
	std::vector<RuleFunc<int>> rulesBasic = { &multiplyDivideRule<int>, &plusMinusRule<int> };
	std::vector<ParsingFunc<int>> parsingFuncBasic =
	{ &parsingPlus<int>, &parsingMinus<int>, &parsingOpenBracket<int>,  &parsingCloseBracket<int>,
	&parsingMultiply<int>, &parsingDivision<int>};
	basicCalc_ = IntCalc(rulesBasic, parsingFuncBasic);
	std::vector<RuleFunc<double>> rulesAdvanced = { &powSqrtRule<double>, &multiplyDivideRule<double>, &plusMinusRule<double> };
	std::vector<ParsingFunc<double>> parsingFuncAdvanced =
	{ &parsingPlus<double>, &parsingMinus<double>, &parsingOpenBracket<double>,  &parsingCloseBracket<double>,
	&parsingMultiply<double>, &parsingDivision<double>, &parsingDot<double>, &parsingPow<double>, &parsingSqrt<double>};
	advancedCalc_ = DoubleCalc(rulesAdvanced, parsingFuncAdvanced);
}

void Interface::process() {
	std::string input;
	while (true) {
		std::cout << "Choose calculator" << '\n';
		std::getline(std::cin, input);
		if (input == "1") {
			while (true) {
				std::cout << "Enter expression" << '\n';
				std::getline(std::cin, input);
				if (input == "0") break;
				auto tokens = basicCalc_.parse(input);
				auto result = basicCalc_.solve(*tokens, 0, tokens->size() - 1);
				if (auto* num = dynamic_cast<Number<int>*>(result.get())) {
					num->printValue();
				}
			}
		}
		if (input == "2") {
			while (true) {
				std::cout << "Enter expression" << '\n';
				std::getline(std::cin, input);
				if (input == "0") break;
				auto tokens = advancedCalc_.parse(input);
				auto result = advancedCalc_.solve(*tokens, 0, tokens->size() - 1);
				if (auto* num = dynamic_cast<Number<double>*>(result.get())) {
					num->printValue();
				}
			}
		}
	}
}