#include "Adresse.h"


Adresse::Adresse() {
    this->pays = "";
    this->ville = "";
    this->rue = "";
    this->codePostal = 0;
}

Adresse::Adresse(string pays, string ville, string rue, int codePostal) {
    this->pays = pays;
    this->ville = ville;
    this->rue = rue;
    this->codePostal = codePostal;
}

Adresse::~Adresse() {
    cout << "Destruction de l'adresse" << endl;
}

void Adresse::afficherAdresse() {
    cout << rue << ", " << ville << ", " << pays << ", " << codePostal << endl;
}

ostream &operator<<(ostream &out, Adresse &a) {
    out << a.rue << ", " << a.ville << ", " << a.pays << ", " << a.codePostal << endl;
    return out;
}

istream &operator>>(istream &in, Adresse &a) {
    cout << "Saisir les informations de l'adresse:" << endl;
    cout << "Pays: ";
    in >> a.pays;
    cout << "Ville: ";
    in >> a.ville;
    cout << "Rue: ";
    in >> a.rue;
    cout << "Code Postal: ";
    in >> a.codePostal;
    return in;
}
