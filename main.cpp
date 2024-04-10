#include <iostream>
#include "Adresse.h"
#include "Personne.h"
#include "Danseur.h"
#include "Juge.h"
#include "Critere.h"
#include "Style.h"
#include "Session.h"

#include "Competition.h"

using namespace std;


int main() {
    srand(time(0));

    // Test Adresse
    Adresse a1 = Adresse("Pays 1", "Ville 1", "Rue 1", 1234);
    Adresse a2 = Adresse("Pays 2", "Ville 2", "Rue 2", 5678);

    // Test Personne
    Personne p1 = Personne(123, "Doe", "John");
    Personne p2 = Personne(456, "Smith", "Jane");

    // Test Danseur
    Danseur d1 = Danseur(132, "Chelhi", "Nidhal", 1659, 21);
    Danseur d2 = Danseur(456, "Techini", "NourElhouda", 1234, 25);

    // Test Juge
    Juge j1 = Juge(132, "Mekki", "Mohamed", 1659, 21);
    Juge j2 = Juge(456, "Smith", "Jane", 1234, 25);

    // Test Critere
    Critere c1 = Critere("Technique", 10);
    Critere c2 = Critere("Style", 20);
    Critere c3 = Critere("Synchronisation", 30);


    // Test Style
    Style s1 = Style("Hip Hop", 10, 20, "easy");

    // Test Session
    Session session1 = Session(d1, d2, {&j1, &j2}, {&c1, &c2, &c3});
    Session session2 = Session(d1, d2, {&j1, &j2}, {&c1, &c2, &c3});


    Competition competition1;

    cin >> competition1;

    cout << competition1 << endl;
    return 0;
}
