#include "Arbre.h"
#include <clocale>
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <list>

/**
* Implementation cpp du Arbre.h
*/

Arbre::Arbre() :
	racine(nullptr)
{
	//La racine est � nullptr au d�but
}

Arbre::Arbre(const Arbre& arbre) {
}

Arbre::~Arbre() {
	//Destructeur vide
}

const Noeud* Arbre::getRacine() const {
	return racine;//Retourner le noeud de la racine
}

const string Arbre::getCurseurElement() const {
	return curseur->getElement();//Retourne le string du curseur
}

const bool Arbre::determinerQuestion() const {
	bool question = false;

	if (curseur->getGauche() != nullptr) {
		question = true;//S'il y a un �lement � gauche (c'est � dire une r�ponse), le curseur est � une reponse
	}

	return question;
}

const bool Arbre::determinerReponse() const {
	bool reponse = false;

	//Si le noeud (curseur) n'a aucun fils (droite ou gauche), c'est une feuille, donc une r�ponse
	if (curseur->getGauche() == nullptr && curseur->getDroite() == nullptr) {
		reponse = true;
	}

	return reponse;
}

const bool Arbre::verifierDroiteCurseur() const {
	bool droite = false;

	if (curseur->getDroite() != nullptr) {//Verifier si il y a un �lement � la droite du curseur
		droite = true;
	}

	return droite;
}

const bool Arbre::curseurValide() const {
	bool curseurValide = false;

	if (curseur != nullptr) {//Verifier si le curseur pointe sur nullptr ou non
		curseurValide = true;
	}

	return curseurValide;
}

void Arbre::setRacine(string elem) {
	racine = new Noeud();//Inserer un nouveau noeud � la racine
	racine->setElement(elem);//Ajuster le noeud avec l'�lement string
}

void Arbre::insererElement(string reponse, string question) {

	if (racine == nullptr) {//Si la racine est a nullptr
		setRacine(question);//On insere le string � la racine
		Noeud* noeudReponse = new Noeud();//Cr�er un nouveau noeud pour la nouvelle r�ponse a gauche
		noeudReponse->setElement(reponse);//Mettre la reponse dans le noeud
		racine->setGauche(noeudReponse);//Ajuster le noeud � gauche de la racine
	}

	else if (curseur->getDroite() == nullptr && curseur->getGauche() == nullptr) {//Si on est dans une feuille
		//Inserer a droite
		Noeud* noeudDroite = new Noeud();
		//On met � droite ce qu'il y a pr�sentement dans le curseur, l'ancienne r�ponse va a droite (pour non)
		noeudDroite->setElement(getCurseurElement());
		curseur->setDroite(noeudDroite);

		//Inserer a gauche la nouvelle r�ponse (oui)
		Noeud* noeudGauche = new Noeud();
		noeudGauche->setElement(reponse);
		curseur->setGauche(noeudGauche);

		//Remplacer le contenu du curseur par la nouvelle question
		curseur->setElement(question);
	}

	else if (verifierDroiteCurseur() == false) {
		//Si le curseur pointe sur nullptr, donc si par exemple on r�pond NON des le d�but

		Noeud* droite = new Noeud();//Cr�er le nouveau noeud
		droite->setElement(question);//Mettre � droite le noeud (avec la question)
		curseur->setDroite(droite);

		deplacerCurseurDroite();//D�placer le curseur � droite (vers la question)

		Noeud* noeudReponse = new Noeud();
		noeudReponse->setElement(reponse);//Mettre la nouvelle reponse  dans le noeud
		curseur->setGauche(noeudReponse);//Mettre ce noeud � gauche de la question
	}
}

void Arbre::deplacerCurseurDebut() {
	curseur = racine;//Curseur d�plac� � la racine
}

void Arbre::deplacerCurseurDroite() {
	curseur = curseur->getDroite();//Deplacer le curseur vers la droite
}

void Arbre::deplacerCurseurGauche() {
	curseur = curseur->getGauche();//Deplacer le curseur vers la gauche
}

void Arbre::sauvegarder() {//Pour sauvegarder on utilise le fichier
	ofstream fichier;
	fichier.open(nomFichier);//Ouvrir le fichier

	if (fichier.is_open()) {//Tant que le fichier est ouvert
		sauvegarderRecursif(racine, 0, "R", fichier);//Commencer la r�cursion avec la racine
	}

	fichier.close();//Fermer le fichier avant de terminer
}

