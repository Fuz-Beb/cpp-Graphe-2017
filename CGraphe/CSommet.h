#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.h"

class CSommet
{
private:
	// Attributs
	unsigned int uiSOMNum;
	unsigned int uiSOMNbrArcArrivant;
	unsigned int uiSOMNbrArcPartant;
	CArc ** ppqSOMArcArrivant;
	CArc ** ppqSOMArcPartant;

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
	explicit CSommet();

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CSommet & SOMSommet;
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
	*****************************/
	explicit CSommet(CSommet & SOMSommet);

	/*****************************
	Constructeur de confort
	******************************
	Entrée : unsigned int uiNumSommet, CArc * pqSommetArcArrivant, CArc * pqSommetArcPartant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CSommet(unsigned int uiNumSommet, CArc * pqSommetArcArrivant, CArc * pqSommetArcPartant);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CSommet();

	// Accesseurs

	/*****************************
	Methode : Lire Numero
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNum();

	/*****************************
	Methode : Modifier Numero
	******************************
	Entrée : unsigned int uiNum
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetNum(unsigned int uiNum);

	/*****************************
	Methode : Lire Nombre Arc
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiNbr
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNbrArcArrivant();

	/*****************************
	Methode : Modifier Nombre Arc
	******************************
	Entrée : unsigned int uiNbr
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetNbrArcArrivant(unsigned int uiNbr);

	/*****************************
	Methode : Lire Nombre Arc
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiNbr
	Entraine : retourne l'attribut
	*****************************/
	unsigned int SOMGetNbrArcPartant();

	/*****************************
	Methode : Modifier Nombre Arc
	******************************
	Entrée : unsigned int uiNbr
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetNbrArcPartant(unsigned int uiNbr);

	/*****************************
	Methode : Lire Arc Arrivant
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetListArcArrivant();

	/*****************************
	Methode : Modifier Arc Arrivant
	******************************
	Entrée : CArc ** arc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetListArcArrivant(CArc ** arc);

	/*****************************
	Methode : Lire Arc Partant
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : CArc **
	Entraine : retourne l'attribut
	*****************************/
	CArc ** SOMGetListArcPartant();

	/*****************************
	Methode : Modifier Arc Partant
	******************************
	Entrée : CArc ** arc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void SOMSetListArcPartant(CArc ** arc);

	/*****************************
	Methode : Ajouter Arc Arrivant
	******************************
	Entrée : CArc * pARCArc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre arc à la liste des arcs
	*****************************/
	void SOMAddArcArrivant(CArc * pARCArc);

	/*****************************
	Methode : Ajouter Arc Partant
	******************************
	Entrée : CArc * pARCArc
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre arc à la liste des arcs
	*****************************/
	void  SOMAddArcPartant(CArc * pARCArc);

	/*****************************
	Methode : Supprimer Arc Arrivant
	******************************
	Entrée : CArc * pARCArc
	Necessité : néant
	Sortie : néant
	Entraine : supprime l'arc correspondant
	*****************************/
	void SOMSuppArcArrivant(CArc * pARCArc);

	/*****************************
	Methode : Supprimer Arc Partant
	******************************
	Entrée : CArc * pARCArc
	Necessité : néant
	Sortie : néant
	Entraine : supprime l'arc correspondant
	*****************************/
	void  SOMSuppArcPartant(CArc * pARCArc);

	/*****************************
	Methode : Compter le nombre d'arc dans la liste
	******************************
	Entrée : CArc ** ppARCList
	Necessité : néant
	Sortie : uiCompteur
	Entraine : compte le nombre d'arcs dans la liste et retourne le nombre
	*****************************/
	unsigned int SOMCompterArc(CArc ** ppARCList);

	/*****************************
	Methode : Vider Sommet
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : vide un sommet de ses arcs
	*****************************/
	void SOMViderSommet();
};
#endif