#include <todolist-cpp/Board.hpp>

void Board::addTodo(const std::string &description)
{
    Task t{_nextId, description};
    _todo.push_back(t);
    _nextId++;
}

void Board::toDone(int id)
{
    // TODO
    return;
}