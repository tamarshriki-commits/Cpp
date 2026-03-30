template<typename T>

std::unique_ptr<Token<T>> Sqrt<T>::takeRoot(std::unique_ptr<Token<T>>& right)
    {
        auto* rightRaw = dynamic_cast<Number<T>*>(right.get());

        if (rightRaw) {
            return std::make_unique<Number<T>>(std::sqrt(rightRaw->getValue()));
        }
        throw std::runtime_error("error in takeRoot");
    }