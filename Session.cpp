#include "Session.h"
Session::Session() {
    danseur1 = new Danseur();
    danseur2 = new Danseur();
    gagnant = Danseur();
    juge = new Juge();
}
Session::Session(const Danseur &d1, const Danseur &d2, const Juge &j,  vector<Critere *> &c) {
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
    for (int i = 0; i < s.criteres.size(); i++) {
        criteres.push_back(new Critere(*s.criteres[i]));
    }
    gagnant = Danseur(s.gagnant);
}
Session::~Session() {
    delete danseur1;
    delete danseur2;
    delete juge;
    for (int i = 0; i < criteres.size(); i++) {
        delete criteres[i];

    }
    criteres.clear();
}
void Session::noterDanseur(Danseur &d) {
    cout << "Noter " << d.getFullName() << ": (doit etre entre 0 et 10): " << endl;
    int performance = 0;
    for (int i = 0; i < criteres.size(); i++) {
        int note = 0;
        cout << criteres[i]->getLibelle() << "= ";
        cin >> note;
        performance += criteres[i]->getCoefficient() * note;
    }
    d.addPerformance((double) performance / criteres.size());

}
void Session::determinerGagnant() {
    noterDanseur(*danseur1);
    noterDanseur(*danseur2);
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
    s.juge = new Juge();
    in >> *s.juge;
    char rep;
    do {
        cout << "Entrez un critere: " << endl;
        Critere *critere = new Critere();
        in >> *critere;
        s.criteres.push_back(critere);
        cout << "Ajouter un autre critere? (o/n)";
        in >> rep;
    } while (rep == 'o' || rep == 'O');
    s.determinerGagnant();
    return in;
}





