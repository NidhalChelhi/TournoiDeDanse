#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Style.h"
#include "Session.h"

class Competition {
private:
    Style *style;
    int nbSessionsInital;
    vector<Session *> sessions;

public:

    // Constructeurs

    Competition() {
        style = new Style();
        nbSessionsInital = 0;
    };

    Competition(Style style, int nbSessionsInital, vector<Session> sessions) {
        this->style = new Style(style);
        this->nbSessionsInital = nbSessionsInital;
        for (int i = 0; i < nbSessionsInital; i++) {
            this->sessions.push_back(new Session(sessions[i]));
        }
    };

    Competition(const Competition &competition) {
        style = new Style(*competition.style);
        nbSessionsInital = competition.nbSessionsInital;
        for (int i = 0; i < nbSessionsInital; i++) {
            sessions.push_back(new Session(*competition.sessions[i]));
        }
    };

    // Destructeur
    ~Competition() {
        delete style;
        for (int i = 0; i < nbSessionsInital; i++) {
            delete sessions[i];
        }
    };


    // Opérateur d'affectation
    Competition &operator=(const Competition &competition) {
        if (this != &competition) {
            delete style;
            for (int i = 0; i < nbSessionsInital; i++) {
                delete sessions[i];
            }
            style = new Style(*competition.style);
            nbSessionsInital = competition.nbSessionsInital;
            for (int i = 0; i < nbSessionsInital; i++) {
                sessions.push_back(new Session(*competition.sessions[i]));
            }
        }
        return *this;
    };

    // Getters
    Style *getStyle() const { return style; };

    int getNbSessionsInital() const { return nbSessionsInital; };

    vector<Session *> getSessions() const { return sessions; };


    // Setters
    void setStyle(Style *style) { this->style = style; };

    void setNbSessionsInital(int nbSessionsInital) { this->nbSessionsInital = nbSessionsInital; };

    void setSessions(vector<Session *> sessions) { this->sessions = sessions; };

    // Surcharge d'opérateurs

    friend ostream &operator<<(ostream &os, const Competition &competition) {
        os << "Style: " << *competition.style << endl;
        os << "Nombre de sessions Initiale: " << competition.nbSessionsInital << endl;
        for (int i = 0; i < competition.nbSessionsInital; i++) {
            os << *competition.sessions[i] << endl;
        }
        return os;
    };

    friend istream &operator>>(istream &is, Competition &competition) {
        cout << "*** Saisie d'une competition ***" << endl;
        is >> *competition.style;
        cout << "Nombre de sessions: ";
        is >> competition.nbSessionsInital;
        for (int i = 0; i < competition.nbSessionsInital; i++) {
            Session *session = new Session();
            is >> *session;
            competition.sessions.push_back(session);
        }
        for (int i = 0; i < competition.nbSessionsInital - 1; i = i + 2) {
            Session *session = new Session(competition.sessions[i]->getGagnant(),
                                           competition.sessions[i + 1]->getGagnant(),
                                           competition.sessions[i]->getJuges(), {});
            competition.sessions.push_back(session);
        }
        return is;
    };


};


// initial should be 2**k
//initail = n;
//we need other n-1 sessions to the final



