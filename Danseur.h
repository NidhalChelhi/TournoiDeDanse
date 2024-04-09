#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Personne.h"
#include "Style.h"

class Danseur : public Personne {
private:
    int age;
    int numDanseur;
    vector<Style *> styles;
public:

    // Const(s) & Dest
    Danseur();

    Danseur(
            int cin,
            string nom,
            string prenom,
            int age,
            int numDanseur,
            int critere1;
            int critere2;
            int critere3;
            int critere4;
            vector<Style *> styles);

    Danseur(const Danseur &);

    ~Danseur();


    // Getters
    int getAge() { return age; };

    int getNumDanseur() { return numDanseur; };

    int getCritere1() { return critere1; };

    int getCritere2() { return critere2; };

    int getCritere3() { return critere3; };

    int getCritere4() { return critere4; };


    vector<Style *> getStyles() { return styles; };


    // Setters
    void setAge(int age) {
        this->age = age;
    };

    void setNumDanseur(int numDanseur) {
        this->numDanseur = numDanseur;
    };

    void setCritere1(int critere1) {
        this->critere1 = critere1;
    };

    void setCritere2(int critere2) {
        this->critere2 = critere2;
    };

    void setCritere3(int critere3) {
        this->critere3 = critere3;
    };

    void setCritere4(int critere4) {
        this->critere4 = critere4;
    };

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Danseur &);

    friend istream &operator>>(istream &, Danseur &);


};