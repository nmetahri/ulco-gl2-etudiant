#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/View.hpp>
#include <todolist-cpp/Task.hpp>

#include <catch2/catch.hpp>

TEST_CASE("Test show board")
{
    Board b;

    b.addTodo("Test1");
    b.addTodo("Test2");

    REQUIRE(printBoard(b) == "Todo :\n1. Test1\n2. Test2\nDone :\n");
}

TEST_CASE("showTask")
{
    std::string name = "Je m'identifie à une superbe tache.";
    Task t{1, name};
    REQUIRE(t._id == 1);
    REQUIRE(t._name == name);
    REQUIRE(showTask(t) == "1. " + name);
}
