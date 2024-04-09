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
    int experience;
    int numJuge;
    vector<Style *> styles;
public:

    // Const(s) & Dest
    Juge();

    Juge(
            int cin,
            string nom,
            string prenom,
            int experience,
            int numJuge,
            vector<Style *> styles);

    Juge(const Juge &);

    ~Juge();


    // Getters
    int getAge() { return experience; };

    int getNumJuge() { return numJuge; };

    vector<Style *> getStyles() { return styles; };


    // Setters
    void setAge(int experience) {
        this->experience = experience;
    };

    void setNumJuge(int numJuge) {
        this->numJuge = numJuge;
    };


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Juge &);

    friend istream &operator>>(istream &, Juge &);


    // methode
    int setPerfomances(Danseur &d) {
        d.setCritere1(9);
        d.setCritere2(10);
        d.setCritere3(9);
        d.setCritere4(2);

        return d.getCritere1() * 2 + d.getCritere2() * 3 + d.getCritere3() * 8 + d.getCritere4() * 10;
    }

};