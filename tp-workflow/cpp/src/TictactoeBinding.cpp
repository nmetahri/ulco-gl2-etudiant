#include "Tictactoe.hpp"

#include <pybind11/pybind11.h>

PYBIND11_MODULE(tictactoe, m) {
        
    pybind11::enum_<Cell>(m, "Cell")
        .value("Vide", Cell::Vide)
        .value("Rouge", Cell::Rouge)
        .value("Vert", Cell::Vert)
        ;

    pybind11::enum_<Status>(m, "Status")
        .value("Rouge joue", Status::RougeJoue)
        .value("Vert joue", Status::VertJoue)
        .value("Rouge gagne", Status::RougeGagne)
        .value("Vert gagne", Status::VertGagne)
        .value("Egalité", Status::Egalite);

    pybind11::class_<Jeu>(m, "Jeu")
        .def(pybind11::init<>())
        .def("getStatus", &Jeu::getStatus)
        .def("isGameFinished", &Jeu::isGameFinished)
        .def("jouer", &Jeu::jouer)
        .def("getCell", &Jeu::getCell)
        // TODO ...
        ;

}

