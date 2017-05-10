#ifndef C_PARSEGRAPHE_H
#define C_PARSEGRAPHE_H

#include "CParse.h"
#include "CGrapheOperation.h"
#define FORMATFICHIERINCORRECTE 2

class CParseGraphe : private CParse
{
private:
	// Attributs
	unsigned int uiPAGNbSommets;
	unsigned int uiPAGNbArcs;
	CGrapheOperation PAGgraphe;
	
	// Accesseurs

	/*****************************
	Methode : Lire Nombre Sommets
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : Retourne le nombre de sommets précédemment lu
	*****************************/
	unsigned int PAGLireNbSommets();

	/*****************************
	Methode : Lire Nombre Arcs
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int
	Entraine : Retourne le nombre d'arcs qui a été précédemment lu
	*****************************/
	unsigned int PAGLireNbArcs();

	
public:
	// Constructeur

	/*****************************
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CParseGraphe();

	// Methodes

	/*****************************
	Methode : Retourner Graphe
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : Retourne un pointeur sur l'attribut de graGraphe
	Entraine : Création d'un objet/pointeur en appellant le constructeur de recopie de CGraphe
	*****************************/
	CGrapheOperation * PAGRetournerGraphe();

	/*****************************
	Methode : Traiter fichier
	******************************
	Entrée : char * psChemin
	Necessité : néant
	Sortie : néant
	Entraine : La lecture du fichier et création du graphe associée
	*****************************/
	void PAGTraiterFichier(char * psChemin);

private:
	/*****************************
	Methode : Traiter Sommets
	******************************
	Entrée : néant
	Necessité : méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : La lecture du fichier et création des sommets du graphe
	*****************************/
	void PAGTraiterSommets();

	/*****************************
	Methode : Traiter Arcs
	******************************
	Entrée : néant
	Necessité : méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : La lecture du fichier et création des arcs du graphe
	*****************************/
	void PAGTraiterArcs();
};
#endif