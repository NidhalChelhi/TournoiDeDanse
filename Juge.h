#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Personne.h"
#include "Style.h"
#include "Danseur.h"

class Juge : public Personne {
private:
    int numJuge;
    int experience;

public:
    // Const(s) & Dest
    Juge();

    Juge(int cin, string nom, string prenom, int numJuge, int experience);

    Juge(const Juge &);

    ~Juge();

    // Getters
    int getNumJuge() { return numJuge; };

    int getExperience() { return experience; };

    // Setters
    void setNumJuge(int numJuge) {
        this->numJuge = numJuge;
    };

    void setExperience(int experience) {
        this->experience = experience;
    };

    // Methodes
    void noterDanseur(Danseur &d, vector<Critere *> criteres);

    void afficher();

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Juge &);

    friend istream &operator>>(istream &, Juge &);
};