//
// Created by NidhalChelhi on 09/Apr/24.
//

#ifndef TOURNOIDEDANSE_SESSION_H
#define TOURNOIDEDANSE_SESSION_H


#include "Juge.h"
#include "Danseur.h"

class Session {
    vector<Juge> juges;
    // should be 2 !
    vector<Danseur> danseurs;
    Danseur gagnant;

public:

    // const & dest
    Session();

    Session(Danseur danseur1, Danseur danseur2, vector<Juge> juges);

    Session(const Session &);

    ~Session();

    // Getters
    vector<Juge> getJuges() { return juges; };

    vector<Danseur> getDanseurs() { return danseurs; };

    Danseur getGagnant() { return gagnant; };

    // Setters
    void setJuges(vector<Juge> juges) { this->juges = juges; };

    void setDanseurs(vector<Danseur> danseurs) { this->danseurs = danseurs; };



    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Session &);

    friend istream &operator>>(istream &, Session &);



    // methode

    void calculatePerformances() {
        int perfomance0 = juges[0].setPerfomances(danseurs[0]);
        int perfomance1 = juges[0].setPerfomances(danseurs[1]);

        if (perfomance0 > perfomance1) {
            gagnant = danseurs[0];
        } else {
            gagnant = danseurs[1];
        }


    }
};


#endif //TOURNOIDEDANSE_SESSION_H
