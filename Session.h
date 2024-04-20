#pragma once
#include "Juge.h"
#include "Danseur.h"
#include "Critere.h"
#include <iostream>
#include <vector>
using namespace std;

class Session {
private:
    Danseur *danseur1;
    Danseur *danseur2;
    Juge *juge;
    vector<Critere *> criteres;
    Danseur gagnant;
    static int nbSessions;
public:
    // const & dest
    Session();
    Session(const Danseur &, const Danseur &, const Juge &,  vector<Critere *> &);
    Session(const Session &s);
    ~Session();
    // Getters
    Danseur *getDanseur1() { return danseur1; }
    Danseur *getDanseur2() { return danseur2; }
    Juge *getJuge() { return juge; }
    vector<Critere *> &getCriteres() { return criteres; }
    Danseur getGagnant() { return gagnant; }
    void setGagnant(Danseur d) { gagnant = d; }
    // Autres méthodes
    void determinerGagnant();
    void noterDanseur(Danseur &);
    // static method
    static int getNbSessions() { return nbSessions; }

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Session &);
    friend istream &operator>>(istream &, Session &);
};


