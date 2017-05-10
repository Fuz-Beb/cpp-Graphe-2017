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
	Constructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CGraphe();

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CSommet & sommet);
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
	*****************************/
	explicit CGraphe(CGraphe & graphe);

	/*****************************
	Constructeur de confort
	******************************
	Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs);

	/*****************************
	Surcharge de l'operateur =
	******************************
	Entrée : CGraphe & GRAGraphe
	Necessité : néant
	Sortie : CGraphe &
	Entraine : modification de l'objet a gauche du signe
	*****************************/
	CGraphe & operator=(CGraphe & GRAGraphe);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CGraphe();

	// Accesseurs

	/*****************************
	Methode : Lire Sommets
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CSommet ** ppqSOMSommets
	Entraine : retourne l'attribut
	*****************************/
	CSommet ** CGraphe::GRAGetSommets();

	/*****************************
	Methode : Ajouter Sommet
	******************************
	Entrée : unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant
	Necessité : néant
	Sortie : néant
	Entraine : ajoute un nouveau sommet au graphe
	*****************************/
	void GRAAjoutSommet(unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant);

	/*****************************
	Methode : Supprimer Sommet
	******************************
	Entrée : CSommet * pqSOMsommet
	Necessité : néant
	Sortie : néant
	Entraine : supprime un sommet au graphe
	*****************************/
	void GRASupprimerSommet(CSommet * pqSOMsommet);

	/*****************************
	Methode : Modifier Sommet
	******************************
	Entrée : unsigned int uiNum, CSommet * pqSOMsommet
	Necessité : néant
	Sortie : néant
	Entraine : modifie un sommet au graphe
	*****************************/
	void GRAModifierSommet(unsigned int uiNum, CSommet * pqSOMsommet);

	/*****************************
	Methode : Lire Nombre Sommets
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiGRANbSommets
	Entraine : retourne l'attribut
	*****************************/
	unsigned int GRAGetNbSommets();

	/*****************************
	Methode : Modifier Nombre Sommets
	******************************
	Entrée : unsigned int uiNbSommets
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void GRASetNbSommets(unsigned int uiNbSommets);

	/*****************************
	Methode : Lire Nombre Arcs
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiGRANbArcs
	Entraine : retourne l'attribut
	*****************************/
	unsigned int GRAGetNbArcs();

	/*****************************
	Methode : Modifier Nombre Arcs
	******************************
	Entrée : unsigned int uiNbArcs
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void GRASetNbArcs(unsigned int uiNbArcs);

	/*****************************
	Methode : Récupérer Sommet
	******************************
	Entrée : unsigned int uiSommet
	Necessité : néant
	Sortie : CSommet *
	Entraine : récupère un sommet du graphe
	*****************************/
	CSommet * GRAGetSommet(unsigned int uiSommet);

	/*****************************
	Methode : Ajouter Arc
	******************************
	Entrée : unsigned int uiDestination, CSommet * pqSOMSommet
	Necessité : néant
	Sortie : néant
	Entraine : ajoute un nouvel arc au graphe
	*****************************/
	void GRAAjoutArc(unsigned int uiDestination, CSommet * pqSOMSommet);

	/*****************************
	Methode : Supprimer Arc
	******************************
	Entrée : CArc * pqARCarc, CSommet * pqSOMSommet
	Necessité : néant
	Sortie : néant
	Entraine : supprime un arc au graphe
	*****************************/
	void GRASupprimerArc(CArc * pqARCarc, CSommet * pqSOMSommet);

	/*****************************
	Methode : Afficher Arc
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : affichage du graphe
	Entraine : affichage du graphe dans la console
	*****************************/
	void GRAAfficherGraphe();

	/*****************************
	Methode : Trouver Sommet
	******************************
	Entrée : unsigned int uiSommet
	Necessité : néant
	Sortie : CSommet * 
	Entraine : cherche et renvoi le sommet
	*****************************/
	CSommet * GRATrouverSommet(unsigned int uiSommet);

	/*****************************
	Methode : Trouver Arc
	******************************
	Entrée : CSommet * pqSOMSommetSource, unsigned int uiDestination
	Necessité : néant
	Sortie : CArc *
	Entraine : cherche et renvoi l'arc
	*****************************/
	CArc * GRATrouverArcPartant(CSommet * pqSOMSommetSource, unsigned int uiDestination);


	/*****************************
	Methode : Trouver Arc Arrivant
	******************************
	Entrée : CSommet * pqSOMSommetSource, unsigned int uiDestination
	Necessité : néant
	Sortie : CArc *
	Entraine : cherche et renvoi l'arc
	*****************************/
	CArc * GRATrouverArcArrivant(CSommet * pqSOMSommetSource, unsigned int uiDestination);
};
#endif