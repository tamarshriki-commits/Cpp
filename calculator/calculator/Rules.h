#pragma once
#include "Plus.h"
#include "Minus.h"
#include <array>

template<typename T>
using ruleFunc = void(*)(std::vector<std::unique_ptr<Token<T>>>&, size_t, size_t);

template<typename T>
void plusMinusRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end);

#include "Rules.tcc"