#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Personne.h"
#include "Danseur.h"
#include "Critere.h"
using namespace std;
class Juge : public Personne {
private:
    int numJuge;
    int experience;
public:
    // Const(s) & Dest
    Juge();
    Juge(int , string , string , int , int);
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
    void afficher();
    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Juge &);
    friend istream &operator>>(istream &, Juge &);
    // Methodes
    //void noterDanseur(Danseur &d, vector<Critere *> criteres);
    void estCompetant() override;
};