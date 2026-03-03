#pragma once
#include "Token.h"
#include "Number.h"
#include <memory>
#include <stdexcept>

template <typename T>
class Minus :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> sub(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right);
};

#include "Minus.tcc"