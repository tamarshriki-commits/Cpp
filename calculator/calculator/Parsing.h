#pragma once
#include "Plus.h"
#include "Minus.h"
#include "OpeningBracket.h"
#include "ClosingBracket.h"
#include "Multiplication.h"
#include "Division.h"
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

#include "Parsing.tcc"