#pragma once

#include "plus.h"
#include "minus.h"
#include "openingBracket.h"
#include "closingBracket.h"
#include "multiplication.h"
#include "division.h"
#include "dot.h"
#include "pow.h"
#include "sqrt.h"
#include <array>

template<typename T>
using ParsingFunc = std::unique_ptr<Token<T>>(*)(char);

template<typename T>
std::unique_ptr<Token<T>> parsingPlus(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingMinus(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingOpenBracket(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingCloseBracket(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingMultiply(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingDivision(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingDot(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingPow(char c);

template<typename T>
std::unique_ptr<Token<T>> parsingSqrt(char c);

#include "parsing.tcc"