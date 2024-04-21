#include "Tournoi.h"
#include <map>
#include <algorithm>

Tournoi::Tournoi() {

    this->nom = "";
    this->lieu = nullptr;
    this->date = "";
    map<Style *, Competition *> competitions;

}

Tournoi::Tournoi(string nom, Adresse *lieu, string date, map<Style *, Competition *> competitions) {

    this->nom = nom;
    this->lieu = lieu;
    this->date = date;
    this->competitions = competitions;
    this->resultat = Resultat();
    map<Style *, Competition *>::iterator it;
    for (it = competitions.begin(); it != competitions.end(); it++) {
        this->resultat.ajouterGagnant(it->second->getSessions().back()->getGagnant());
    }

}

Tournoi::~Tournoi() {

    delete this->lieu;

}

string &Tournoi::getNom() {
    return this->nom;

}

string &Tournoi::getDate() {
    return this->date;
}

Adresse *Tournoi::getLieu() {
    return this->lieu;
}

Resultat Tournoi::getResultat() {
    return this->resultat;
}

void Tournoi::setNom(string &nom) {
    this->nom = nom;
}

void Tournoi::setDate(string &date) {
    this->date = date;
}

void Tournoi::setLieu(Adresse *lieu) {
    this->lieu = lieu;
}

void Tournoi::setResultat(Resultat resultat) {
    this->resultat = resultat;
}


ostream &operator<<(ostream &out, Tournoi &tournoi) {
    out << "********************* TOURNOI DE DANSE *********************" << endl;
    out << "Nom: " << tournoi.nom << endl;
    out << "Date: " << tournoi.date << endl;
    out << "Lieu: " << endl;
    out << *tournoi.lieu << endl;
    map<Style *, Competition *>::iterator it;
    for (it = tournoi.competitions.begin(); it != tournoi.competitions.end(); it++) {
        out << "********************* Competition " << it->first->getNom() << " *********************" << endl;
        out << *it->second << endl;
    }
    return out;
}

istream &operator>>(istream &in, Tournoi &tournoi) {
    cout << "Saisir les informations du tournoi:" << endl;
    cout << "Nom: ";
    in >> tournoi.nom;
    cout << "Date: ";
    in >> tournoi.date;
    cout << "Lieu: " << endl;
    Adresse *adresse = new Adresse();
    in >> *adresse;
    tournoi.lieu = adresse;

    char reponse;
    do {

        Style *style = new Style();
        in >> *style;
        Competition *competition = new Competition();
        in >> *competition;
        tournoi.competitions[style] = competition;
        tournoi.resultat.ajouterGagnant(competition->getSessions().back()->getGagnant());
        cout << "Voulez-vous ajouter une autre competition? (O/N): ";
        in >> reponse;

    } while (reponse == 'O' || reponse == 'o');
    return in;
}

Tournoi::Tournoi(const Tournoi &tournoi) {
    this->nom = tournoi.nom;
    this->lieu = tournoi.lieu;
    this->date = tournoi.date;
    this->competitions = tournoi.competitions;
    this->resultat = tournoi.resultat;

}

void Tournoi::setCompetitions(map<Style *, Competition *> competitions) {
    this->competitions = competitions;


}

map<Style *, Competition *> Tournoi::getCompetitions() {
    return this->competitions;

}


