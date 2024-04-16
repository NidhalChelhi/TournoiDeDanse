#include "Juge.h"
#include <cstdlib>

// Const(s) & Dest
Juge::Juge() : Personne() {
    numJuge = 0;
    experience = 0;
}

Juge::Juge(
        int CIN,
        string nom,
        string prenom,
        int numJuge,
        int experience
) : Personne(CIN, nom, prenom) {
    this->experience = experience;
    this->numJuge = numJuge;
}

Juge::Juge(const Juge &d) : Personne(d) {
    experience = d.experience;
    numJuge = d.numJuge;
}

Juge::~Juge() {
    // Destructor
}

// Surcharge d'opérateurs
ostream &operator<<(ostream &out, Juge &d) {
    Personne *p = &d;
    out << *p;
    out << "Numéro de juge: " << d.numJuge << endl;
    out << "Expérience: " << d.experience << endl;
    return out;
}

istream &operator>>(istream &in, Juge &d) {
    Personne *p = &d;
    in >> *p;
    cout << "Numéro de juge: ";
    in >> d.numJuge;
    cout << "Expérience: ";
    in >> d.experience;
    return in;
}

// Methodes
void Juge::noterDanseur(Danseur &d, vector<Critere *> criteres) {
    cout << "Noter " << d.getFullName() << ": (doit etre entre 0 et 10): " << endl;
    int performance = 0;
    for (int i = 0; i < criteres.size(); i++) {
        int note = 0;
        cout << criteres[i]->getLibelle() << "= ";
        cin >> note;

        performance += criteres[i]->getCoefficient() * note;
    }
    d.addPerformance((double) performance / criteres.size());
}

void Juge::afficher() {
    cout << "Juge: " << endl;
    Personne::afficher();
    cout << "Numéro de juge: " << numJuge << endl;
    cout << "Expérience: " << experience << endl;
}
