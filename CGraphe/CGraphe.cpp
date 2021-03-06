﻿#include "CGraphe.h"
#include "CException.h"

using namespace std;

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGraphe::CGraphe()
{
	ppqGRASommets = nullptr;
	uiGRANbSommets = 0;
	uiGRANbArcs = 0;
}

/*****************************
Constructeur de recopie
******************************
Entrée : CGraphe & GRAgraphe);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CGraphe::CGraphe(CGraphe & GRAgraphe)
{
	// Allocation de la liste sommet
	ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * GRAgraphe.uiGRANbSommets);
	
	if(ppqGRASommets == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	for(unsigned int uiBoucle = 0 ; uiBoucle < GRAgraphe.uiGRANbSommets ; uiBoucle++) {
		ppqGRASommets[uiBoucle] = new CSommet(*GRAgraphe.ppqGRASommets[uiBoucle]);
	}

	uiGRANbSommets = GRAgraphe.uiGRANbSommets;
	uiGRANbArcs = GRAgraphe.uiGRANbArcs;
}

/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGraphe::CGraphe(unsigned int uiNbSommets, unsigned int uiNbArcs)
{
	ppqGRASommets = nullptr;
	uiGRANbSommets = uiNbSommets;
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Surcharge de l'operateur =
******************************
Entrée : CGraphe & GRAGraphe
Necessité : néant
Sortie : CGraphe &
Entraine : modification de l'objet a gauche du signe
*****************************/
CGraphe & CGraphe::operator=(CGraphe & GRAGraphe)
{
	// Allocation de la liste sommet
	if (GRAGraphe.GRAGetNbSommets() > 0) {
		if (ppqGRASommets == nullptr)
			ppqGRASommets = (CSommet **)malloc(sizeof(CSommet*) * GRAGraphe.uiGRANbSommets);
		else
			ppqGRASommets = (CSommet **) realloc (ppqGRASommets, sizeof(CSommet*) * GRAGraphe.uiGRANbSommets);
	
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		for(unsigned int uiBoucle = 0 ; uiBoucle < GRAGraphe.uiGRANbSommets ; uiBoucle++)
			ppqGRASommets[uiBoucle] = new CSommet(*GRAGraphe.ppqGRASommets[uiBoucle]);
		
	}
	else {
		uiGRANbSommets = GRAGraphe.uiGRANbSommets;
		uiGRANbArcs = GRAGraphe.uiGRANbArcs;
	}
	return *this;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CGraphe::~CGraphe()
{
	if(ppqGRASommets != nullptr) {
		for (unsigned int uiBoucle = 0 ; uiBoucle < uiGRANbSommets ; uiBoucle++) {
			if(ppqGRASommets[uiBoucle] != nullptr)
				delete ppqGRASommets[uiBoucle];
		}
		delete(ppqGRASommets);
	}
}

// Accesseurs

/*****************************
Methode : Lire Sommets
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
CSommet ** CGraphe::GRAGetSommets()
{
	return ppqGRASommets;
}

/*****************************
Methode : Lire Nombre Sommets
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbSommets
Entraine : retourne l'attribut
*****************************/
unsigned int CGraphe::GRAGetNbSommets()
{
	return uiGRANbSommets;
}

/*****************************
Methode : Modifier Nombre Sommets
******************************
Entrée : unsigned int uiNbSommets
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CGraphe::GRASetNbSommets(unsigned int uiNbSommets)
{
	uiGRANbSommets = uiNbSommets;
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiGRANbArcs
Entraine : retourne l'attribut
*****************************/
unsigned int CGraphe::GRAGetNbArcs()
{
	return uiGRANbArcs;
}

/*****************************
Methode : Modifier Nombre Arcs
******************************
Entrée : unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CGraphe::GRASetNbArcs(unsigned int uiNbArcs)
{
	uiGRANbArcs = uiNbArcs;
}

/*****************************
Methode : Ajouter Sommet
******************************
Entrée : unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant
Necessité : néant
Sortie : néant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void CGraphe::GRAAjoutSommet(unsigned int uiSommet, CArc * ppqArrivant, CArc * ppqPartant)
{
	// Unicite avant creation d'un sommet
	if(ppqGRASommets != nullptr) {
		CSommet * SOMlistSommets = GRATrouverSommet(uiSommet);
		if(SOMlistSommets != nullptr)
			throw CException(ECHECNEWSOMMET, "Echec il existe deja un sommet avec ce numero");
		// Reallocation + 1 sommet
		ppqGRASommets = (CSommet **)realloc(ppqGRASommets, sizeof(CSommet *) * (uiGRANbSommets + 1));

		// Verification de la bonne reallocation
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
	else {
		// Creation d'une liste avec comme taille 1 sommet
		ppqGRASommets =(CSommet **)malloc(sizeof(CSommet *));

		// Vérification de la bonne création
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	// Creation d'un nouveau sommet
	CSommet * SOMNewSommet = new CSommet(uiSommet, ppqArrivant, ppqPartant);

	// Vérification d'une présence de liste
	if(SOMNewSommet == nullptr)
		throw CException(ECHECNEWSOMMET, "Echec de la creation d'un nouveau sommet");

	// Ajout à la liste du graphe le sommet et incrément son nombre
	ppqGRASommets[uiGRANbSommets] = SOMNewSommet;
	uiGRANbSommets++;
}

/*****************************
Methode : Supprimer Sommet
******************************
Entrée : CSommet * sommet
Necessité / Préconditions : fournir un objet en paramètre non nul
Sortie : néant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet * SOMSommet)
{
	unsigned int uiBoucle, uiBoucleArcPartant;
	CArc * ARCArcPartant = nullptr;

	if(uiGRANbSommets < 1)
		throw CException(ERREURARGS, "Erreur le nombre de sommet est nul");

	// Vérification de la présence d'une liste non nul
	if(ppqGRASommets == nullptr)
		throw CException(ECHECNONTROUVE, "Echec la liste des sommets est nul");

	// Décrementer le nombre d'arcs
	uiGRANbArcs -= SOMSommet->SOMGetNbrArcArrivant() + SOMSommet->SOMGetNbrArcPartant();

	// Vider les arcs partants des autres sommets
	for (uiBoucle = 0 ; uiBoucle < uiGRANbSommets ; uiBoucle++) {
		ARCArcPartant = GRATrouverArcPartant(ppqGRASommets[uiBoucle], SOMSommet->SOMGetNum());
		if (ARCArcPartant != nullptr)
			for (uiBoucleArcPartant = 0 ; uiBoucleArcPartant < ppqGRASommets[uiBoucle]->SOMGetNbrArcPartant() ; uiBoucleArcPartant++) // Redimensionner la liste des arcs partants
				if (ARCArcPartant->ARCGetDestination() ==  ppqGRASommets[uiBoucle]->SOMGetListArcPartant()[uiBoucleArcPartant]->ARCGetDestination()) {
					delete(ARCArcPartant);
					ppqGRASommets[uiBoucle]->SOMSetNbrArcPartant(ppqGRASommets[uiBoucle]->SOMGetNbrArcPartant() - 1);
					while (uiBoucleArcPartant < ppqGRASommets[uiBoucle]->SOMGetNbrArcPartant()) { // 
						ppqGRASommets[uiBoucle]->SOMGetListArcPartant()[uiBoucleArcPartant] = ppqGRASommets[uiBoucle]->SOMGetListArcPartant()[uiBoucleArcPartant + 1];
						uiBoucleArcPartant++;
					}
					break;
				}
	}

	// Vider les arcs partant du sommets et arrivant dans les autres
	for (uiBoucle = 0 ; uiBoucle < SOMSommet->SOMGetNbrArcPartant() ; uiBoucle++)
		GRASupprimerArc(SOMSommet->SOMGetListArcPartant()[uiBoucle], SOMSommet);

	// Permet de supprimer les arcs liés à ce sommet
	SOMSommet->SOMViderSommet();

	// Suppression du sommet
	for (uiBoucle = 0 ; uiBoucle < uiGRANbSommets ; uiBoucle++)
		if (SOMSommet->SOMGetNum() == ppqGRASommets[uiBoucle]->SOMGetNum()) {
			delete(ppqGRASommets[uiBoucle]);
			uiGRANbSommets--;
			while (uiBoucle < uiGRANbSommets) {
				ppqGRASommets[uiBoucle] = ppqGRASommets[uiBoucle + 1];
				uiBoucle++;
			}
		}

	if(uiGRANbSommets >= 1) {	
		// Realloc de la bonne taille - 1 sommet
		ppqGRASommets = (CSommet **)realloc(ppqGRASommets, sizeof(CSommet *) * ((uiGRANbSommets)));
		if(ppqGRASommets == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}
	else
		delete(ppqGRASommets);
}

/*****************************
Methode : Modifier Sommet
******************************
Entree : unsigned int uiNum, CSommet * SOMSommet
Necessite / Preconditions : fournir un objet en parametre non nul
Sortie : neant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum, CSommet * SOMSommet)
{
	CArc * ARCArcPartant = nullptr;
	unsigned int uiBoucle, uiNbArcArrivant = SOMSommet->SOMGetNbrArcArrivant();

	// Unicite avant modification d'un sommet
	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	// Permet d'actualiser le nouveau numero du sommet aux arcs precedant
	for (uiBoucle = 0 ; uiBoucle < uiNbArcArrivant ; uiBoucle++)
		SOMSommet->SOMGetListArcArrivant()[uiBoucle]->ARCSetDestination(uiNum);

	for (uiBoucle = 0 ; uiBoucle < uiGRANbSommets ; uiBoucle++) {
		ARCArcPartant = GRATrouverArcPartant(ppqGRASommets[uiBoucle], SOMSommet->SOMGetNum());
		if (ARCArcPartant != nullptr)
			ARCArcPartant->ARCSetDestination(uiNum);
	}

	// Permet de changer le numero du sommet
	SOMSommet->SOMSetNum(uiNum);
}

/*****************************
Methode : Ajouter Arc
******************************
Entrée : unsigned int uiDestination, CSommet * sommet
Necessité : néant
Sortie : néant
Entraine : ajoute un nouvel arc au graphe
*****************************/
void CGraphe::GRAAjoutArc(unsigned int uiDestination, CSommet * SOMSommet)
{
	CSommet * SOMDestination = nullptr;
	CArc * ARCArcPartant = nullptr, * ARCArcArrivant = nullptr, * ARCTrouverArc = nullptr;

	// Verification si la liste des sommets est vide
	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	// Recherche du sommet correspondant
	SOMDestination = GRATrouverSommet(uiDestination);
	if(SOMDestination == nullptr) {
		delete(SOMSommet);
		SOMSommet = nullptr;
		throw CException(ECHECNONTROUVE, "Erreur la uiDestination n'a pas été trouvée");
	}
		// Verification d'unicite dans le lien / Impossible d'avoir 1 -> 2 et 1 -> 2
		ARCTrouverArc = GRATrouverArcPartant(SOMSommet, SOMDestination->SOMGetNum());

		if(ARCTrouverArc != nullptr)
			throw CException(ECHECDOUBLONARC, "Erreur doublon d'arc");

		// Creation d'un nouvel arc et affectation
		ARCArcPartant = new CArc(uiDestination);

		if(ARCArcPartant == nullptr)
			throw CException(ECHECADDARC, "Erreur le nouvel arc n'a pas été créé");

		SOMSommet->SOMAddArcPartant(ARCArcPartant);

		ARCArcArrivant = new CArc(SOMSommet->SOMGetNum());
		SOMDestination->SOMAddArcArrivant(ARCArcArrivant);

		// Incrementation des compteurs d'arcs
		uiGRANbArcs++;
}

/*****************************
Methode : Supprimer Arc
******************************
Entrée : CArc * ARCArc, CSommet * SOMSommet
Necessité : néant
Sortie : néant
Entraine : supprime un arc au graphe
*****************************/
void CGraphe::GRASupprimerArc(CArc * ARCArc, CSommet * SOMSommet)
{
	unsigned int uiBoucle;
	CSommet * SOMDestination = nullptr;
	CArc * ARCArcASupprimer = nullptr;
	CArc ** ARCListRealloc = nullptr;

	if(ARCArc == nullptr || SOMSommet == nullptr)
		throw CException(ERREURARGS, "Erreur l'argument n'est pas correcte");

	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	// Affectation du sommet de destination (de l'arc)
	SOMDestination = GRATrouverSommet(ARCArc->ARCGetDestination());
	if(SOMDestination == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur sommet non trouvé");

	// SUPPRESSION SOMMET SOURCE :
	ARCArcASupprimer = GRATrouverArcPartant(SOMSommet, ARCArc->ARCGetDestination());
	if(ARCArcASupprimer == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouve");

	// Redimensionnement de la liste des arcs SOURCE
	for (uiBoucle = 0 ; uiBoucle < SOMSommet->SOMGetNbrArcPartant() ; uiBoucle++)
		if (ARCArcASupprimer->ARCGetDestination() == SOMSommet->SOMGetListArcPartant()[uiBoucle]->ARCGetDestination()) {
			SOMSommet->SOMSetNbrArcPartant(SOMSommet->SOMGetNbrArcPartant() - 1);
			delete(ARCArcASupprimer);
			while (uiBoucle < SOMSommet->SOMGetNbrArcPartant()) {
				SOMSommet->SOMGetListArcPartant()[uiBoucle] = SOMSommet->SOMGetListArcPartant()[uiBoucle + 1];
				uiBoucle++;
			}	
			break;
		}

	// SUPPRESSION SOMMET DESTINATION :
	ARCArcASupprimer = GRATrouverArcArrivant(SOMDestination, SOMSommet->SOMGetNum());
	if(ARCArcASupprimer == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouvé");

	// Redimensionnement de la liste des arcs DESTINATION
	for (uiBoucle = 0 ; uiBoucle < SOMSommet->SOMGetNbrArcArrivant() ; uiBoucle++)
		if (ARCArcASupprimer->ARCGetDestination() == SOMDestination->SOMGetListArcArrivant()[uiBoucle]->ARCGetDestination()) {
			SOMDestination->SOMSetNbrArcArrivant(SOMDestination->SOMGetNbrArcArrivant() - 1);
			delete(ARCArcASupprimer);
			while (uiBoucle < SOMDestination->SOMGetNbrArcArrivant()) {
				SOMDestination->SOMGetListArcArrivant()[uiBoucle] = SOMDestination->SOMGetListArcArrivant()[uiBoucle + 1];
				uiBoucle++;
			}
			break;
		}
}

/*****************************
Methode : Afficher Arc
******************************
Entrée : néant
Necessité : néant
Sortie : affichage du graphe
Entraine : affichage du graphe dans la console
*****************************/
void CGraphe::GRAAfficherGraphe()
{
	unsigned int uiNombreArcPartant = 0;
	CArc ** ARCArcPartant = nullptr;

	// Si le graphe n'a pas de sommet, afficher un message
	if(uiGRANbSommets == 0)
		cout << "Le graphe est vide" << endl;
	// Sinon afficher le graphe
	else {
		// Parcourir tout les sommets
		for(unsigned int uiBoucleSommet = 0 ; uiBoucleSommet < uiGRANbSommets ; uiBoucleSommet++) {
			// Recuperation du nombre d'arc pour le sommet en question
			uiNombreArcPartant = 0;
			if(ppqGRASommets[uiBoucleSommet] == nullptr)
				throw CException(ECHECNONTROUVE, "Erreur le sommet est nul");
			else
				uiNombreArcPartant = ppqGRASommets[uiBoucleSommet]->SOMGetNbrArcPartant();

			// S'il n'y a pas d'arc alors j'affiche juste le sommet
			if(uiNombreArcPartant == 0)
				cout << ppqGRASommets[uiBoucleSommet]->SOMGetNum() << endl;
			else {
				// Recuperation de la liste des arcs
				ARCArcPartant = ppqGRASommets[uiBoucleSommet]->SOMGetListArcPartant();

				// Impossible d'etre ici s'il n'y a pas d'arc (verification au cas ou erreur ailleur)
				if(ARCArcPartant == nullptr)
					throw new CException(ECHECNONTROUVE, "Erreur aucun arc trouvé");

				// Sinon ça rentre dans cette boucle et permet de parcourir les arcs du sommet
				for(unsigned int uiBoucleArc = 0 ; uiBoucleArc < uiNombreArcPartant ; uiBoucleArc++)
					cout << ppqGRASommets[uiBoucleSommet]->SOMGetNum() << " --> " << ARCArcPartant[uiBoucleArc]->ARCGetDestination() << " ; ";

				// Affichage d'un saut de ligne pour ameliorer l'affichage
				cout << endl;
			}
		}
	}
}

/*****************************
Methode : Trouver Sommet
******************************
Entrée : unsigned int uiSommet
Necessité : néant
Sortie : CSommet * 
Entraine : cherche et renvoi le sommet
*****************************/
CSommet * CGraphe::GRATrouverSommet(unsigned int uiSommet)
{
	for(unsigned int uiBoucleSommet = 0 ; uiBoucleSommet < uiGRANbSommets ; uiBoucleSommet++) {
		if(ppqGRASommets[uiBoucleSommet]->SOMGetNum() == uiSommet)
			return ppqGRASommets[uiBoucleSommet];
	}

	return nullptr;
}


/*****************************
Methode : Trouver Arc Partant
******************************
Entrée : CSommet * SOMSommetSource, unsigned int uiDestination
Necessité : néant
Sortie : CArc *
Entraine : cherche et renvoi l'arc
*****************************/
CArc * CGraphe::GRATrouverArcPartant(CSommet * SOMSommetSource, unsigned int uiDestination)
{
	for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < SOMSommetSource->SOMGetNbrArcPartant() ; uiBoucleArcs++)
			if(SOMSommetSource->SOMGetListArcPartant()[uiBoucleArcs]->ARCGetDestination() ==  uiDestination)
				return SOMSommetSource->SOMGetListArcPartant()[uiBoucleArcs];
	return nullptr;
}


/*****************************
Methode : Trouver Arc Arrivant
******************************
Entrée : CSommet * SOMSommetSource, unsigned int uiDestination
Necessité : néant
Sortie : CArc *
Entraine : cherche et renvoi l'arc
*****************************/
CArc * CGraphe::GRATrouverArcArrivant(CSommet * SOMSommetSource, unsigned int uiDestination)
{
	for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < SOMSommetSource->SOMGetNbrArcArrivant() ; uiBoucleArcs++)
			if(SOMSommetSource->SOMGetListArcArrivant()[uiBoucleArcs]->ARCGetDestination() ==  uiDestination)
				return SOMSommetSource->SOMGetListArcArrivant()[uiBoucleArcs];
	return nullptr;
}