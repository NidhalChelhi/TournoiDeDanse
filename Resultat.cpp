#include "Resultat.h"

Resultat::Resultat() {

}

Resultat::Resultat(vector<Danseur> gagnants) {
    this->gagnants = gagnants;
}

Resultat::~Resultat() {

}

vector<Danseur> &Resultat::getGagnants() {
    return gagnants;
}

void Resultat::setGagnants(vector<Danseur> &gagnants) {
    this->gagnants = gagnants;
}

void Resultat::ajouterGagnant(Danseur gagnant) {
    this->gagnants.push_back(gagnant);
}

ostream &operator<<(ostream &os, Resultat resultat) {
    os << "Gagnants: " << endl;
    for (int i = 0; i < resultat.gagnants.size(); i++) {
        os << resultat.gagnants[i].getFullName() << ": ";
        for (int j = 0; j < resultat.gagnants[i].getPerformances().size(); j++) {
            os << resultat.gagnants[i].getPerformances()[j] << "    ";
        }
        os << endl;
    }
    return os;
}

istream &operator>>(istream &in, Resultat &resultat) {
    cout << "Gagnants: ";
    for (int i = 0; i < resultat.gagnants.size(); i++) {
        in >> resultat.gagnants[i];
    }
    return in;
}

void Resultat::enregistrerFichier(Resultat &resultat) {
    fstream f;
    f.open("D:\\Resultat.txt", ios::in | ios::out | ios::app);
    if (!f.is_open()) exit(-1);
    for (int i = 0; i < resultat.gagnants.size(); i++) {
        f << resultat.gagnants[i];
    }
}

