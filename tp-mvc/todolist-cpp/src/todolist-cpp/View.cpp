#include <todolist-cpp/View.hpp>

std::string printBoard(const Board &b)
{
    std::string str;

    str += "Todo :\n";
    for (const auto task : b._todo)
    {
        str += showTask(task) + "\n";
    }

    str += "Done :\n";

    for (const auto task : b._done)
    {
        str += showTask(task) + "\n";
    }

    return str;
}

std::string showTask(const Task &t)
{
    return std::to_string(t._id) + ". " + t._name;
}
