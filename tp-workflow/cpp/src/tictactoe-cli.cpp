#include "Tictactoe.hpp"
#include "TictactoeTextInterface.hpp"

#include <sstream>

using namespace std;

int main() {
    Jeu jeu;
    std::ostringstream stream;

    TictactoeTextInterface jeuTI;
    jeuTI.jouer();

    return 0;
}

