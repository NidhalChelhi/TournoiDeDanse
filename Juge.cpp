#include "Juge.h"
#include "Style.h"
// Const(s) & Dest
Juge::Juge() : Personne() {
    numJuge = 0;
}

Juge::Juge(
        int cin,
        string nom,
        string prenom,
        int experience,
        int numJuge,
        vector<Style *> styles) : Personne(cin, nom, prenom) {
    this->experience = experience;
    this->numJuge = numJuge;
    this->styles = styles;
}

Juge::Juge(const Juge &d) : Personne(d) {
    experience = d.experience;
    numJuge = d.numJuge;
    styles = d.styles;
}

Juge::~Juge() {
    for (int i = 0; i < styles.size(); i++) {
        delete styles[i];
    }
}

// Surcharge d'opérateurs
ostream &operator<<(ostream &out, Juge &d) {
    Personne *p = &d;
    out << *p;
    out << "Age: " << d.experience << endl;
    out << "Numéro de juge: " << d.numJuge << endl;
    out << "Styles: " << endl;
    for (int i = 0; i < d.styles.size(); i++) {
        out << i + 1 << ") " << *d.styles[i];
    }
    return out;
}

istream &operator>>(istream &in, Juge &d) {
    Personne *p = &d;
    in >> *p;
    cout << "Age: ";
    in >> d.experience;
    cout << "Numéro de juge: ";
    in >> d.numJuge;
    char rep;
    do {
        Style *style = new Style();
        in >> *style;
        d.styles.push_back(style);
        cout << "Ajouter un autre style? (o/n)";
        in >> rep;
    } while (rep == 'o');
    return in;
}
