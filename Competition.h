//
// Created by NidhalChelhi on 09/Apr/24.
//

#ifndef TOURNOIDEDANSE_COMPETITION_H
#define TOURNOIDEDANSE_COMPETITION_H


class Competition {

    Style style;
    int nbSessionsInital;
    vector <Session> sessions;

public:

    void saisirCompetition() {
        cout << "Style: ";
        cin >> style;
        cout << "Nombre de sessions: ";
        cin >> nbSessionsInital;
        for (int i = 0; i < nbSessionsInital; i++) {
            Session session;
            cin >> session;
            sessions.push_back(session);
        }
        for (int i = 0; i < nbSessionsInital -1 ; i = i+2) {
           Session session = Session(sessions[i].getGagnant(), sessions[i+1].getGagnant(), jury.getJury());
            sessions.push_back(session);
        }

    }

};


// initial should be 2**k
//initail = n;
//we need other n-1 sessions to the final


[1,2,3,4, 5,6, 7]


class Session {
    vector <Jury> juris;
};
#endif //TOURNOIDEDANSE_COMPETITION_H
