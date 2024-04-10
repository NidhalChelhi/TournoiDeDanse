#pragma once

#include "Juge.h"
#include "Danseur.h"
#include <vector>

using namespace std;


class Session {
    Danseur *danseur1;
    Danseur *danseur2;
    vector<Juge *> juges;
    vector<Critere *> criteres;
public:
    Danseur *gagnant;

    // const & dest
    Session();

    Session(const Danseur &d1, const Danseur &d2, const vector<Juge *> &j, const vector<Critere *> &c);

    Session(const Session &s);

    ~Session();

    // Getters
    Danseur *getDanseur1() { return danseur1; }

    Danseur *getDanseur2() { return danseur2; }

    vector<Juge *> &getJuges() { return juges; }

    vector<Critere *> &getCriteres() { return criteres; }

    Danseur *getGagnant() { return gagnant; }

    void setGagnant(Danseur *d) { gagnant = d; }

    // Autres méthodes

    void determinerGagnant();


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Session &);

    friend istream &operator>>(istream &, Session &);


};


