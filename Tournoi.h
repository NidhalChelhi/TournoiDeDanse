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
    string &getNom();
    void setNom(string &nom);
    Adresse *getLieu() ;
    void setLieu(Adresse *lieu);
    string &getDate() ;
    void setDate( string &date);
    const vector<Competition *> &getCompetitions() ;
    void setCompetitions( vector<Competition *> &competitions);
    Resultat *getResultat() ;
    void setResultat(Resultat *resultat);
    void afficherResultat();
    // Overloaded operators
    friend ostream &operator<<(ostream &, Tournoi&);
    friend istream &operator>>(istream &, Tournoi &);
};


