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
    vector<int> performances;


public:

    // Const(s) & Dest
    Danseur();

    Danseur(int cin, string nom, string prenom, int numDanseur, int age);

    Danseur(const Danseur &);

    ~Danseur();


    // Getters
    int getNumDanseur() { return numDanseur; };

    int getAge() { return age; };

    vector<int> getPerformances() { return performances; };


    // Setters
    void setNumDanseur(int numDanseur) {
        this->numDanseur = numDanseur;
    };

    void setAge(int age) {
        this->age = age;
    };

    void setPerformances(vector<int> performances) {
        this->performances = performances;
    };

    void afficher();

    // Methodes

    void addPerformance(int performance) {
        this->performances.push_back(performance);
    }


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Danseur &);

    friend istream &operator>>(istream &, Danseur &);


};