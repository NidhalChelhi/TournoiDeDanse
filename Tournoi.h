
#include "Adresse.h"
#include "Competition.h"
#include "Resultat.h"

class Tournoi {

private:
    string nom;
    Adresse *lieu;
    string date;

    vector<Competition *> competitions;
    Resultat *resultat;


public:

    // Constructors and destructors
    Tournoi();

    Tournoi(string nom, Adresse *lieu, string date);

    ~Tournoi();

    // Getters and setters
    const string &getNom() const;

    void setNom(const string &nom);

    Adresse *getLieu() const;

    void setLieu(Adresse *lieu);

    const string &getDate() const;

    void setDate(const string &date);

    const vector<Competition *> &getCompetitions() const;

    void setCompetitions(const vector<Competition *> &competitions);

    Resultat *getResultat() const;

    void setResultat(Resultat *resultat);


    // Overloaded operators
    friend ostream &operator<<(ostream &os, const Tournoi &tournoi);

    friend istream &operator>>(istream &is, Tournoi &tournoi);

};


