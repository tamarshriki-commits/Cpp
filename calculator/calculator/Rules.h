#pragma once
#include "Plus.h"
#include "Minus.h"
#include "Multiplication.h"
#include "Division.h"
#include <array>

template<typename T>
using RuleFunc = size_t(*)(std::vector<std::unique_ptr<Token<T>>>&, size_t, size_t);

template<typename T>
size_t plusMinusRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end);

template<typename T>
size_t multiplyDivideRule(std::vector<std::unique_ptr<Token<T>>>& tokens, size_t begin, size_t end);

#include "Rules.tcc"