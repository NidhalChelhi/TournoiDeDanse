#include "Competition.h"


Competition::Competition() {
    nbSessionsInital = 0;
};

Competition::Competition(int nbSessionsInital, vector<Session *> initialSessions) {
    this->nbSessionsInital = nbSessionsInital;

    for (int i = 0; i < nbSessionsInital; i++) {
        sessions.push_back(new Session(*initialSessions[i]));
    }
    int i = 0;
    int j = 1;
    while (sessions.size() < 2 * nbSessionsInital - 1) {
        Session *newSession = new Session(sessions[i]->getGagnant(), sessions[j]->getGagnant(),
                                          *sessions[i]->getJuge(), sessions[i]->getCriteres());
        sessions.push_back(newSession);
        i = i + 2;
        j = j + 2;
    };
};

Competition::Competition(const Competition &competition) {
    this->nbSessionsInital = competition.nbSessionsInital;
    for (int i = 0; i < competition.sessions.size(); i++) {
        this->sessions.push_back(new Session(*competition.sessions[i]));
    }
}


Competition::~Competition() {
    for (int i = 0; i < sessions.size(); i++) {
        delete sessions[i];
    }
}

ostream &operator<<(ostream &out, const Competition &competition) {
    for (int i = 0; i < competition.sessions.size(); i++) {
        if (i == competition.sessions.size() - 1) {
            out << "**************** Finale ****************" << endl;
        } else {
            out << "**************** Session " << i + 1 << " ****************" << endl;
        }

        out << *competition.sessions[i] << endl;
    }
    return out;
}

istream &operator>>(istream &in, Competition &competition) {
    cout << "Nombre de sessions: ";
    in >> competition.nbSessionsInital;
    for (int i = 0; i < competition.nbSessionsInital; i++) {
        cout << "*** Saisie de la session " << i + 1 << " ***" << endl;
        Session *session = new Session();
        in >> *session;
        competition.sessions.push_back(session);
    }
    int i = 0;
    int j = 1;


    while (competition.sessions.size() < 2 * competition.nbSessionsInital - 1) {
        Session *newSession = new Session(competition.sessions[i]->getGagnant(),
                                          competition.sessions[j]->getGagnant(),
                                          *competition.sessions[i]->getJuge(),
                                          competition.sessions[i]->getCriteres());

        competition.sessions.push_back(newSession);
        i = i + 2;
        j = j + 2;
    };
    return in;
}

void Competition::affichageSpecial() {
    for (int i = 0; i < nbSessionsInital; i++) {

        cout << setw(8) << sessions[i]->getDanseur1()->getNom() << setw(8) << ""
             << setw(8) << sessions[i]->getDanseur2()->getNom() << setw(8) << "";
    };
    cout << endl;
    cout << endl;
    int round = nbSessionsInital;
    int startIndex = 0;
    int k = 16;
    while (round > 0) {
        for (int i = startIndex; i < startIndex + round; i++) {
            cout << setw(k) << sessions[i]->getGagnant().getNom() << setw(k) << "";
        }
        cout << endl;
        startIndex += round;
        round /= 2;
        k = k * 2;

    }
};


