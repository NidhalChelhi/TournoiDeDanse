#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Adresse.h"

class Personne {
private:
    int cin;
    string nom;
    string prenom;
    vector<Adresse *> adresses;
public:

    // Const(s) & Dest
    Personne();

    Personne(int cin, string nom, string prenom);

    Personne(const Personne &);

    ~Personne();


    // Getters
    int getCin() { return cin; };

    string getNom() { return nom; };

    string getPrenom() { return prenom; };

    string getFullName() { return prenom + " " + nom; };

    vector<Adresse *> getAdresses() { return adresses; };


    // Setters
    void setCin(int cin) {
        this->cin = cin;
    };

    void setNom(string nom) {
        this->nom = nom;
    };

    void setPrenom(string prenom) {
        this->prenom = prenom;
    };

    // Methodes
    void afficherDetails();

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Personne &);

    friend istream &operator>>(istream &, Personne &);


};