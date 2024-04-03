#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <iostream>

int main()
{
    Task t{1, "TODO"};
    std::cout << showTask(t) << std::endl;

    Board b;
    b.addTodo("First todo");
    b.addTodo("Second todo");

    std::cout << std::endl
              << printBoard(b) << std::endl;

    b.toDone(1);

    std::cout << std::endl
              << printBoard(b) << std::endl;

    return 0;
}
