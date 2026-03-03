template<typename T>
void plusMinusRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end) {
    for (size_t i = begin + 1; i < end; ) {

        if (auto* plus = dynamic_cast<Plus<T>*>(tokens[i].get())) {
            auto result = plus->add(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
        }
        else if (auto* minus = dynamic_cast<Minus<T>*>(tokens[i].get())) {
            auto result = minus->sub(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
        }
        else {
            ++i;
        }
    }
    if ((begin - end) != 0) throw std::runtime_error("error in plusMinusRule");
}