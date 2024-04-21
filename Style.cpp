#include "Style.h"
#include <algorithm> // for using transform
#include <cctype> // for using toupper

Style::Style() {
    this->id = 0;
    this->nom = "";
    this->ageMin = 0;
    this->ageMax = 0;
    this->niveau = "";
}

Style::Style(int id, string nom, int ageMin, int ageMax, string niveau) {
    this->id = id;
    this->nom = nom;
    this->ageMin = ageMin;
    this->ageMax = ageMax;
    this->niveau = niveau;
}

Style::~Style() {}

ostream &operator<<(ostream &out, Style &style) {
    out << "ID: " << style.id << endl;
    out << "Nom: " << style.nom << endl;
    out << "Age min: " << style.ageMin << endl;
    out << "Age max: " << style.ageMax << endl;
    out << "Niveau: " << style.niveau << endl;
    return out;
}

istream &operator>>(istream &in, Style &style) {
    cout << "Saisir les informations du style:" << endl;
    cout << "ID du Style: ";
    in >> style.id;
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

Style &Style::operator=(const Style &other) {
    if (this != &other) {
        this->id = other.id;
        this->nom = other.nom;
        this->ageMin = other.ageMin;
        this->ageMax = other.ageMax;
        this->niveau = other.niveau;
    }
    return *this;
}

bool Style::operator<(const Style &other) const {
    return this->id < other.id;
}

bool Style::operator==(const Style &other) const {
    return this->id == other.id;
}

