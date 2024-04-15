#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("init raz constructeur")
{
    Jeu jeu;
    bool empty = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (jeu.getCell(i, j) != Cell::Vide)
            {
                empty = false;
                break;
            }
        }
    }

    REQUIRE(empty);
}

TEST_CASE("getCell valid")
{
    Jeu jeu;
    auto cell = jeu.getCell(1, 1);

    REQUIRE(cell == Cell::Vide);
}

TEST_CASE("getCell invalid")
{
    Jeu jeu;

    REQUIRE_THROWS_AS(jeu.getCell(3, 3), std::exception);
}

TEST_CASE("Affichage grille vide")
{
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    for (int i = 0; i < 3; i++)
    {
        stream << "..." << std::endl;
    }

    original_stream << jeu;

    REQUIRE(stream.str() == original_stream.str());
}

TEST_CASE("Jouer case valide affichage") {
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    jeu.jouer(1,1);

    original_stream << jeu;
    stream << "..." << std::endl << ".R." << std::endl << "..." << std::endl;

    REQUIRE(stream.str() == original_stream.str());
}

TEST_CASE("Jouer case valide") {
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    jeu.jouer(1,1);

    original_stream << jeu;
    stream << "..." << std::endl << ".R." << std::endl << "..." << std::endl;

    REQUIRE(stream.str() == original_stream.str());
}

TEST_CASE("Jouer case prise") {
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    jeu.jouer(1,1);
    REQUIRE(jeu.jouer(1,1) == false);
} 

TEST_CASE("Jouer case invalide affichage") {
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    jeu.jouer(1,1);
    jeu.jouer(1,1);

    original_stream << jeu;
    stream << "..." << std::endl << ".R." << std::endl << "..." << std::endl;

    REQUIRE(stream.str() == original_stream.str());
}


TEST_CASE("Jouer case invalide") {
    Jeu jeu;
    std::stringstream stream;
    std::stringstream original_stream;

    jeu.jouer(1,1);
    jeu.jouer(1,1);
}

TEST_CASE("Joueur rouge gagne") {
    Jeu jeu;

    jeu.jouer(0,0); // Rouge
    jeu.jouer(0,1);
    jeu.jouer(1,1); // Rouge
    jeu.jouer(0,2);
    jeu.jouer(2,2); // Rouge

    REQUIRE(jeu.getStatus() == Status::RougeGagne);
}

TEST_CASE("Joueur vert gagne") {
    Jeu jeu;

    jeu.jouer(0,1);
    jeu.jouer(0,0); // Vert
    jeu.jouer(0,2);
    jeu.jouer(1,1); // Vert
    jeu.jouer(1,2);
    jeu.jouer(2,2); // Vert

    REQUIRE(jeu.getStatus() == Status::VertGagne);
}

