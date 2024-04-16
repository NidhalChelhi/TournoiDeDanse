#include "Tournoi.h"


// Constructors and destructors
Tournoi::Tournoi() {
    this->nom = "";
    this->lieu = new Adresse();
    this->date = "";
    this->competitions = vector<Competition *>();
    this->resultat = new Resultat();
}

Tournoi::Tournoi(string nom, Adresse *lieu, string date) {
    this->nom = nom;
    this->lieu = lieu;
    this->date = date;
    this->competitions = vector<Competition *>();
    this->resultat = new Resultat();
}

Tournoi::~Tournoi() {
    delete this->lieu;
    delete this->resultat;
    for (Competition *competition: this->competitions) {
        delete competition;
    }
}

// Getters and setters

const string &Tournoi::getNom() const {
    return nom;
}

void Tournoi::setNom(const string &nom) {
    Tournoi::nom = nom;
}

Adresse *Tournoi::getLieu() const {
    return lieu;
}

void Tournoi::setLieu(Adresse *lieu) {
    Tournoi::lieu = lieu;
}

const string &Tournoi::getDate() const {
    return date;
}

void Tournoi::setDate(const string &date) {
    Tournoi::date = date;
}

const vector<Competition *> &Tournoi::getCompetitions() const {
    return competitions;
}

void Tournoi::setCompetitions(const vector<Competition *> &competitions) {
    Tournoi::competitions = competitions;
}

Resultat *Tournoi::getResultat() const {
    return resultat;
}

void Tournoi::setResultat(Resultat *resultat) {
    Tournoi::resultat = resultat;
}

// Overloaded operators


ostream &operator<<(ostream &out, const Tournoi &tournoi) {
    out << "nom: " << tournoi.nom << " lieu: " << *tournoi.lieu << " date: " << tournoi.date << " competitions: ";
    for (Competition *competition: tournoi.competitions) {
        out << *competition << " ";
    }
    cout << "resultat: " << *tournoi.resultat;
    return out;
}

istream &operator>>(istream &in, Tournoi &tournoi) {
    cout << "nom: ";
    in >> tournoi.nom;
    cout << "lieu: ";
    in >> *tournoi.lieu;
    cout << "date: ";
    in >> tournoi.date;
    cout << "competitions: ";
    for (Competition *competition: tournoi.competitions) {
        in >> *competition;
    }

    return in;
}


