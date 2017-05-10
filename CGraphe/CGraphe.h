#ifndef C_GRAPHE_H
#define C_GRAPHE_H

#include "CSommet.h"
#define ECHECALLOCATION 1
#define ECHECADDARC 7
#define ECHECNEWSOMMET 8
#define ECHECNONTROUVE 9
#define ECHECDOUBLONARC 10
#define ERREURARGS 11
#define ECHECLISTEVIDE 13

class CGraphe
{
private:
	// Attributs
	CSommet ** ppqGRASommets;
	unsigned int uiGRANbSommets;
	unsigned int uiGRANbArcs;

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
	explicit CGraphe();

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CSommet & sommet);
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
	*****************************/
	explicit CGraphe(CGraphe & graphe);

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs);

	/*****************************
	Surcharge de l'operateur =
	******************************
	Entr�e : CGraphe & GRAGraphe
	Necessit� : n�ant
	Sortie : CGraphe &
	Entraine : modification de l'objet a gauche du signe
	*****************************/
	CGraphe & operator=(CGraphe & GRAGraphe);

	/*****************************
	Destructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet est d�truit
	*****************************/
	~CGraphe();

	// Accesseurs

	/*****************************
	Methode : Lire Sommets
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : CSommet ** ppqSOMSommets
	Entraine : retourne l'attribut
	*****************************/
	CSommet ** CGraphe::GRAGetSommets();

	/*****************************
	Methode : Ajouter Sommet
	******************************
	Entr�e : unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : ajoute un nouveau sommet au graphe
	*****************************/
	void GRAAjoutSommet(unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant);

	/*****************************
	Methode : Supprimer Sommet
	******************************
	Entr�e : CSommet * pqSOMsommet
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : supprime un sommet au graphe
	*****************************/
	void GRASupprimerSommet(CSommet * pqSOMsommet);

	/*****************************
	Methode : Modifier Sommet
	******************************
	Entr�e : unsigned int uiNum, CSommet * pqSOMsommet
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : modifie un sommet au graphe
	*****************************/
	void GRAModifierSommet(unsigned int uiNum, CSommet * pqSOMsommet);

	/*****************************
	Methode : Lire Nombre Sommets
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiGRANbSommets
	Entraine : retourne l'attribut
	*****************************/
	unsigned int GRAGetNbSommets();

	/*****************************
	Methode : Modifier Nombre Sommets
	******************************
	Entr�e : unsigned int uiNbSommets
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void GRASetNbSommets(unsigned int uiNbSommets);

	/*****************************
	Methode : Lire Nombre Arcs
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiGRANbArcs
	Entraine : retourne l'attribut
	*****************************/
	unsigned int GRAGetNbArcs();

	/*****************************
	Methode : Modifier Nombre Arcs
	******************************
	Entr�e : unsigned int uiNbArcs
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void GRASetNbArcs(unsigned int uiNbArcs);

	/*****************************
	Methode : R�cup�rer Sommet
	******************************
	Entr�e : unsigned int uiSommet
	Necessit� : n�ant
	Sortie : CSommet *
	Entraine : r�cup�re un sommet du graphe
	*****************************/
	CSommet * GRAGetSommet(unsigned int uiSommet);

	/*****************************
	Methode : Ajouter Arc
	******************************
	Entr�e : unsigned int uiDestination, CSommet * pqSOMSommet
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : ajoute un nouvel arc au graphe
	*****************************/
	void GRAAjoutArc(unsigned int uiDestination, CSommet * pqSOMSommet);

	/*****************************
	Methode : Supprimer Arc
	******************************
	Entr�e : CArc * pqARCarc, CSommet * pqSOMSommet
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : supprime un arc au graphe
	*****************************/
	void GRASupprimerArc(CArc * pqARCarc, CSommet * pqSOMSommet);

	/*****************************
	Methode : Afficher Arc
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : affichage du graphe
	Entraine : affichage du graphe dans la console
	*****************************/
	void GRAAfficherGraphe();

	/*****************************
	Methode : Trouver Sommet
	******************************
	Entr�e : unsigned int uiSommet
	Necessit� : n�ant
	Sortie : CSommet * 
	Entraine : cherche et renvoi le sommet
	*****************************/
	CSommet * GRATrouverSommet(unsigned int uiSommet);

	/*****************************
	Methode : Trouver Arc
	******************************
	Entr�e : CSommet * pqSOMSommetSource, unsigned int uiDestination
	Necessit� : n�ant
	Sortie : CArc *
	Entraine : cherche et renvoi l'arc
	*****************************/
	CArc * GRATrouverArcPartant(CSommet * pqSOMSommetSource, unsigned int uiDestination);


	/*****************************
	Methode : Trouver Arc Arrivant
	******************************
	Entr�e : CSommet * pqSOMSommetSource, unsigned int uiDestination
	Necessit� : n�ant
	Sortie : CArc *
	Entraine : cherche et renvoi l'arc
	*****************************/
	CArc * GRATrouverArcArrivant(CSommet * pqSOMSommetSource, unsigned int uiDestination);
};
#endif