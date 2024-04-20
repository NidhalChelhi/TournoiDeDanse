#include "Danseur.h"
#include <vector>
#include <map>
#include "algorithm"
using namespace std;

class Resultat {
private:
    vector<Danseur *> gagnants;
    map<int,double> ScoreGagnants;
public:
    // Constructeurs et destructeurs
    Resultat();
    Resultat(vector<Danseur *> gagnants);
    ~Resultat();
    // Methodes
    void ajouterGagnant(Danseur *d);
    void afficherGagnants();
    double GetScoreGagnant(int CIN) { return ScoreGagnants[CIN]; };
    void RemplirScoreGagnants();
    void afficherScoreGagnants();
    // Getters
    vector<Danseur *> getGagnants();
    // Setters
    void setGagnants(vector<Danseur *> gagnants);
    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &os, const Resultat &resultat);
};

