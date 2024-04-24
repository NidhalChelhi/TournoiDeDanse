
#include "Adresse.h"
#include "Competition.h"
#include "Resultat.h"
#include<map>
#include "Style.h"
#include <algorithm>

class Tournoi {

private:
    string nom;
    Adresse *lieu;
    string date;
    map<Style *, Competition *> competitions;
    Resultat resultat;

public:


    Tournoi();

    Tournoi(string nom, Adresse *lieu, string date, map<Style *, Competition *> competitions);

    Tournoi(const Tournoi &tournoi);

    ~Tournoi();

    string &getNom();

    string &getDate();

    Adresse *getLieu();

    Resultat getResultat();

    map<Style *, Competition *> getCompetitions();

    void setNom(string &nom);

    void setDate(string &date);

    void setLieu(Adresse *lieu);

    void setResultat(Resultat resultat);

    void setCompetitions(map<Style *, Competition *> competitions);

    friend ostream &operator<<(ostream &os, Tournoi &tournoi);

    friend istream &operator>>(istream &in, Tournoi &tournoi);

};