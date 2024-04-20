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
    // Destructor
}

ostream &operator<<(ostream &out, Adresse &a) {
    out << "Pays: " << a.pays << ", Ville: " << a.ville << ", Rue: " << a.rue << ", Code Postal: " << a.codePostal
        << endl;
    return out;
}

istream &operator>>(istream &in, Adresse &a) {
    cout << "__Saisie d'une adresse__ \n";
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
