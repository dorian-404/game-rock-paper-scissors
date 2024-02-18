#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
    // Déclaration des variables
    int nombreDeTours = 0;
    const string ROCHE = "Roche";
    const string PAPIER = "Papier";
    const string CISEAUX = "Ciseaux";
    string userInput = " ";
    string userChoice = " ";
    int nbrePointUser = 0;
    int nbrePointOrdi = 0;
    string userChoiceMenu = " ";

    const string options[] = { ROCHE, PAPIER, CISEAUX };
    string choixAutomatique;

    do {
        cout << "/*********** BIENVENUE AU JEU DE PIERRE - PAPIER - CISEAUX **************/\n Cliquez sur une touche pour continuer " << endl;
        cout << "1. Explication du jeu" << endl;
        cout << "2. Nouvelle Partie" << endl;
        cout << "3. Score et Classement final" << endl;
        cout << "4. Terminer le programme\n /***********************************************************/" << endl;

        getline(cin, userChoiceMenu);

        if (userChoiceMenu != "4") {
            switch (stoi(userChoiceMenu)) {
            case 1:
                cout << "Deux joueurs se montrent simultanément leur main qui symbolisera une pierre (poing fermé), un papier (main tendue) ou des ciseaux (l'index et le majeur forment un V). La pierre bat les ciseaux, les ciseaux battent le papier et le papier bat la pierre. Si les deux joueurs jouent le même symbole, il y a égalité" << endl;
                break;
            case 2:
                cout << "Veuillez entrer le nombre de tours : ";
                getline(cin, userInput);
                nombreDeTours = stoi(userInput);
                while (nombreDeTours != 0) {
                    cout << "\nVeuillez votre choix entre la Roche(R), le papier(P) et le ciseaux(C) : ";

                    getline(cin, userChoice);

                    while (userChoice != "P" && userChoice != "C" && userChoice != "R") {
                        cout << "Vous n'avez pas entre la bonne valeur, Veuillez Ressaye ";
                        getline(cin, userChoice);
                    }

                    int randomChoice = rand() % 3 + 1;

                    switch (randomChoice) {
                    case 1:
                        choixAutomatique = ROCHE;
                        if (userChoice == "C") {
                            cout << "L'ordinateur gagne" << endl;
                            nbrePointOrdi += 1;
                            userChoice = CISEAUX;
                        }
                        else if (userChoice == "P") {
                            cout << "L'utilisateur gagne" << endl;
                            nbrePointUser += 1;
                            userChoice = PAPIER;
                        }
                        else {
                            cout << "Egalite" << endl;
                        }
                        break;
                    case 2:
                        choixAutomatique = PAPIER;
                        if (userChoice == "R") {
                            cout << "L'ordinateur gagne" << endl;
                            nbrePointOrdi += 1;
                            userChoice = ROCHE;
                        }
                        else if (userChoice == "C") {
                            cout << "L'utilisateur gagne" << endl;
                            nbrePointUser += 1;
                            userChoice = CISEAUX;
                        }
                        else {
                            cout << "Egalite" << endl;
                        }
                        break;
                    case 3:
                        choixAutomatique = CISEAUX;
                        if (userChoice == "P") {
                            cout << "L'ordinateur gagne" << endl;
                            nbrePointOrdi += 1;
                            userChoice = PAPIER;
                        }
                        else if (userChoice == "R") {
                            cout << "L'utilisateur gagne" << endl;
                            nbrePointUser += 1;
                            userChoice = ROCHE;
                        }
                        else {
                            cout << "Egalite" << endl;
                        }
                        break;
                    default:
                        cerr << "Erreur dans la génération aléatoire." << endl;
                        exit(1);
                    }

                    cout << "Le choix de l'ordinateur : " << choixAutomatique << endl;
                    cout << "Le choix de l'utilisateur : " << userChoice << endl;
                    nombreDeTours -= 1;
                    cout << "Nombre de tours restants : " << nombreDeTours << endl;
                    cout << "Nombre de points de l'ordi : " << nbrePointOrdi << " et Nombre de point du user : " << nbrePointUser << endl;
                }
                break;
            case 3:
                cout << "Le score final de l'ordinateur est " << nbrePointOrdi << endl;
                cout << "Le score final du joueur est " << nbrePointUser << endl;
                if (nbrePointUser > nbrePointOrdi) {
                    cout << "Le vainqueur est l'utilisateur" << endl;
                }
                else {
                    cout << "Le vainqueur est l'ordinateur" << endl;
                }
                break;
            default:
                cout << "Appuyez sur une touche pour continuer" << endl;
                break;
            }
        }
    } while (userChoiceMenu != "4");

    return 0;
}
