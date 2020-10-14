#include "UtilitairesES.h"
#include <iostream>
#include <string>
using namespace std;

/*
* Implementation .cpp de UtilitaireES.h
*/

int lireEntier(const string& message, int limiteInferieure,
	int limiteSuperieure)
{
	int nombre = 0;
	bool valide = false;
	while (!valide)
	{
		cout << message << ": ";
		cin >> nombre;
		if (cin.fail())
		{
			cerr << "Vous devez entrer une valeur réelle !!" << endl;
		}
		else if (nombre >= limiteInferieure && nombre <= limiteSuperieure)
		{
			valide = true;
		}
		else
		{
			cerr << "Vous devez entrer une valeur entre " << limiteInferieure << " "
				<< "et " << limiteSuperieure << "." << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}


float lireReel(const string& message, float limiteInferieure, float limiteSuperieure)
{
	float nombre = 0;
	bool valide = false;
	while (!valide)
	{
		cout << message << ": ";
		cin >> nombre;
		if (cin.fail())
		{
			cerr << "Vous devez entrer une valeur entière !!" << endl;
		}
		else if (nombre >= limiteInferieure && nombre <= limiteSuperieure)
		{
			valide = true;
		}
		else
		{
			cerr << "Vous devez entrer une valeur entre " << limiteInferieure << " "
				<< "et " << limiteSuperieure << "." << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	}
	return nombre;
}

string lireString(const string& message) {
	bool approuve = false;
	string saisi;

	while (approuve == false) {
		cout << message << ": ";
		getline(cin, saisi);//j'utilise getline, pour récuperer toute la ligne(y compris les espaces)

		if (message.length() <= 80) {//J'accepte seulement une chaine plus petit ou égal à 80 caracteres.
			approuve = true;
		}
		else {
			cout << "Veuillez entrer une chaine d'un maximum de 80 caractere !!!" << endl;
			approuve = false;
		}
	}

	return saisi;
}

string lireChoix(const string& message) {
	string choix;
	bool approuve = false;

	while (approuve == false) {
		cout << message << ":";
		getline(cin, choix);

		if (choix == "O" || choix == "N") {//L'utilisateur doit absolument choisir entre O ou N, sinon on ne quitte pas la boucle
			approuve = true;
		}
		else {
			cout << "Veuillez choisir entre O ou N !!!!" << endl;
			approuve = false;
		}
	}

	return choix;

}