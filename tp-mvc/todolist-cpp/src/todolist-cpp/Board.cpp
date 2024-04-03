#include <todolist-cpp/Board.hpp>
#include <algorithm>

void Board::addTodo(const std::string &description)
{
    Task t{_nextId, description};
    _todo.push_back(t);
    _nextId++;
}

void Board::toDone(int id)
{
    const auto it = std::find_if(_todo.begin(), _todo.end(), [id](const Task &task)
                                 { return task._id == id; });

    if (it != _todo.end())
    {
        _done.push_back(*it);
        _todo.erase(it);
    }
}