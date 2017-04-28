#ifndef C_PARSEGRAPHE_H
#define C_PARSEGRAPHE_H

#include "CParse.h"
#include "CGrapheOperation.h"
#include <string>
#include <stdio.h>

class CParseGraphe : private CParse
{
private:
	// Attributs
	unsigned int uiNbSommets;
	unsigned int uiNbArcs;
	CGrapheOperation graGraphe;
	
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
	Methode : Traiter Sommets
	******************************
	Entrée : néant
	Necessité :  Méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : La lecture du fichier et création des sommets du graphe
	*****************************/
	void PAGTraiterSommets();

	/*****************************
	Methode : Traiter Arcs
	******************************
	Entrée : néant
	Necessité :  Méthode Traiter fichier / Ouvrir fichier
	Sortie : néant
	Entraine : La lecture du fichier et création des arcs du graphe
	*****************************/
	void PAGTraiterArcs();

	/*****************************
	Methode : Traiter fichier
	******************************
	Entrée : char * sChemin
	Necessité : néant
	Sortie : néant
	Entraine : La lecture du fichier et création du graphe associée
	*****************************/
	void PAGTraiterFichier(char * sChemin);
};

#endif