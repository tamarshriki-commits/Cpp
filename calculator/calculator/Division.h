#pragma once
#include "Token.h"
#include "Number.h"
#include <memory>
#include <stdexcept>

template <typename T>
class Division :
    public Token<T>
{
public:
    std::unique_ptr<Token<T>> divide(std::unique_ptr<Token<T>>& left,
        std::unique_ptr<Token<T>>& right);
};

#include "Division.tcc"
