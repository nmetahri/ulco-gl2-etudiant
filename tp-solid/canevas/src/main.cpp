
#include "Canevas.hpp"
#include "Export.hpp"

#include <iostream>

int main() {

    Canevas c;
    c.ajouterDisque(2);
    c.ajouterRectangle(3, 4);

    std::cout << "Aire totale : " << c.aireTotale() << std::endl;

    Export e;

    std::cout << "\n**** Resume ****" << std::endl;
    e.exportYAML(std::cout, c.resume());

    std::cout << "\n**** Descriptions ****" << std::endl;
    e.exportYAML(std::cout, c.descriptions());

    e.exportJSON(std::cout, c.descriptions());

    return 0;
}