void Arbre::sauvegarderRecursif(Noeud*& n, int niveau, string direction, ofstream& fichier) {

	if (n != nullptr) {//
		fichier << niveau << " " << direction << " " << n->getElement() << endl;//�crire dans le fichier

		sauvegarderRecursif(n->gauche, niveau + 1, "G", fichier);//Gauche, appeler de nouveau le m�thode mais vers gauche
		sauvegarderRecursif(n->droite, niveau + 1, "D", fichier);//Droite, appeler de nouveau la m�thode mais vers droite
	}
}

void Arbre::lectureFichier() {//Lecture du fichier et ins�rer chaque ligne dans la liste
	string niveau, direction, element, line;
	list<string> uneLigne;//Liste pour contenir les 3 variables

	ifstream lecture;
	lecture.open(nomFichier, ios::in);//Ouvrir

	while (getline(lecture, line)) {//Tant qu'il y a des lignes
		istringstream linein{ line };

		//Separer la ligne � chaque espace, et ins�rer chaque partie dans la variable voulu
		getline(linein, niveau, ' ');
		getline(linein, direction, ' ');
		getline(linein, element);

		uneLigne.clear();//Vider la ligne (car la ligne peut contenir les 3 variables de la ligne pr�cedante)

		//Inserer chaque variable dans la liste uneLigne
		uneLigne.push_back(niveau);
		uneLigne.push_back(direction);
		uneLigne.push_back(element);

		listeArbre.push_back(uneLigne);//Inserer uneLigne dans la grande liste (listeArbre)
	}

	lecture.close();//Fermer le fichier
}

void Arbre::restaurer() {//Restaurer l'arbre � partir de la liste du fichier
	lectureFichier();//Lecture du fichier et insertion de chaque ligne dans la listeArbre
	restaurerRecursif(racine, 0, "R", listeArbre);//Commencer la r�cursion avec la racine
}

void Arbre::restaurerRecursif(Noeud*& n, int niveau, string direction, list<list<string>>& liste) {

	if (n == nullptr) {

		if (!liste.empty()) {//Tant que la listeArbre n'est pas vide, donc tant qu'il y a des lignes

			if (toString(niveau) == liste.front().front()) {//J'accede au premier �lement du premier element (ligne) de la liste 
				//Si le niveau correspond au niveau de l'�lement de la ligne, on enl�ve le niveau (avec pop_front)
				liste.front().pop_front();//Lorsque je fait pop_front, la direction va devenir le nouveau front()

				if (direction == liste.front().front()) {//J'accede au premier �lement du premier element (ligne) de la liste 
					//Maintenant, si la direction correspond � la direction de l'�lement de la ligne, on enl�ve la direction
					liste.front().pop_front();//Lorsque je fait pop_front, l'element va devenir le nouveau front()

					n = new Noeud();//On cr�e le nouveau noeud
					n->setElement(liste.front().front());//Ins�rer l'�lement (valide) dans le noeud
					liste.pop_front();//Enlever la ligne de l'�lement de la liste (listeArbre), pour passer � la prochaine ensuite

					restaurerRecursif(n->gauche, niveau + 1, "G", liste);//Refaire la meme chose vers la gauche (recursion)
					restaurerRecursif(n->droite, niveau + 1, "D", liste);//Refaire la meme chose vers la droite (recursion)
				}
			}

		}

	}
}

string Arbre::toString(int nombre) {
	//Convertir le nombre (niveau dans notre cas) en string pour pouvoir faire la comparaison entre sring
	ostringstream ss;
	ss << nombre;
	return ss.str();//Retourne le nombre (niveau) en string
}

void Arbre::detruire() {//Pour sauvegarder on utilise le fichier
	detruireRecursif(racine);//Commencer la r�cursion avec la racine
}

void Arbre::detruireRecursif(Noeud*& n) {

	if (n != nullptr) {//
		detruireRecursif(n->gauche);//Gauche, appeler de nouveau le m�thode mais vers gauche
		detruireRecursif(n->droite);//Droite, appeler de nouveau la m�thode mais vers droite
		delete n;//Detruire le noeud
	}
}

