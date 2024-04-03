#include <todolist-cpp/Board.hpp>

#include <catch2/catch.hpp>

TEST_CASE("Test addTodo")
{
    Board b;
    b.addTodo("Ceci est une todo de test.");

    REQUIRE(b._todo.size() == 1);
    REQUIRE(b._todo.front()._name == "Ceci est une todo de test.");
}

TEST_CASE("Test addTodos")
{
    Board b;

    for (int i = 0; i < 10; i++)
    {
        b.addTodo("Ceci est le test n°" + std::to_string(i));
    }

    REQUIRE(b._todo.size() == 10);
    REQUIRE(b._todo.back()._id == 10);
}