template<typename T>
size_t plusMinusRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end) {
    size_t erasedAmount = 0;
    for (size_t i = begin + 1; i < end; ) {

        if (auto* plus = dynamic_cast<Plus<T>*>(tokens[i].get())) {
            auto result = plus->add(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
            erasedAmount +=2;
        }
        else if (auto* minus = dynamic_cast<Minus<T>*>(tokens[i].get())) {
            auto result = minus->sub(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
            erasedAmount +=2;
        }
        else {
            ++i;
        }
    }
    return erasedAmount;
}

template<typename T>
size_t multiplyDivideRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end) {
    size_t erasedAmount = 0;
    for (size_t i = begin + 1; i < end; ) {

        if (auto* multiplication = dynamic_cast<Multiplication<T>*>(tokens[i].get())) {
            auto result = multiplication->multiply(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
            erasedAmount +=2;
        }
        else if (auto* division = dynamic_cast<Division<T>*>(tokens[i].get())) {
            auto result = division->divide(tokens[i - 1], tokens[i + 1]);
            tokens[i - 1] = std::move(result);

            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            end = end - 2;
            erasedAmount +=2;
        }
        else {
            ++i;
        }
    }
    return erasedAmount;
}