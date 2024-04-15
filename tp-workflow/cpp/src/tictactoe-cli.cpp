#include "Tictactoe.hpp"

#include <sstream>

using namespace std;

int main() {
    Jeu jeu;
    std::ostringstream stream;

    std::cout << jeu;

    jeu.jouer(0,1);

    std::cout << jeu;

    return 0;
}

