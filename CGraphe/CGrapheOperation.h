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
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	CGrapheOperation();

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CGrapheOperation & graGraphe);
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
	*****************************/
	explicit CGrapheOperation(CGrapheOperation & graGrapheOperation);

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CGrapheOperation();

	// Methodes

	/*****************************
	Methode : Inverser un graphe
	******************************
	Entr�e : neant
	Necessit� : neant
	Sortie : CGrapheOperation *
	Entraine : le graphe de sortie est inverse
	*****************************/
	CGrapheOperation * GRAInverserGraphe();

	/*****************************
	Methode : Convertir un graphe orient� en non orient�
	******************************
	Entr�e : neant
	Necessit� : neant
	Sortie : CGrapheOperation *
	Entraine : le graphe de sortie est converti en non orient�
	*****************************/
	CGrapheOperation * GRAConvertirGraphe();

	/*****************************
	Methode : Trouver ensemble max sommets ind�pendants
	******************************
	Entr�e : CGraphe & GRAGrapheOrientee, CSommet ** SOMTabStable
	Necessit� : neant
	Sortie : void
	Entraine : le graphe de sortie est inverse
	*****************************/
	void CGrapheOperation::calcStableMax(CGraphe * GRAGrapheOrientee, CSommet ** ppqSOMListeStable);

	/*****************************
	Methode : Compter Sommets
	******************************
	Entr�e : CSommet ** SOMListeSommets
	Necessit� : n�ant
	Sortie : unsigned int
	Entraine : retourne le nombre de sommet
	*****************************/
	unsigned int CGrapheOperation::compterSommetsListe(CSommet ** SOMListeSommets);

	/*****************************
	Methode : Lire Sommets
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CSommet **
	Entraine : retourne l'attribut
	*****************************/
	CSommet ** CGrapheOperation::GROGetSommets();

	/*****************************
	Methode : Modifier Sommets
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CSommet **
	Entraine : retourne l'attribut
	*****************************/
	void CGrapheOperation::GROSetSommets(CSommet ** SOMListe);
	};


#endif