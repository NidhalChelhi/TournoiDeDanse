#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Personne.h"

class Danseur : public Personne {
private:
    int numDanseur;
    int age;
    vector<double> performances;


public:

    // Const(s) & Dest
    Danseur();

    Danseur(int cin, string nom, string prenom, int numDanseur, int age);

    Danseur(const Danseur &);

    ~Danseur();


    // Getters
    int getNumDanseur() { return numDanseur; };

    int getAge() { return age; };

    vector<double> getPerformances() { return performances; };


    // Setters
    void setNumDanseur(int numDanseur) {
        this->numDanseur = numDanseur;
    };

    void setAge(int age) {
        this->age = age;
    };

    void setPerformances(vector<double> performances) {
        this->performances = performances;
    };

    void afficher();

    // Methodes

    void addPerformance(double performance);

    Danseur operator<(Danseur &d) const;

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Danseur &);

    friend istream &operator>>(istream &, Danseur &);

};