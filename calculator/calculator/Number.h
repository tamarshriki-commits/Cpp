#pragma once
#include "Token.h"
template <typename T>
class Number :
    public Token<T>
{
public:
    Number<T>(T value) : value_(value) {}
    T getValue() { return value_; }

private:
    T value_;
};

