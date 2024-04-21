
#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Salle {
private:
string nom;
int capacite;

public:
// Const(s) & Dest
Salle();

Salle(string nom, int capacite);

~Salle();

// Getters
string getNom() { return nom; };

int getCapacite() { return capacite; };


// Setters
void setNom(string nom) { this->nom = nom; };

void setCapacite(int capacite) { this->capacite = capacite; };


// Surcharge d'opérateurs
friend ostream &operator<<(ostream &, Salle &);

friend istream &operator>>(istream &, Salle &);

};


