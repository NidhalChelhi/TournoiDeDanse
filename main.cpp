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

    // Test Adresse
    Adresse a1 = Adresse("Pays 1", "Ville 1", "Rue 1", 1234);
    Adresse a2 = Adresse("Pays 2", "Ville 2", "Rue 2", 5678);


    // Test 8 Danseur
    Danseur d1 = Danseur(111, "1", "Player", 1111, 21);
    Danseur d2 = Danseur(222, "2", "Player", 2222, 25);
    Danseur d3 = Danseur(333, "3", "Player", 3333, 21);
    Danseur d4 = Danseur(444, "4", "Player", 4444, 25);



    // Test Juge
    Juge j1 = Juge(132, "1", "Juge", 1659, 21);
    Juge j2 = Juge(456, "2", "Juge", 1234, 25);

    // Test Critere
    Critere c1 = Critere("Technique", 10);
    Critere c2 = Critere("Style", 20);
    Critere c3 = Critere("Synchronisation", 30);


    // Test Style
    Style s1 = Style("Hip Hop", 10, 20, "easy");

    // Test Session
    Session session1 = Session(d1, d2, j1, {&c1, &c2, &c3});
    Session session2 = Session(d3, d4, j2, {&c1, &c2, &c3});


    Competition c = Competition(&s1, 2, {&session1, &session2});


    cout << c << endl;


    system("pause");
}
