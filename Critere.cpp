#include "Critere.h"

Critere::Critere() {
    libelle = "";
    coefficient = 0;
}

Critere::Critere(string libelle, int coefficient) {
    this->libelle = libelle;
    this->coefficient = coefficient;
}

Critere::~Critere() {
    // Destructor
}

ostream &operator<<(ostream &out, Critere &c) {
    out << "Libellé: " << c.libelle << endl;
    out << "Coefficient: " << c.coefficient << endl;
    return out;
}

istream &operator>>(istream &in, Critere &c) {
    cout << "Libellé: ";
    in >> c.libelle;
    cout << "Coefficient: ";
    in >> c.coefficient;
    return in;
}

