#ifndef ARBRE_H
#define ARBRE_H
#include "Noeud.h"
#include <list>

/**
* Fichier qui comporte des fonctions permettant de manipuler l'arbre, ses noeuds,
* le curseur et la racine. (Pour faire les traitements de l'arbre)
*/

class Arbre {

public:
	Arbre();//Constructeur par defaut
	Arbre(const Arbre& arbre);
	~Arbre();//Destructeur

	//Acceder � la racine
	const Noeud* getRacine() const;//Retourne le noeud � la racine
	void setRacine(string elem);//Modifier l'�lement de la racine

	//Manipulation du curseur
	const string getCurseurElement() const;//Retourner l'�lement string du curseur
	void deplacerCurseurDebut();//Deplacer le curseur au d�but (� la racine)
	void deplacerCurseurGauche();//Deplace le curseur vers la gauche
	void deplacerCurseurDroite();//Deplace le cruseur vers la droite
	const bool curseurValide() const;//Verifier si le curseur est valide (nullptr ou non)
	const bool verifierDroiteCurseur() const;//Verifier la droite du curseur (si la droite est null ou non)

	//Methodes pour verifier si le curseur pointe sur une question ou une reponse
	const bool determinerQuestion() const;//Verifier si c'est une question
	const bool determinerReponse() const;//Verifier si c'est une reponse (une feuille)
	
	//Inserer une nouvel �lement (quel que soit l'�lement: question, reponse)
	void insererElement(string reponse, string question);

	//M�thodes pour sauvegarder l'arbre, le restaurer et le detruire
	void sauvegarder();//Sauvegarder l'arbre dans le fichier avant de quitter
	void restaurer();//Restaurer l'arbre du fichier, avant de commencer la partie
	void detruire();
	

private:
	Noeud* racine;//La racine de l'arbre (le debut)
	mutable Noeud* curseur;//Curseur essentiel aux nombreux traitements

	string nomFichier = "sauvegarde.txt";//nomFichier pour la sauvegarde
	list<list<string>> listeArbre;//Liste qui contient chaque ligne du fichier
	void lectureFichier();//Methode pour la lecture du fichier et pour le mettre dans la liste
	
	//Sauvegarder r�cursivement en utilisant le niveau et la direction de l'�lement
	void sauvegarderRecursif(Noeud*& n, int niveau, string direction, ofstream& fichier);

	//Restaurer l'arbre r�cursivement en utilisant le niveau et la direction de l'�lement
	void restaurerRecursif(Noeud*& n, int niveau, string direction, list<list<string>>& liste);

	//Detruire l'arbre r�cursivement en utilisant le niveau et la direction de l'�lement
	void detruireRecursif(Noeud*& n);

	//Utile pour comparer le niveau (mettre le int niveau en string)
	string toString(int nombre);
};

#endif
