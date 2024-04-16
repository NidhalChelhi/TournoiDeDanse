#include "Resultat.h"


// Constructeurs et destructeurs
Resultat::Resultat() {
}

Resultat::Resultat(vector<Danseur *> gagnants) {
    this->gagnants = gagnants;
}

Resultat::~Resultat() {
}

void Resultat::ajouterGagnant(Danseur *d) {
    gagnants.push_back(d);
}

void Resultat::afficherGagnants() {
    for (int i = 0; i < gagnants.size(); i++) {
        cout << gagnants[i]->getNom() << " " << gagnants[i]->getPrenom() << endl;
    }
}

vector<Danseur *> Resultat::getGagnants() {
    return gagnants;
}

// Setters

void Resultat::setGagnants(vector<Danseur *> gagnants) {
    this->gagnants = gagnants;
}


// Surcharge d'opérateurs

ostream &operator<<(ostream &os, const Resultat &resultat) {
    os << "Gagnants: " << endl;
    for (int i = 0; i < resultat.gagnants.size(); i++) {
        os << resultat.gagnants[i]->getNom() << " " << resultat.gagnants[i]->getPrenom() << endl;
    }
    return os;
}




