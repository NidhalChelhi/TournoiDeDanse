#include <iostream>
#include "Tournoi.h"

using namespace std;

int main() {
    int choice;
    Tournoi tournoi;
    while (true) {
        cout << "********************* MENU *********************" << endl;
        cout << "1. Entrer un Tournoi" << endl;
        cout << "2. Afficher Tournoi" << endl;
        cout << "3. Afficher Tableau" << endl;
        cout << "4. Afficher Resultats" << endl;
        cout << "5. Exit" << endl;
        cout << "Enterer votre choix: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin >> tournoi;
                break;
            }
            case 2: {
                cout << tournoi;
                break;
            }

            case 3: {
                map<Style *, Competition *> competitions = tournoi.getCompetitions();
                map<Style *, Competition *>::iterator it;
                for (it = competitions.begin(); it != competitions.end(); it++) {
                    cout << "********************* Competition " << it->first->getNom() << " *********************"
                         << endl;
                    it->second->affichageSpecial();
                }
                break;
            }

            case 4: {
                cout << tournoi.getResultat();
                break;

            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Choix Invalide" << endl;
                break;
            }
        }
    }
    system("pause");
    cout << Personne::getNbPersonnes() << endl;
    return 0;
}