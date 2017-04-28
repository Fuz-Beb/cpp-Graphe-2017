#ifndef C_GRAPHEOPERATION_H
#define C_GRAPHEOPERATION_H

#include "CGraphe.h"
#include "CSommet.h"

class CGrapheOperation : public CGraphe
{
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
};
#endif