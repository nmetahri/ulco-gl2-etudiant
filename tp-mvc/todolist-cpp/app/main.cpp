#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <iostream>
#include <sstream>

int main()
{
    Board b;

    std::string input, cmd, rst;
    while (input != "quit")
    {
        std::getline(std::cin, input);

        std::istringstream iss(input);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);

        if (cmd == "add")
        {
            b.addTodo(rst);
        }

        if (cmd == "done")
        {
            try
            {
                int id = stoi(rst);
                b.toDone(stoi(rst));
            }
            catch (...)
            {
                std::cerr << "Invalid ID !" << std::endl;
            }
        }

        std::cout << printBoard(b) << std::endl;
    }

    return 0;
}
