#ifndef UTILITAIRES_ES
#define UTILITAIRES_ES

/**
* Fichier qui comporte des fonctions permettant de faciliter les
* entrées/sorties
*/

#include <string>

using namespace std;

/**
* Permet de lire un entier entre limiteInferieure et limiteSuperieure
*
* Entrée: message Le message qui sera affiché à chaque lecture
* Entrée: limiteInferieure la limite inférieure
* Entrée: limiteSuperieure la limite supérieure
* Sortie: la valeur entière lue entre limiteInferieure et limiteSuperieure
*/
int lireEntier(const string& message, int limiteInferieure,
	int limiteSuperieure);

/**
* Permet de lire un réel entre limiteInferieure et limiteSuperieure
* exclusivement
*
* Entrée: message Le message qui sera affiché à chaque lecture
* Entrée: limiteInferieure la limite inférieure
* Entrée: limiteSuperieure la limite supérieure
* Sortie: la valeur réelle lue entre limiteInferieure et limiteSuperieure
*/
float lireReel(const string& message, float limiteInferieure,
	float limiteSuperieure);

/**
* Permet de lire un string
* Entrée: Le message qui sera affiché à chaque lecture
* Sortie: la valeur string que l'utilisateur a saisi (maximum de 80 caracteres)
*/
string lireString(const string& message);

/**
* Permet de lire le choix de l'utilisateur (O ou N)
* Entrée: Le message qui sera affiché à chaque lecture
* Sortie: Le choix de l'utilisateur
*/
string lireChoix(const string& message);

#endif

