#include "TictactoeTextInterface.hpp"

#include <sstream>

void TictactoeTextInterface::jouer() {
    int i,j;

    while (!_jeu.isGameFinished()) {
        switch (_jeu.getStatus())
        {
        case Status::RougeJoue:
            std::cout << "Rouge joue" << std::endl;
            break;
        case Status::VertJoue:
            std::cout << "Vert joue" << std::endl;
            break;
        default:
            break;
        }
        
        std::cout << std::endl << _jeu;

        std::string input, i_str, j_str;
        std::cout << "Entrez un coup (i j) : ";
        std::getline(std::cin, input);

        std::istringstream buffer(input);
        std::getline(buffer, i_str, ' ');
        std::getline(buffer, j_str, ' ');

        try {
            i = stoi(i_str);
            j = stoi(j_str);
            _jeu.jouer(i, j);
        } catch (std::invalid_argument) {
            std::cerr << "invalid input : i j" << std::endl;
            continue;
        }
    }

    std::cout << std::endl << _jeu;

    switch (_jeu.getStatus())
    {
    case Status::Egalite:
        std::cout << "Egalité !" << std::endl;
        break;
    case Status::VertGagne:
        std::cout << "Vert gagne !" << std::endl;
        break;
    case Status::RougeGagne:
        std::cout << "Rouge gagne !" << std::endl;
        break;
    default:
        std::cout << "Partie terminée !" << std::endl;
        break;
    }
}