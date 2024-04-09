#include "Danseur.h"
#include "Style.h"
// Const(s) & Dest
Danseur::Danseur() : Personne() {
    numDanseur = 0;
}

Danseur::Danseur(
        int cin,
        string nom,
        string prenom,
        int age,
        int numDanseur,
        vector<Style *> styles) : Personne(cin, nom, prenom) {
    this->age = age;
    this->numDanseur = numDanseur;
    this->styles = styles;
}

Danseur::Danseur(const Danseur &d) : Personne(d) {
    age = d.age;
    numDanseur = d.numDanseur;
    styles = d.styles;
}

Danseur::~Danseur() {
    for (int i = 0; i < styles.size(); i++) {
        delete styles[i];
    }
}


// Surcharge d'opérateurs
ostream &operator<<(ostream &out, Danseur &d) {
    Personne *p = &d;
    out << *p;
    out << "Age: " << d.age << endl;
    out << "Numéro de danseur: " << d.numDanseur << endl;
    out << "Styles: " << endl;
    for (int i = 0; i < d.styles.size(); i++) {
        out << i + 1 << ") " << *d.styles[i];
    }
    return out;
}

istream &operator>>(istream &in, Danseur &d) {
    Personne *p = &d;
    in >> *p;
    cout << "Age: ";
    in >> d.age;
    cout << "Numéro de danseur: ";
    in >> d.numDanseur;
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




