#include "Forme.hpp"
#include "cmath"

Disque::Disque(double rayon) :
    _rayon(rayon)
{}

double Disque::aire() const {
    return _rayon * 2 * M_PI;
}

Description Disque::toDescription() const {
    Description description;
    description["Nom"] = "Disque";
    description["Rayon"] = std::to_string(_rayon);

    return description;
}

Rectangle::Rectangle(double largeur, double hauteur) :
    _largeur(largeur), _hauteur(hauteur)
{}

double Rectangle::aire() const {
    return _largeur * _hauteur;
}

Description Rectangle::toDescription() const {
    Description description;
    description["Nom"] = "Rectangle";
    description["Largeur"] = std::to_string(_largeur);
    description["Hauteur"] = std::to_string(_hauteur);

    return description;
}
