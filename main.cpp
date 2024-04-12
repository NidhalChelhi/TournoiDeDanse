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

    // Test 8 Danseur
    Danseur d1 = Danseur(111, "1", "Player", 1111, 21);
    Danseur d2 = Danseur(222, "2", "Player", 2222, 25);
    Danseur d3 = Danseur(333, "3", "Player", 3333, 21);
    Danseur d4 = Danseur(444, "4", "Player", 4444, 25);
    Danseur d5 = Danseur(555, "5", "Player", 5555, 21);
    Danseur d6 = Danseur(666, "6", "Player", 6666, 25);
    Danseur d7 = Danseur(777, "7", "Player", 7777, 21);
    Danseur d8 = Danseur(888, "8", "Player", 8888, 25);




    // Test Juge
    Juge j1 = Juge(132, "1", "Juge", 1659, 21);
    Juge j2 = Juge(456, "2", "Juge", 1234, 25);
    Juge j3 = Juge(789, "3", "Juge", 9876, 21);
    Juge j4 = Juge(101, "4", "Juge", 5432, 25);

    // Test Critere
    Critere c1 = Critere("Technique", 10);
    Critere c2 = Critere("Style", 20);
    Critere c3 = Critere("Synchronisation", 30);


    // Test Style
    Style s1 = Style("Hip Hop", 10, 20, "easy");

    // Test Session
    Session session1 = Session(d1, d2, {&j1}, {&c1, &c2, &c3});
    Session session2 = Session(d3, d4, {&j2}, {&c1, &c2, &c3});
    Session session3 = Session(d5, d6, {&j3}, {&c1, &c2, &c3});
    Session session4 = Session(d7, d8, {&j4}, {&c1, &c2, &c3});


//   Competition c = Competition(&s1, 4, {&session1, &session2, &session3, &session4});
    Competition c;

    cin >> c;

    cout << c << endl;


    system("pause");
}
