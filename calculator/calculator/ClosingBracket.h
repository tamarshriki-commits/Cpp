#pragma once
#include "Token.h"

template <typename T>
class ClosingBracket :
    public Token<T>
{
};
