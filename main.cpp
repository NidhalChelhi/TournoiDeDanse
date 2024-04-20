#include <iostream>
#include "Adresse.h"
#include "Personne.h"
#include "Danseur.h"
#include "Juge.h"
#include "Critere.h"
#include "Style.h"
#include "Session.h"
#include "Tournoi.h"
#include "Competition.h"

using namespace std;


int main() {
    // Test Tournoi
    /*Tournoi t1;
    cin>>t1;
    cout<<t1;*/
    Competition c1;
    cin>>c1;
    cout<<c1;
    /*// Test  Danseur
    Danseur d1 ;
    cin>>d1;
    cout<<d1;
    cout<<"--------------------"<<endl;
    Danseur d2 = Danseur(123, "1", "Danseur", 1234, 25);
    cout<<d2;*/

    /*// Test Adresse
    Adresse a1;
    cin>>a1;
    cout<<a1;
    cout<<"--------------------"<<endl;
    Adresse a2 = Adresse("Rue 1", "Ville 1", "Pays 1", 1234);
    cout<<a2;

    // Test Juge
    Juge j1 ;
    cin>>j1;
    cout<<j1;
    cout<<"--------------------"<<endl;
    Juge j2 = Juge(456, "2", "Juge", 1234, 25);
    cout<<j2;
    // Test Critere
    Critere c1 = Critere("Critere 1", 10);
    cout<<c1;
    cout<<"--------------------"<<endl;
    Critere c2 ;
    cin>>c2;
    cout<<c2;
*/

    /*// Test Style
    Style s1 = Style("Hip Hop", 10, 20, "easy");

    // Test Session
    Session session1 = Session(d1, d2, j1, {&c1, &c2, &c3});
    Session session2 = Session(d3, d4, j2, {&c1, &c2, &c3});


    Competition c = Competition(&s1, 2, {&session1, &session2});


    cout << c << endl;*/


    system("pause");
    return 0;
}
