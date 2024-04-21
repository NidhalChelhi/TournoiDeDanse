#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Critere.h"

using namespace std;

class Style {

private:
int id;
string nom;
int ageMin;
int ageMax;
string niveau;
public:

// Const(s) & Dest
Style();

Style(int id, string nom, int ageMin, int ageMax, string niveau);

~Style();

// Getters
int getId() { return id; };

string getNom() { return nom; };

int getAgeMin() { return ageMin; };

int getAgeMax() { return ageMax; };

string getNiveau() { return niveau; };


// Setters
void setId(int id) { this->id = id; };

void setNom(string nom) { this->nom = nom; };

void setAgeMin(int ageMin) { this->ageMin = ageMin; };

void setAgeMax(int ageMax) { this->ageMax = ageMax; };

void setNiveau(string niveau) { this->niveau = niveau; };


// Surcharge d'opérateurs
friend ostream &operator<<(ostream &, Style &);

friend istream &operator>>(istream &, Style &);

bool operator<(const Style &other) const;

bool operator==(const Style &other) const;

Style &operator=(const Style &other);

};

