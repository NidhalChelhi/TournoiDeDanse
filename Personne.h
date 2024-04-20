#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Adresse.h"
using namespace std;

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
    virtual void estCompetant();
    // Getters
    int getCIN() { return CIN; };
    string getNom() { return nom; };
    string getPrenom() { return prenom; };
    string getFullName() { return prenom + " " + nom; };
    vector<Adresse *> getAdresses() { return adresses; };
    static int getNbPersonnes() { return nbPersonnes; }; // static method
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
    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Personne &);
    friend istream &operator>>(istream &, Personne &);

};

