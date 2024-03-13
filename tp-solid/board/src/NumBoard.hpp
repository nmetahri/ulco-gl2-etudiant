#pragma once

#include "Board.hpp"

class NumBoard : public Board
{
public:
    void addNum(const std::string &t)
    {
        add((std::to_string(_id) + ". " + t));
        _id++;
    }

private:
    int _id = 1;
};