#include "Session.h"


Session::Session() {
    danseur1 = new Danseur();
    danseur2 = new Danseur();
    gagnant = Danseur();
    juge = new Juge();
    criteres = vector<Critere *>();
}

Session::Session(const Danseur &d1, const Danseur &d2, const Juge &j, const vector<Critere *> &c) {
    danseur1 = new Danseur(d1);
    danseur2 = new Danseur(d2);
    juge = new Juge(j);
    for (Critere *critere: c) {
        criteres.push_back(critere);
    }
    determinerGagnant();
}

Session::Session(const Session &s) {
    danseur1 = new Danseur(*s.danseur1);
    danseur2 = new Danseur(*s.danseur2);
    juge = new Juge(*s.juge);
    for (Critere *critere: s.criteres) {
        criteres.push_back(new Critere(*critere));
    }
    gagnant = Danseur(s.gagnant);
}

Session::~Session() {
    delete danseur1;
    delete danseur2;
    delete juge;
    for (Critere *critere: criteres) {
        delete critere;
    }
    criteres.clear();
}


void Session::determinerGagnant() {
    juge->noterDanseur(*danseur1, criteres);
    juge->noterDanseur(*danseur2, criteres);
    Danseur d = *danseur1 < *danseur2;
    setGagnant(d);
};

ostream &operator<<(ostream &out, Session &s) {
    out << "Juge : " << s.juge->getFullName() << endl;
    out << "Danseur 1: " << s.danseur1->getFullName() << endl;
    for (int i = 0; i < s.danseur1->getPerformances().size(); i++) {
        out << "s" << i + 1 << ": " << s.danseur1->getPerformances()[i] << "\t";
    };
    out << endl;
    out << "Danseur 2: " << s.danseur2->getFullName() << endl;
    for (int i = 0; i < s.danseur2->getPerformances().size(); i++) {
        out << "s" << i + 1 << ": " << s.danseur2->getPerformances()[i] << "\t";
    };
    out << endl;
    out << "############# GAGNANT: " << s.getGagnant().getFullName() << endl;
    for (int i = 0; i < s.gagnant.getPerformances().size(); i++) {
        out << "s" << i + 1 << ": " << s.getGagnant().getPerformances()[i] << "\t";
    };
    out << endl;
    return out;
}

istream &operator>>(istream &in, Session &s) {
    s.danseur1 = new Danseur();
    s.danseur2 = new Danseur();
    cout << "Entrez le danseur 1: " << endl;
    in >> *s.danseur1;
    cout << "Entrez le danseur 2: " << endl;
    in >> *s.danseur2;
    cout << "Entrez le juge: " << endl;
    in >> *s.juge;

    char rep;
    do {
        cout << "Entrez un critère: " << endl;
        Critere *critere = new Critere();
        in >> *critere;
        s.criteres.push_back(critere);
        cout << "Ajouter un autre critère? (o/n)";
        in >> rep;
    } while (rep == 'o' || rep == 'O');
    s.determinerGagnant();
    return in;
}




