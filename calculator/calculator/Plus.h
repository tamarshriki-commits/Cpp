#pragma once
#include "Token.h"
#include "Number.h"
#include <memory>
template <typename T>
class Plus :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> add(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right)
    {
        auto* leftRaw = dynamic_cast<Number<T>*>(left.get());
        auto* rightRaw = dynamic_cast<Number<T>*>(right.get());

        if (leftRaw && rightRaw) {
            return std::make_unique<Number<T>>(leftRaw->getValue() + rightRaw->getValue());
        }
        return nullptr;
    }
};

