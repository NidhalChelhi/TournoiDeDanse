#include "Session.h"


Session::Session() {
    danseur1 = Danseur();
    danseur2 = Danseur();
    juges = vector<Juge *>();
    criteres = vector<Critere *>();
    gagnant = Danseur();
}

Session::Session(Danseur danseur1, Danseur danseur2, vector<Juge *> juges, vector<Critere *> criteres) {
    this->danseur1 = danseur1;
    this->danseur2 = danseur2;
    this->juges = juges;
    this->criteres = criteres;
    gagnant = Danseur();
}

Session::Session(const Session &s) {
    danseur1 = s.danseur1;
    danseur2 = s.danseur2;
    juges = s.juges;
    criteres = s.criteres;
    gagnant = s.gagnant;
}

Session::~Session() {
    juges.clear();
    criteres.clear();
}

ostream &operator<<(ostream &out, Session &s) {
    out << "********** AFFICHAGE SESSION **********" << endl;
    out << "Juges: ";
    for (int i = 0; i < s.juges.size(); i++) {
        out << s.juges[i]->getFullName() << "\t";
    }
    out << endl;
    out << "Danseur 1: " << s.danseur1.getFullName() << endl;
    for (int i = 0; i < s.juges.size(); i++) {
        s.juges[i]->noterDanseur(s.danseur1, s.criteres);
    }

    float score1 = 0;

    out << "Performances: ";
    for (int i = 0; i < s.danseur1.getPerformances().size(); i++) {
        out << s.danseur1.getPerformances()[i] << "\t";
        score1 += s.danseur1.getPerformances()[i];

    }
    out << endl;
    out << "Score: " << score1 << endl;


    out << "Danseur 2: " << s.danseur2.getFullName() << endl;
    for (int i = 0; i < s.juges.size(); i++) {
        s.juges[i]->noterDanseur(s.danseur2, s.criteres);

    }
    float score2 = 0;
    out << "Performances: ";
    for (int i = 0; i < s.danseur2.getPerformances().size(); i++) {
        out << s.danseur2.getPerformances()[i] << "\t";
        score2 += s.danseur2.getPerformances()[i];

    }
    out << endl;
    out << "Score: " << score2 << endl;


    if (score1 > score2) {
        s.gagnant = s.danseur1;
    } else {
        s.gagnant = s.danseur2;
    }
    out << "*** GAGNANT: " << s.gagnant.getFullName() << endl;

    s.danseur1.setPerformances(vector<int>());
    s.danseur2.setPerformances(vector<int>());

    return out;
}

istream &operator>>(istream &in, Session &s) {
    cout << "Entrez le danseur 1: " << endl;
    in >> s.danseur1;
    cout << "Entrez le danseur 2: " << endl;
    in >> s.danseur2;
    char rep;
    do {
        cout << "Entrez un juge: " << endl;
        Juge *juge = new Juge();
        in >> *juge;
        s.juges.push_back(juge);
        cout << "Voulez-vous ajouter un autre juge? (o/n)" << endl;
        in >> rep;
    } while (rep == 'o');
    char rep1;
    do {
        cout << "Entrez un critère: " << endl;

        Critere *critere = new Critere();
        in >> *critere;
        s.criteres.push_back(critere);
        cout << "Ajouter un autre critère? (o/n)";
        in >> rep1;
    } while (rep1 == 'o');
    return in;
}


Danseur Session::calculerGagnant() {
    float score1 = 0;
    float score2 = 0;
    for (int i = 0; i < juges.size(); i++) {
        score1 += juges[i]->noterDanseur(danseur1, criteres);
        score2 += juges[i]->noterDanseur(danseur2, criteres);
        if (score1 > score2) {
            gagnant = danseur1;
        } else {
            gagnant = danseur2;
        }
    }
    return gagnant;
}


