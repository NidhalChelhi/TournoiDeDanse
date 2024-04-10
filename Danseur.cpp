#include "Danseur.h"

// Const(s) & Dest
Danseur::Danseur() : Personne() {
    numDanseur = 0;
    age = 0;
    performances = {};

}

Danseur::Danseur(int cin, string nom, string prenom, int numDanseur, int age) : Personne(cin, nom, prenom) {
    this->numDanseur = numDanseur;
    this->age = age;
}

Danseur::Danseur(const Danseur &d) : Personne(d) {
    age = d.age;
    numDanseur = d.numDanseur;
    performances = d.performances;
}

Danseur::~Danseur() {
    performances.clear();
}


// Surcharge d'opérateurs
ostream &operator<<(ostream &out, Danseur &d) {
    Personne *p = &d;
    out << *p;
    out << "Numéro de danseur: " << d.numDanseur << endl;
    out << "Age: " << d.age << endl;
    return out;
}

istream &operator>>(istream &in, Danseur &d) {
    Personne *p = &d;
    in >> *p;
    cout << "Numéro de danseur: ";
    in >> d.numDanseur;
    cout << "Age: ";
    in >> d.age;
    return in;
}




