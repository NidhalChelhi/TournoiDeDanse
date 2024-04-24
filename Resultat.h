
#include "Danseur.h"
#include <vector>
#include <fstream>

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

    void enregistrerFichier(Resultat &resultat);

    friend ostream &operator<<(ostream &os, Resultat resultat);

    friend istream &operator>>(istream &in, Resultat &resultat);

};

