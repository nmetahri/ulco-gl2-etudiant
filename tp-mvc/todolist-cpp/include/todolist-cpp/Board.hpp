#pragma once

#include <todolist-cpp/Task.hpp>
#include <iostream>
#include <list>

class Board
{
public:
    Board() : _nextId(1){};

    void addTodo(const std::string &description);
    void toDone(int id);

    std::list<Task> _todo;
    std::list<Task> _done;

private:
    int _nextId;
};
