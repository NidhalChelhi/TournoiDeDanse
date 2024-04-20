#pragma once

#include <iostream>
#include <string>

using namespace std;

class Critere {
private:
    string libelle;
    int coefficient;

public:
    Critere();
    Critere(string libelle, int coefficient);
    Critere(const Critere &c);
    ~Critere();
    string getLibelle() { return libelle; };

    int getCoefficient() { return coefficient; };

    void setLibelle(string libelle) { this->libelle = libelle; };

    void setCoefficient(int coefficient) { this->coefficient = coefficient; };

    friend ostream &operator<<(ostream &, Critere &);

    friend istream &operator>>(istream &, Critere &);

};
