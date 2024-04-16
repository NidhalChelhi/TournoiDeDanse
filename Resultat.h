
#include "Danseur.h"
#include <vector>

using namespace std;


class Resultat {

private:
    vector<Danseur *> gagnants;
public:
    // Constructeurs et destructeurs
    Resultat();

    Resultat(vector<Danseur *> gagnants);

    ~Resultat();

    // Methodes
    void ajouterGagnant(Danseur *d);

    void afficherGagnants();

    // Getters
    vector<Danseur *> getGagnants();

    // Setters
    void setGagnants(vector<Danseur *> gagnants);

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &os, const Resultat &resultat);


};

