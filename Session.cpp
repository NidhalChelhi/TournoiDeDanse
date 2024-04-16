#include "Session.h"


Session::Session() {
    danseur1 = new Danseur();
    danseur2 = new Danseur();
    gagnant = new Danseur();

    juges = vector<Juge *>();
    criteres = vector<Critere *>();



}

Session::Session(const Danseur &d1, const Danseur &d2, const vector<Juge *> &j, const vector<Critere *> &c) {
    danseur1 = new Danseur(d1);
    danseur2 = new Danseur(d2);

    for (Juge *judge: j) {
        juges.push_back(judge);
    }
    for (Critere *critere: c) {
        criteres.push_back(critere);
    }
    determinerGagnant();
}

Session::Session(const Session &s) {
    danseur1 = new Danseur(*s.danseur1);
    danseur2 = new Danseur(*s.danseur2);
    for (Juge *judge: s.juges) {
        juges.push_back(new Juge(*judge));
    }
    for (Critere *critere: s.criteres) {
        criteres.push_back(new Critere(*critere));
    }
    gagnant = new Danseur(*s.gagnant);
}

Session::~Session() {
    delete danseur1;
    delete danseur2;
    delete gagnant;

    juges.clear();
    criteres.clear();
}


void Session::determinerGagnant() {
    for (int i = 0; i < juges.size(); i++) {
        juges[i]->noterDanseur(*danseur1, criteres);
        juges[i]->noterDanseur(*danseur2, criteres);
    }
    float score1 = 0;
    float score2 = 0;
    for (int i = 0; i < danseur1->getPerformances().size(); i++) {
        score1 += danseur1->getPerformances()[i];
        score2 += danseur2->getPerformances()[i];
    }
    if (score1 > score2) {
        setGagnant(danseur1);
    } else {
        setGagnant(danseur2);
    };
};

ostream &operator<<(ostream &out, Session &s) {
//    out << "Juges: ";
//    for (int i = 0; i < s.juges.size(); i++) {
//        out << s.juges[i]->getFullName() << "\t";
//    }
//    out << endl;
    out << "Danseur 1: " << s.danseur1->getFullName() << endl;
    out << "Danseur 2: " << s.danseur2->getFullName() << endl;
    s.determinerGagnant();
    out << "############# GAGNANT: " << s.gagnant->getFullName() << endl;
    s.danseur1->setPerformances(vector<int>());
    s.danseur2->setPerformances(vector<int>());

    return out;
}

istream &operator>>(istream &in, Session &s) {
    s.danseur1 = new Danseur();
    s.danseur2 = new Danseur();
    cout << "Entrez le danseur 1: " << endl;
    in >> *s.danseur1;
    cout << "Entrez le danseur 2: " << endl;
    in >> *s.danseur2;
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
    s.determinerGagnant();

    return in;
}



