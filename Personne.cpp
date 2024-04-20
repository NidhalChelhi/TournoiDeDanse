#include "Personne.h"
#include "Adresse.h"

int Personne::nbPersonnes = 0;
Personne::Personne() {
    this->CIN = 0;
    this->nom = "";
    this->prenom = "";
    nbPersonnes++;
}
Personne::Personne(int CIN, string nom, string prenom) {
    this->CIN = CIN;
    this->nom = nom;
    this->prenom = prenom;
    nbPersonnes++;
}
Personne::Personne(const Personne &p) {
    this->CIN = p.CIN;
    this->nom = p.nom;
    this->prenom = p.prenom;
    this->adresses = p.adresses;
    nbPersonnes++;
}
Personne::~Personne() {
    for (Adresse *adresse: adresses) {
        delete adresse;
    };
    adresses.clear();
}
void Personne::afficher() {
    cout << "CIN: ";
    cout << CIN << endl;
    cout << "Nom Complet: ";
    cout << nom << " " << prenom << endl;
    cout << "Adresses: " << endl;
    for (int i = 0; i < (int) adresses.size(); i++) {
        cout << i + 1 << ") " << *adresses[i];
    }
}
ostream &operator<<(ostream &out, Personne &p) {
    out << "CIN: ";
    out << p.CIN << endl;
    out << "Nom Complet: ";
    out << p.nom << " " << p.prenom << endl;
    out << "Adresses: " << endl;
    for (int i = 0; i < (int) p.adresses.size(); i++) {
        out << i + 1 << ") " << *p.adresses[i];
    }
    return out;
}

istream &operator>>(istream &in, Personne &p) {
    cout << "CIN:";
    in >> p.CIN;
    cout << "Prenom:";
    in >> p.prenom;
    cout << "Nom:";
    in >> p.nom;
    char rep;
    do {
        Adresse *adresse = new Adresse();
        in >> *adresse;
        p.adresses.push_back(adresse);
       cout << "Ajouter une autre adresse? (o/n)";
        in >> rep;
    } while (rep == 'o'|| rep=='O');
    Personne::nbPersonnes++;
    return in;
}

void Personne::estCompetant() {
    cout<<"Je suis simple spectateur :)"<<endl;
}


