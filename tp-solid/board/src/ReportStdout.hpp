#pragma once

#include "Board.hpp"

class ReportStdout
{
public:
    void report(const Board &board) const
    {
        for (const std::string &item : board.getItems())
            std::cout << item << std::endl;
        std::cout << std::endl;
    }
};
