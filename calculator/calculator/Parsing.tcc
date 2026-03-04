template<typename T>
std::unique_ptr<Token<T>> parsingPlus(char c) {
	if (c == '+') {
		return std::make_unique<Plus<T>>();
	}
	else return nullptr;
}

template<typename T>
std::unique_ptr<Token<T>> parsingMinus(char c) {
	if (c == '-') {
		return std::make_unique<Minus<T>>();
	}
	else return nullptr;
}

template<typename T>
std::unique_ptr<Token<T>> parsingOpenBracket(char c) {
	if (c == '(') {
		return std::make_unique<OpeningBracket<T>>();
	}
	else return nullptr;
}

template<typename T>
std::unique_ptr<Token<T>> parsingCloseBracket(char c) {
	if (c == ')') {
		return std::make_unique<ClosingBracket<T>>();
	}
	else return nullptr;
}

template<typename T>
std::unique_ptr<Token<T>> parsingMultiply(char c) {
	if (c == '*') {
		return std::make_unique<Multiplication<T>>();
	}
	else return nullptr;
}

template<typename T>
std::unique_ptr<Token<T>> parsingDivision(char c) {
	if (c == '/') {
		return std::make_unique<Division<T>>();
	}
	else return nullptr;
}