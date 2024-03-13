#include "Canevas.hpp"

#include <cmath>
#include <string>
#include <numeric>

void Canevas::ajouterDisque(int rayon) {
    _formes.push_back(std::make_unique<Disque>(rayon));
}

void Canevas::ajouterRectangle(int largeur, int hauteur) {
    _formes.push_back(std::make_unique<Rectangle>(largeur, hauteur));
}

double Canevas::aireTotale() const {
    double res = 0.0;
    for (const auto & f : _formes)
        res += f.get()->aire();
    return res;
}

std::vector<Description> Canevas::descriptions() const {
    std::vector<Description> descriptions;

    for (const auto &forme: Canevas::_formes) {
        descriptions.push_back(forme.get()->toDescription());
    }

    return descriptions;
}

std::vector<Description> Canevas::resume() const {
    std::vector<Description> resume;
    
    Description name;
    name["Nom"] = "Canvas";
    resume.push_back(name);

    Description aireTotale;
    aireTotale["aireTotale"] = std::to_string(Canevas::aireTotale());
    resume.push_back(aireTotale);

    return resume;
}
