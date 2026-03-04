
template <typename T>
size_t Calculator<T>::findClosingBracket_(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin) {
		size_t unClosedBracket = 1;
		for (size_t i = begin; i < tokens.size(); ++i) {
			if (auto* openingBracket = dynamic_cast<OpeningBracket<T>*>(tokens[i].get())) {
				unClosedBracket++;
			}
			if (auto* closingBracket = dynamic_cast<ClosingBracket<T>*>(tokens[i].get())) {
				unClosedBracket--;
			}
			if (unClosedBracket == 0) {
				return i;
			}
		}
	}

template <typename T>
void Calculator<T>::removeWhitespace_(std::string& s)
	{
		s.erase(
			std::remove_if(s.begin(), s.end(), ::isspace),
			s.end()
		);
	}

template <typename T>
std::unique_ptr<Token<T>> Calculator<T>::solve(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end) {
		for (size_t i = begin; i < end; ++i) {
			if (auto* braket = dynamic_cast<OpeningBracket<T>*>(tokens[i].get())) {
				size_t closingPos = findClosingBracket_(tokens, i + 1);
				auto result = solve(tokens, i + 1, closingPos - 1);
				size_t closingPos2 = findClosingBracket_(tokens, i + 1);
				end = end - (closingPos - closingPos2);
				tokens[i] = std::move(result);
				tokens.erase(tokens.begin() + i + 1, tokens.begin() + closingPos2 + 1);
				end = end - (closingPos2 - i);
			}
		}
		size_t counter = 0;
		for (auto rule : rules_) {
			end -= counter;
			counter = rule(tokens, begin, end);
		}
		if (begin < tokens.size()) {
			return std::move(tokens[begin]);
		}
		throw std::runtime_error("error in solve");
	}