#include "Danseur.h"

// Const(s) & Dest
Danseur::Danseur() : Personne() {
    numDanseur = 0;
    age = 0;
    performances = vector<double>();
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

// Methodes
void Danseur::afficher() {
    Personne::afficher();
    cout << "Numéro de danseur: " << numDanseur << endl;
    cout << "Age: " << age << endl;
    cout << "Performances: ";
    for (int i = 0; i < performances.size(); i++) {
        cout << performances[i] << " ";
    }
    cout << endl;
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

Danseur Danseur::operator<(Danseur &d) const {
    Danseur danseurGagnant;
    if (this->performances.back() < d.performances.back()) {
        danseurGagnant = d;
    } else {
        danseurGagnant = *this;

    }
    return danseurGagnant;
}




