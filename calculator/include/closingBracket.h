#pragma once

#include "token.h"

template <typename T>
class ClosingBracket :
    public Token<T>
{
};
