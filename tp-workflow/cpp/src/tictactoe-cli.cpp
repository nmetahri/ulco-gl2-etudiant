#include "Tictactoe.hpp"

#include <sstream>

using namespace std;

int main() {
    Jeu jeu;
    std::ostringstream stream;

    std::cout << jeu;

    jeu.jouer(0,0); // Rouge
    jeu.jouer(0,1);
    jeu.jouer(1,1); // Rouge
    jeu.jouer(0,2);
    jeu.jouer(2,2); // Rouge

    std::cout << jeu;

    return 0;
}

