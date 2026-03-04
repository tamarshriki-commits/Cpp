#pragma once
#include "Token.h"
#include "Number.h"
#include <memory>
#include <stdexcept>

template <typename T>
class Multiplication :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> multiply(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right);
};

#include "Multiplication.tcc"
