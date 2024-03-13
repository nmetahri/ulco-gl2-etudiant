#pragma once

#include "Descriptible.hpp"

class Forme : public Descriptible {
    public:
        virtual ~Forme() = default;
        virtual double aire() const = 0;
};

class Disque : public Forme {
    public:
        Disque(double rayon);
        double aire() const override;
        Description toDescription() const override;
    private:
        double _rayon;
};

class Rectangle : public Forme {
    public:
        Rectangle(double largeur, double hauteur);
        double aire() const override;
        Description toDescription() const override;
    private:
        double _largeur;
        double _hauteur;

};

