template<typename T>

std::unique_ptr<Token<T>> Pow<T>::raisePow(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right)
    {
        auto* leftRaw = dynamic_cast<Number<T>*>(left.get());
        auto* rightRaw = dynamic_cast<Number<T>*>(right.get());

        if (leftRaw && rightRaw) {
            return std::make_unique<Number<T>>(std::pow(leftRaw->getValue(), rightRaw->getValue()));
        }
        throw std::runtime_error("error in raisePow");
    }