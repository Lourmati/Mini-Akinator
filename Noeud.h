#ifndef NOEUD_H
#define NOEUD_H
#include <string>
using namespace std;

/**
* Fichier qui comporte des fonctions permettant de manipuler et avoir acces aux noeuds
* Accesseurs, constructeur, destructeur, etc.
*/

class Noeud {
	friend class Arbre;//Ami avec la classe Arbre

public:
	Noeud();//Constructeur par defaut
	~Noeud();//Destructeur

	const string getElement() const;//Get l'element string
	const Noeud* getGauche() const;//Get le noeud à gauche du noeud courant
	Noeud* getGauche();//Get le noeud à gauche du noeud courant
	const Noeud* getDroite() const;//Get le noeud à droite du noeud courant
	Noeud* getDroite();//Get le noeud à droite du noeud courant
	void setElement(string element);//Modifier l'élement du noeud
	void setGauche(Noeud* gauche);//Modifier la gauche du noeud courant
	void setDroite(Noeud* droite);//Modifier la droite du noeud courant

private:
	Noeud* gauche;//Pointeur de type noeud vers la gauche
	Noeud* droite;//Pointeur de type noeud vers la droite
	string element;//L'élement string
};

#endif