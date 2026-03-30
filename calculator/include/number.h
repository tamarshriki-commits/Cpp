#pragma once

#include "token.h"
#include <iostream>

template <typename T>
class Number :
    public Token<T>
{
public:
    Number<T>(T value) : value_(value) {}
    T getValue() { return value_; }
    void printValue() { std::cout << value_ << '\n'; }
    void addValue(T amount) { value_ += amount; }

private:
    T value_;
};

