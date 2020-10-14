#include "Noeud.h"
#include <string>
using namespace std;

/*
* Implementation cpp du Noeud.h
*/

Noeud::Noeud() :gauche(nullptr), droite(nullptr) {
	//Gauche et droite initialisé à 0
}

Noeud::~Noeud() {
	//Destructeur vide
}

const string Noeud::getElement() const {
	return element;//Retourner l'element string
}

const Noeud* Noeud::getGauche() const {
	return gauche;//Retourner l'element string
}

Noeud* Noeud::getGauche() {
	return gauche;//Retourner le noeud gauche
}

const Noeud* Noeud::getDroite() const {
	return droite;//Retourner le noeud droite
}

Noeud* Noeud::getDroite() {
	return droite;//Retourner le noeud droite
}

void Noeud::setElement(string element) {
	this->element = element;//Set l'element string
}

void Noeud::setGauche(Noeud* gauche) {
	this->gauche = gauche;//Set le noeud à gauche
}

void Noeud::setDroite(Noeud* droite) {
	this->droite = droite;//Set le noeud à droite
}