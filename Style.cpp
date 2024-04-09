#include "Style.h"
#include <algorithm> // for using transform
#include <cctype> // for using toupper

Style::Style() {
    this->nom = "";
    this->ageMin = 0;
    this->ageMax = 0;
    this->niveau = "";
}

Style::Style(string nom, int ageMin, int ageMax, string niveau) {
    this->nom = nom;
    this->ageMin = ageMin;
    this->ageMax = ageMax;
    this->niveau = niveau;
}

Style::~Style() {
    cout << "Destruction de la style" << endl;
}

ostream &operator<<(ostream &out, Style &style) {
    out << "Nom: " << style.nom << ", Age min: " << style.ageMin << ", Age max: " << style.ageMax << ", Niveau: "
        << style.niveau
        << endl;
    return out;
}

istream &operator>>(istream &in, Style &style) {
    cout << "Saisir les informations du style:" << endl;
    cout << "Nom: ";
    in >> style.nom;
    do {
        cout << "Age min: ";
        in >> style.ageMin;
        cout << "Age max: ";
        in >> style.ageMax;
        if (style.ageMin > style.ageMax) {
            cout << "L'age minimum doit être inférieur à l'age maximum" << endl;
        }
    } while (style.ageMin > style.ageMax);
    //
    do {
        cout << "Niveau (EASY, MEDIUM, HARD): ";
        in >> style.niveau;
        transform(style.niveau.begin(), style.niveau.end(), style.niveau.begin(),
                  ::toupper);
        if (style.niveau != "EASY" && style.niveau != "MEDIUM" && style.niveau != "HARD") {
            cout << "Le niveau doit être l'un des suivants: EASY, MEDIUM, HARD" << endl;
        }
    } while (style.niveau != "EASY" && style.niveau != "MEDIUM" && style.niveau != "HARD");

    return in;
}



