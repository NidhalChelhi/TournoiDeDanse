#pragma once

#include "Juge.h"
#include "Danseur.h"
#include <vector>

using namespace std;


class Session {
    Danseur danseur1;
    Danseur danseur2;
    vector<Juge *> juges;
    vector<Critere *> criteres;

    Danseur gagnant;
public:
    // const & dest
    Session();

    Session(Danseur danseur1, Danseur danseur2, vector<Juge *> juges, vector<Critere *> criteres);

    Session(const Session &);

    ~Session();

    // Getters
    Danseur getDanseur1() { return danseur1; };

    Danseur getDanseur2() { return danseur2; };

    vector<Juge *> getJuges() { return juges; };

    vector<Critere *> getCriteres() { return criteres; };

    Danseur getGagnant() { return gagnant; };

    // Setters
    void setDanseur1(Danseur danseur1) { this->danseur1 = danseur1; };

    void setDanseur2(Danseur danseur2) { this->danseur2 = danseur2; };

    void setJuges(vector<Juge *> juges) { this->juges = juges; };

    void setCriteres(vector<Critere *> criteres) { this->criteres = criteres; };


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Session &);

    friend istream &operator>>(istream &, Session &);



    // Methodes

    // Calculer le gagnant de la session
    Danseur calculerGagnant();




};


