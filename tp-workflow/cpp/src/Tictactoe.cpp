#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
    _status = Status::RougeJoue;
}

Status Jeu::getStatus() const {
    return _status;
}

bool Jeu::isValidCase(int i, int j) const {
    return (i < Jeu::GRID_SIZE && i >= 0 && j < Jeu::GRID_SIZE && j >= 0);
}

Cell Jeu::getCell(int i, int j) const {
    if (!isValidCase(i,j)) {
        throw std::exception();
    }

    return _plateau[i][j];
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for (int i = 0; i < jeu.Jeu::GRID_SIZE ; i++) {
        for (int j = 0; j < jeu.Jeu::GRID_SIZE ; j++) {
            auto cell = jeu.getCell(i, j);
            switch (cell)
            {
            case Cell::Rouge:
                os << "R";
                break;
            case Cell::Vert:
                os << "V";
                break;
            default:
                os << ".";
                break;
            }
        }
        os << std::endl;
    }
    
    return os;
}

bool Jeu::checkVictory(Cell player) const {
    // Check Colonnes + lignes
    for (int i = 0; i < 3; i++)
    {
        if (getCell(i,0) == player && getCell(i,1) == player && getCell(i,2) == player) return true;
        if (getCell(0,i) == player && getCell(1,i) == player && getCell(2,i) == player) return true;
    }

    // Check diagonales
    if (getCell(0,0) == player && getCell(1,1) == player && getCell(2,2) == player) return true;
    if (getCell(0,2) == player && getCell(1,1) == player && getCell(2,0) == player) return true;

    return false;
}

bool Jeu::isGameFinished() const {
    return _status == Status::RougeGagne || _status == Status::VertGagne || _status == Status::Egalite; 
}

bool Jeu::checkDraw() const {
    for (int i = 0; i < Jeu::GRID_SIZE; i++)
    {
        for (int j = 0; j < Jeu::GRID_SIZE; j++)
        {
            if (getCell(i,j) == Cell::Vide) return false;
        }
    }
    
    return true;
}

bool Jeu::jouer(int i, int j) {
    if (!isValidCase(i,j)){
        return false;
    }

    auto cell = getCell(i, j);

    if (cell == Cell::Vide) {
        switch (_status)
        {
        case Status::RougeJoue:
            _plateau[i][j] = Cell::Rouge;

            if (checkVictory(Cell::Rouge)) {
                _status = Status::RougeGagne;
            } else {
                _status = Status::VertJoue;
            }
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;

            if (checkVictory(Cell::Vert)) {
                _status = Status::VertGagne;
            } else {
                _status = Status::RougeJoue;
            }
            break;
        default:
            return false;
        }

        if (!isGameFinished() && checkDraw()) {
            _status = Status::Egalite;
        }

        return true;
    }

    return false;
}

void Jeu::raz() {
    for (int i = 0; i < Jeu::GRID_SIZE ; i++) {
        _plateau[i].fill(Cell::Vide);
    }
}

