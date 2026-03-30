#pragma once

#include "token.h"
#include "number.h"
#include <cmath>
#include <memory>
#include <stdexcept>

template <typename T>
class Sqrt :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> takeRoot(std::unique_ptr<Token<T>>& right);
};

#include "sqrt.tcc"