template<typename T>

std::unique_ptr<Token<T>> Plus<T>::add(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right)
    {
        auto* leftRaw = dynamic_cast<Number<T>*>(left.get());
        auto* rightRaw = dynamic_cast<Number<T>*>(right.get());

        if (leftRaw && rightRaw) {
            return std::make_unique<Number<T>>(leftRaw->getValue() + rightRaw->getValue());
        }
        throw std::runtime_error("error in plus");
    }
