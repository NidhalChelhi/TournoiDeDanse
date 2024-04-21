#pragma once

#include <iomanip>

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Session.h"

class Competition {
private:
    int nbSessionsInital;
    vector<Session *> sessions;

public:

    // Constructeurs
    Competition();

    Competition(int nbSessionsInital, vector<Session *> initialSessions);

    Competition(const Competition &competition);


    // Destructeur
    ~Competition();


    // Getters
    int getNbSessionsInital() const { return nbSessionsInital; };

    vector<Session *> getSessions() const { return sessions; };

    // Méthodes

    void affichageSpecial();
    // Setters

    void setNbSessionsInital(int nbSessionsInital) { this->nbSessionsInital = nbSessionsInital; };

    void setSessions(vector<Session *> sessions) { this->sessions = sessions; };


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &out, const Competition &competition);;

    friend istream &operator>>(istream &in, Competition &competition);;

};
