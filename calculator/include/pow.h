#pragma once

#include "token.h"
#include "number.h"
#include <cmath>
#include <memory>
#include <stdexcept>

template <typename T>
class Pow :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> raisePow(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right);
};

#include "pow.tcc"