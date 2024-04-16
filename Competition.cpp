#include "Competition.h"


Competition::Competition() {
    style = new Style();
    nbSessionsInital = 0;
};

Competition::Competition(Style *style, int nbSessionsInital, vector<Session *> initialSessions) {
    this->style = style;
    this->nbSessionsInital = nbSessionsInital;
    for (int i = 0; i < nbSessionsInital; i++) {
        sessions.push_back(new Session(*initialSessions[i]));

    }
    int i = 0;
    int j = 1;
    while (sessions.size() < 2 * nbSessionsInital - 1) {
        Session *newSession = new Session(*sessions[i]->getGagnant(), *sessions[j]->getGagnant(),
                                          sessions[i]->getJuges(), sessions[i]->getCriteres());
        sessions.push_back(newSession);
        i = i + 2;
        j = j + 2;
    };
};

Competition::Competition(const Competition &competition) {
    style = new Style(*competition.style);
    nbSessionsInital = competition.nbSessionsInital;
    for (int i = 0; i < nbSessionsInital; i++) {
        sessions.push_back(new Session(*competition.sessions[i]));
    }
};

Competition::~Competition() {
    delete style;
    for (int i = 0; i < sessions.size(); i++) {
        delete sessions[i];
    }
}

ostream &operator<<(ostream &out, const Competition &competition) {
    out << "Style: " << *competition.style << endl;
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
    cout << "******* Saisie d'une competition ******" << endl;
    in >> *competition.style;
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
        Session *newSession = new Session(*competition.sessions[i]->getGagnant(),
                                          *competition.sessions[j]->getGagnant(),
                                          competition.sessions[i]->getJuges(),
                                          competition.sessions[i]->getCriteres());

        competition.sessions.push_back(newSession);
        i = i + 2;
        j = j + 2;
    };
    return in;
};


