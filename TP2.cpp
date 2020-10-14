#include <iostream>
#include <fstream>
#include <Windows.h>
#include <clocale>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <list>
#include "Arbre.h"
#include "UtilitairesES.h"

/**
* Le main, dans lequel le jeu se d�roule 
*/

void afficherMenu();//M�thode pour simplement afficher le menu du jeu
void commencerPartie(Arbre& arbre);//Methode dans laquelle la partie se d�roule (avec les O et N)
void insererNouvelleQuestion(Arbre& arbre);//M�thode pour inserer une nouvelle question et une nouvelle r�ponse

int main() {
	Arbre arbre;//Cr�er l'arbre
	bool quitter = false;
	int choix;
	setlocale(LC_ALL, "");

	arbre.restaurer();//Restaurer l'arbre
	while (!quitter) {//Tant que l'utilisateur ne choisis par 2 (Quitter), on reste dans la partie
		afficherMenu();//Afficher le menu
		choix = lireEntier("Entrez votre choix(entre 1 et 2)", 1, 2);//L'utilisateur choisi entre 1 et 2 (jouer ou quitter)

		if (choix == 1) {//Si le choix est 1, on commence la partie
			commencerPartie(arbre);
		}
		else if (choix == 2) {//Sinon on quitte
			arbre.sauvegarder();//Avant de quitter, sauvegarder l'arbre dans le fichier
			arbre.detruire();
			quitter = true;//Quitter
		}

	}
	return 0;
}


void afficherMenu() {//Afficher le menu avec cout
	cout << "\nVeuillez choisir parmi les choix suivante :\n"
		<< "1) Joueur une nouvelle partie\n"
		<< "2) Quitter" << endl;
}

void commencerPartie(Arbre& arbre) {//Commencer la partie avec l'arbre en parametre
	string reponse;
	string confirmation;

	arbre.deplacerCurseurDebut();//D�placer le curseur au d�but (� la racine)

	//Au tout d�but du jeu, lorsque l'arbre est vide et que racine pointe null
	if (arbre.getRacine() == nullptr) {
		cout << "Je ne sais pas" << endl;
		insererNouvelleQuestion(arbre);//Inserer question et reponse
	}

	else {
		while (arbre.curseurValide() == true) {//Si le curseur est valide
			
			if (arbre.determinerReponse() == true) {//Si on est sur une r�ponse (une feuille)
				cout << "C'est un(e) " + arbre.getCurseurElement() << endl;
				confirmation = lireChoix("J'ai raison? (O/N)");
					
					if (confirmation == "O") {//S'il a trouv�, on break, et retourne au menu
						cout << "J'ai trouv�" << endl;
						break;//Retourner au menu
					}
					else if (confirmation == "N") {//S'il n'a pas trouv�, inserer la nouvelle question
						cout << "J'ai perdu" << endl;
						insererNouvelleQuestion(arbre);
						break;//Retourner au menu
					}
			}

			else if (arbre.determinerQuestion() == true) {//Si on est sur une question
				reponse = lireChoix(arbre.getCurseurElement() + "(O/N)");

				if (reponse == "O") {//Si la reponse � la question est oui
					arbre.deplacerCurseurGauche();
				}
				else if (reponse == "N") {//Si la reponse � la question est non
					if (arbre.verifierDroiteCurseur() == true) {//Verifier
						arbre.deplacerCurseurDroite();
					}
					else {
						cout << "Je ne sais pas" << endl;
						insererNouvelleQuestion(arbre);//Inserer la nouvelle question et reponse
						break;//Retourner au menu
					}
					
				}
			}
		}
	}
}


void insererNouvelleQuestion(Arbre& arbre) {
	string reponse = lireString("Quelle est la r�ponse? ");//Lire la nouvelle reponse
	string question = lireString("Comment puis-je le distinguer? ");//Lire la nouvelle question
	arbre.insererElement(reponse, question);//Inserer la question et la r�ponse
}