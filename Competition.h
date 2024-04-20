#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Style.h"
#include "Session.h"
using namespace std;
class Competition {
private:
    Style *style;
    int nbSessionsInital;
    vector<Session *> sessions;
public:
    // Constructeurs
    Competition();
    Competition(Style *style, int nbSessionsInital, vector<Session *> initialSessions);
    Competition(const Competition &competition);
    // Destructeur
    ~Competition();
    // Getters
    Style *getStyle() const { return style; };
    int getNbSessionsInital() const { return nbSessionsInital; };
    vector<Session *> getSessions() const { return sessions; };
    // Setters
    void setStyle(Style *style) { this->style = style; };
    void setNbSessionsInital(int nbSessionsInital) { this->nbSessionsInital = nbSessionsInital; };
    void setSessions(vector<Session *> sessions) { this->sessions = sessions; };
    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &out, const Competition &competition);;
    friend istream &operator>>(istream &in, Competition &competition);;
};
