
#include "Danseur.h"
#include <vector>

using namespace std;

class Resultat {

private:
    vector<Danseur> gagnants;

public:

    Resultat();

    Resultat(vector<Danseur> gagnants);

    ~Resultat();

    vector<Danseur> &getGagnants();

    void setGagnants(vector<Danseur> &gagnants);

    void ajouterGagnant(Danseur gagnant);

    friend ostream &operator<<(ostream &os, Resultat resultat);

    friend istream &operator>>(istream &in, Resultat &resultat);

};

