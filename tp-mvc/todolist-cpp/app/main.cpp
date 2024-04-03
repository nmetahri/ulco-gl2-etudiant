#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <iostream>

int main()
{
    Board b;
    b.addTodo("Réviser l'examen de réseaux");
    b.addTodo("afficher un board");

    b.toDone(2);

    std::cout << std::endl
              << printBoard(b) << std::endl;

    return 0;
}
