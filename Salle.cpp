#include "Salle.h"

Salle::Salle() {
    nom = "";
    capacite = 0;
}

Salle::Salle(string nom, int capacite) {
    this->nom = nom;
    this->capacite = capacite;
}

Salle::~Salle() {
}

ostream &operator<<(ostream &os, Salle &s) {
    os << "Nom: " << s.nom << " Capacite: " << s.capacite;
    return os;
}

istream &operator>>(istream &is, Salle &s) {
    cout << "Nom: ";
    is >> s.nom;
    cout << "Capacite: ";
    is >> s.capacite;
    return is;
}

