#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Adresse.h"

class Personne {


protected:
    int CIN;
    string nom;
    string prenom;
    vector<Adresse *> adresses;
    static int nbPersonnes;

public:

    Personne(int CIN, string nom, string prenom);

    Personne();

    Personne(const Personne &p);

    ~Personne();

    // Getters
    int getCIN() { return CIN; };

    string getNom() { return nom; };

    string getPrenom() { return prenom; };

    string getFullName() { return prenom + " " + nom; };

    vector<Adresse *> getAdresses() { return adresses; };

    // Setters
    void setCin(int CIN) {
        this->CIN = CIN;
    };

    void setNom(string nom) {
        this->nom = nom;
    };

    void setPrenom(string prenom) {
        this->prenom = prenom;
    };


    // Pure Virtual method
    virtual void afficher() = 0;

    // static Method
    static int getNbPersonnes() { return nbPersonnes; };

    static void displayNbPersonnes() { cout << "Nombre de Personnes: " << nbPersonnes << endl; };

    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Personne &);

    friend istream &operator>>(istream &, Personne &);


};