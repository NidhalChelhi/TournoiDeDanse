#include "Tournoi.h"


// Constructors and destructors
Tournoi::Tournoi() {
    this->nom = "";
    this->lieu = new Adresse();
    this->date = "";
    this->resultat = new Resultat();
}

Tournoi::Tournoi(string nom, Adresse *lieu, string date) {
    this->nom = nom;
    this->lieu = lieu;
    this->date = date;
    this->resultat = new Resultat();
}

Tournoi::~Tournoi() {
    delete this->lieu;
    delete this->resultat;
    for (int i=0;i<competitions.size();i++) {
        delete competitions[i];
    }
    competitions.clear();
}

// Getters and setters
 string &Tournoi::getNom()  {
    return nom;
}
void Tournoi::setNom( string &nom) {
    Tournoi::nom = nom;
}
Adresse *Tournoi::getLieu()  {
    return lieu;
}
void Tournoi::setLieu(Adresse *lieu) {
    Tournoi::lieu = lieu;
}
string &Tournoi::getDate()  {
    return date;
}
void Tournoi::setDate( string &date) {
    Tournoi::date = date;
}
const vector<Competition *> &Tournoi::getCompetitions()  {
    return competitions;
}
void Tournoi::setCompetitions( vector<Competition *> &competitions) {
    Tournoi::competitions = competitions;
}

Resultat *Tournoi::getResultat()  {
    return resultat;
}
void Tournoi::setResultat(Resultat *resultat) {
    Tournoi::resultat = resultat;
}
// Overloaded operators
ostream &operator<<(ostream &out,  Tournoi &tournoi) {
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
    cout << "lieu de Tournoi : \n";
    in >> *tournoi.lieu;
    cout << "date: ";
    in >> tournoi.date;
    cout << "competitions: ";
    char rep;
    do {
        Competition *competion = new Competition();
        in >> *competion;
        tournoi.competitions.push_back(competion);
        cout << "Ajouter une autre adresse? (o/n)";
        in >> rep;
    } while (rep == 'o' || rep == 'O');
    return in;
}
/*istream &operator>>(istream &in, Tournoi &tournoi) {
    cout << "nom: ";
    in >> tournoi.nom;
    cout << "lieu: \n";
    in >> *tournoi.lieu;
    cout << "date: ";
    in >> tournoi.date;
    cout << "competitions: ";
    char rep;
    do {
        Competition *competion = new Competition();
        in >> *competion;
        tournoi.competitions.push_back(competion);
        cout << "Ajouter une autre adresse? (o/n)";
        in >> rep;
    } while (rep == 'o' || rep == 'O');
    return in;
}*/
void Tournoi::afficherResultat() {
    cout << *resultat;
}


