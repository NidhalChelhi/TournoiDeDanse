#pragma once

#include <iostream>
#include <string>

using namespace std;

class Adresse {
private:
    string pays;
    string ville;
    string rue;
    int codePostal;

public:
    // Const(s) & Dest
    Adresse();

    Adresse(string pays, string ville, string rue, int codePostal);

    ~Adresse();


    // Getters
    string getPays() { return pays; }

    string getVille() { return ville; }

    string getRue() { return rue; }

    int getCodePostal() const { return codePostal; }


    // Setters
    void setPays(string pays) { this->pays = pays; }

    void setVille(string ville) { this->ville = ville; }

    void setRue(string rue) { this->rue = rue; }

    void setCodePostal(int codePostal) { this->codePostal = codePostal; }


    // Surcharge d'opérateurs
    friend ostream &operator<<(ostream &, Adresse &);

    friend istream &operator>>(istream &, Adresse &);


};

