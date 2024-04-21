
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

    // Constructors and destructors
    Tournoi();

    Tournoi(string nom, Adresse *lieu, string date, map<Style *, Competition *> competitions);

    ~Tournoi();

    Tournoi(const Tournoi &tournoi);

    // Getters and setters
    string &getNom();

    string &getDate();

    Adresse *getLieu();

    Resultat getResultat();

    void setNom(string &nom);

    void setDate(string &date);

    void setLieu(Adresse *lieu);

    void setResultat(Resultat resultat);

    void setCompetitions(map<Style *, Competition *> competitions);

    map<Style *, Competition *> getCompetitions();

    // Overloaded operators
    friend ostream &operator<<(ostream &os, Tournoi &tournoi);

    friend istream &operator>>(istream &in, Tournoi &tournoi);


};


