#pragma once

#include "Board.hpp"

class Reportable
{
public:
    virtual void report(const Board &board) = 0;
};