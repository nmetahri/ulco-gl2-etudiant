#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE("test 1")
{
    Task t{1, "TODO"};
    REQUIRE(t._id == 1);
    REQUIRE(t._name == "TODO");
}

TEST_CASE("showTask")
{
    std::string name = "Je m'identifie à une superbe tache.";
    Task t{1, name};
    REQUIRE(t._id == 1);
    REQUIRE(t._name == name);
    REQUIRE(showTask(t) == "1. " + name);
}
