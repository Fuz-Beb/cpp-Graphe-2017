#ifndef C_GRAPHEOPERATION_H
#define C_GRAPHEOPERATION_H

#include "CGraphe.h"
#include "CSommet.h"
#include <stdlib.h>

class CGrapheOperation : public CGraphe
{
private:
	CSommet ** SOMListeStableMax;
public:
	// Constructeurs / Destructeurs

	/*****************************
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	CGrapheOperation();

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CGrapheOperation & graGraphe);
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
	*****************************/
	explicit CGrapheOperation(CGrapheOperation & graGrapheOperation);

	/*****************************
	Constructeur de confort
	******************************
	Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CGrapheOperation();

	// Methodes

	/*****************************
	Methode : Inverser un graphe
	******************************
	Entrée : neant
	Necessité : neant
	Sortie : CGrapheOperation *
	Entraine : le graphe de sortie est inverse
	*****************************/
	CGrapheOperation * GRAInverserGraphe();

	/*****************************
	Methode : Convertir un graphe orienté en non orienté
	******************************
	Entrée : neant
	Necessité : neant
	Sortie : CGrapheOperation *
	Entraine : le graphe de sortie est converti en non orienté
	*****************************/
	CGrapheOperation * GRAConvertirGraphe();

	/*****************************
	Methode : Trouver ensemble max sommets indépendants
	******************************
	Entrée : CGraphe & GRAGrapheOrientee, CSommet ** SOMTabStable
	Necessité : neant
	Sortie : void
	Entraine : le graphe de sortie est inverse
	*****************************/
	void CGrapheOperation::calcStableMax(CGraphe * GRAGrapheOrientee, CSommet ** ppqSOMListeStable);

	/*****************************
	Methode : Compter Sommets
	******************************
	Entrée : CSommet ** SOMListeSommets
	Necessité : néant
	Sortie : unsigned int
	Entraine : retourne le nombre de sommet
	*****************************/
	unsigned int CGrapheOperation::compterSommetsListe(CSommet ** SOMListeSommets);

	/*****************************
	Methode : Lire Sommets
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CSommet **
	Entraine : retourne l'attribut
	*****************************/
	CSommet ** CGrapheOperation::GROGetSommets();

	/*****************************
	Methode : Modifier Sommets
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CSommet **
	Entraine : retourne l'attribut
	*****************************/
	void CGrapheOperation::GROSetSommets(CSommet ** SOMListe);
	};


#endif