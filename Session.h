#pragma once

#include "Juge.h"
#include "Danseur.h"
#include "Salle.h"
#include <vector>

using namespace std;


class Session {
private:
    Danseur *danseur1;
    Danseur *danseur2;
    Juge *juge;
    Salle *salle;
    vector<Critere *> criteres;
    Danseur gagnant;
public:

    // const & dest
    Session();

    Session(const Danseur &, const Danseur &, const Juge &, const Salle &, const vector<Critere *> &);

    Session(const Session &s);

    ~Session();

    // Getters
    Danseur *getDanseur1() { return danseur1; }

    Danseur *getDanseur2() { return danseur2; }

    Juge *getJuge() { return juge; }

    Salle *getSalle() { return salle; }

    vector<Critere *> &getCriteres() { return criteres; }

    Danseur getGagnant() { return gagnant; }

    void setGagnant(Danseur d) { gagnant = d; }

    // Autres méthodes
    void determinerGagnant();

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Session &);

    friend istream &operator>>(istream &, Session &);


};


