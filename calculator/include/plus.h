#pragma once

#include "token.h"
#include "number.h"
#include <memory>
#include <stdexcept>

template <typename T>
class Plus :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> add(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right);
};

#include "plus.tcc"