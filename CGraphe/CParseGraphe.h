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
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : Retourne le nombre de sommets pr�c�demment lu
	*****************************/
	unsigned int PAGLireNbSommets();

	/*****************************
	Methode : Lire Nombre Arcs
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : Retourne le nombre d'arcs qui a �t� pr�c�demment lu
	*****************************/
	unsigned int PAGLireNbArcs();

	
public:
	// Constructeur

	/*****************************
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CParseGraphe();

	// Methodes

	/*****************************
	Methode : Retourner Graphe
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : Retourne un pointeur sur l'attribut de graGraphe
	Entraine : Cr�ation d'un objet/pointeur en appellant le constructeur de recopie de CGraphe
	*****************************/
	CGrapheOperation * PAGRetournerGraphe();

	/*****************************
	Methode : Traiter Sommets
	******************************
	Entr�e : n�ant
	Necessit� :  M�thode Traiter fichier / Ouvrir fichier
	Sortie : n�ant
	Entraine : La lecture du fichier et cr�ation des sommets du graphe
	*****************************/
	void PAGTraiterSommets();

	/*****************************
	Methode : Traiter Arcs
	******************************
	Entr�e : n�ant
	Necessit� :  M�thode Traiter fichier / Ouvrir fichier
	Sortie : n�ant
	Entraine : La lecture du fichier et cr�ation des arcs du graphe
	*****************************/
	void PAGTraiterArcs();

	/*****************************
	Methode : Traiter fichier
	******************************
	Entr�e : char * sChemin
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : La lecture du fichier et cr�ation du graphe associ�e
	*****************************/
	void PAGTraiterFichier(char * sChemin);
};

#endif