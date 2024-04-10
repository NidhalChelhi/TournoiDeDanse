#include "Juge.h"
#include <cstdlib>

// Const(s) & Dest
Juge::Juge() : Personne() {
    numJuge = 0;
    experience = 0;
}

Juge::Juge(
        int cin,
        string nom,
        string prenom,
        int numJuge,
        int experience
) : Personne(cin, nom, prenom) {
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
int Juge::noterDanseur(Danseur &d, vector<Critere *> criteres) {
    int performance = 0;
    for (int i = 0; i < criteres.size(); i++) {
        int random_number = 1 + rand() % 100;
        performance += criteres[i]->getCoefficient() * random_number;
    }

    d.addPerformance(performance);

    return performance / criteres.size();

}
