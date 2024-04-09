#include "Personne.h"
#include "Adresse.h"


Personne::Personne() {
    this->cin = 0;
    this->nom = "";
    this->prenom = "";
}

Personne::Personne(int cin, string nom, string prenom) {
    this->cin = cin;
    this->nom = nom;
    this->prenom = prenom;
}

Personne::Personne(const Personne &p) {
    this->cin = p.cin;
    this->nom = p.nom;
    this->prenom = p.prenom;
    this->adresses = p.adresses;
}

Personne::~Personne() {
    cout << "Destruction de la personne" << endl;
}

void Personne::afficherDetails() {
    cout << "CIN: " << cin << ", Nom: " << nom << ", Prénom: " << prenom << endl;
    cout << "Adresses: " << endl;
    for (Adresse *adresse: adresses) {
        adresse->afficherAdresse();
    }
}

ostream &operator<<(ostream &out, Personne &p) {
    out << "CIN: ";
    out << p.cin << endl;
    out << "Nom: ";
    out << p.nom << endl;
    out << "Prénom: ";
    out << p.prenom << endl;
    out << "Adresses: " << endl;
    for (int i = 0; i < (int) p.adresses.size(); i++) {
        out << i+1 << ") " << *p.adresses[i];
    }
    return out;


}

istream &operator>>(istream &in, Personne &p) {
    cout << "Saisir les informations de la personne:" << endl;
    cout << "CIN: ";
    in >> p.cin;
    cout << "Nom: ";
    in >> p.nom;
    cout << "Prénom: ";
    in >> p.prenom;
    char rep;
    do {
        Adresse *adresse = new Adresse();
        in >> *adresse;
        p.adresses.push_back(adresse);
        cout << "Ajouter une autre adresse? (o/n)";
        in >> rep;
    } while (rep == 'o');
    return in;


}
