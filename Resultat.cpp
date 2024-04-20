#include "Resultat.h"
// Constructeurs et destructeurs
Resultat::Resultat() {}
Resultat::Resultat(vector<Danseur *> gagnants) {
    for (int i = 0; i < gagnants.size(); ++i) {
        this->gagnants.push_back(gagnants[i]);
    }
}
Resultat::~Resultat() {
    for (int i = 0; i < gagnants.size(); ++i) {
        delete gagnants[i];
    }
    gagnants.clear();
}
void Resultat::ajouterGagnant(Danseur *d) {
    gagnants.push_back(d);
}
void Resultat::afficherGagnants() {
    for (int i = 0; i < gagnants.size(); i++) {
        cout << gagnants[i]->getNom() << " " << gagnants[i]->getPrenom() << endl;
    }
}
vector<Danseur *> Resultat::getGagnants() {
    return gagnants;
}
// Setters
void Resultat::setGagnants(vector<Danseur *> gagnants) {
    this->gagnants = gagnants;
}
// Surcharge d'opérateurs
ostream &operator<<(ostream &os, const Resultat &resultat) {
    os << "Gagnants: " << endl;
    for (int i = 0; i < resultat.gagnants.size(); i++) {
        os << resultat.gagnants[i]->getNom() << " " << resultat.gagnants[i]->getPrenom() << endl;
    }
    return os;
}
void Resultat::RemplirScoreGagnants() {
    for (int i = 0; i < gagnants.size(); i++) {
        ScoreGagnants[gagnants[i]->getCIN()] = gagnants[i]->getPerformances().back();
    }
}
void Resultat::afficherScoreGagnants() {
    map<int,double>::iterator it;
    for (it=ScoreGagnants.begin();it!=ScoreGagnants.end();it++) {
        cout<<"CIN : "<<it->first<<" Score : "<<it->second<<endl;
    }
}

