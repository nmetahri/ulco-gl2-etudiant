#pragma once

#include "Tictactoe.hpp"

class TictactoeTextInterface
{
public:
    TictactoeTextInterface() : _jeu(Jeu()){};

    void jouer();

private:
    Jeu _jeu;
};