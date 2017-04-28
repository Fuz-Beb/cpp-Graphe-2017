#include "CGraphe.h"
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
CGraphe & CGraphe::operateur=(CGraphe & GRAGraphe)
{
	// To do	
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
Sortie : CSommet **
Entraine : retourne l'attribut
*****************************/
CSommet ** CGraphe::GRAGetSommets()
{
	return ppqGRASommets;
}

/*****************************
Methode : Ajouter Sommet
******************************
Entrée : unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant
Necessité : néant
Sortie : néant
Entraine : ajoute un nouveau sommet au graphe
*****************************/
void CGraphe::GRAAjoutSommet(unsigned int uiSommet, CArc * pqArrivant, CArc * pqPartant)
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
	CSommet * SOMNewSommet = new CSommet(uiSommet, pqArrivant, pqPartant);

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
Entrée : CSommet * pSOMSommet
Necessité / Préconditions : fournir un objet en paramètre non nul
Sortie : néant
Entraine : supprime un sommet au graphe
*****************************/
void CGraphe::GRASupprimerSommet(CSommet * pSOMSommet)
{
	unsigned int uiBoucle = 0;

	if(uiGRANbSommets < 1)
		throw CException(ERREURARGS, "Erreur le nombre de sommet est nul");

	// Permet de supprimer les arcs liés à ce sommet
	pSOMSommet->SOMViderSommet();

	// Vérification de la présence d'une liste non nul
	if(ppqGRASommets == nullptr)
		throw CException(ECHECNONTROUVE, "Echec la liste des sommets est nul");

	uiGRANbSommets--;
	// Suppression à la liste du graphe le sommet et décrémentant son nombre
	delete(ppqGRASommets[uiGRANbSommets]);

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
Entrée : unsigned int uiNum, CSommet * pSOMSommet
Necessité / Préconditions : fournir un objet en paramètre non nul
Sortie : néant
Entraine : modifie un sommet au graphe
*****************************/
void CGraphe::GRAModifierSommet(unsigned int uiNum, CSommet * pSOMSommet)
{
	unsigned int uiBoucle = 0, uiNbArcArrivant = pSOMSommet->SOMGetNbrArcArrivant();

	// Unicite avant modification d'un sommet
	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	CSommet * SOMlistSommets = GRATrouverSommet(uiNum);
	if(SOMlistSommets == nullptr)
		throw CException(ECHECNEWSOMMET, "Echec le sommet en question n'a pas ete trouve");	

	// Permet d'actualiser le nouveau numero du sommet aux arcs precedant
	while(uiBoucle != uiNbArcArrivant) {
		pSOMSommet->SOMGetListArcArrivant()[uiBoucle]->ARCSetDestination(uiNum);
		uiBoucle++;
	}
	// Permet de changer le numéro du sommet
	pSOMSommet->SOMSetNum(uiNum);
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
Methode : Ajouter Arc
******************************
Entrée : unsigned int uiDestination, CSommet * pSOMSommet
Necessité : néant
Sortie : néant
Entraine : ajoute un nouvel arc au graphe
*****************************/
void CGraphe::GRAAjoutArc(unsigned int uiDestination, CSommet * pSOMSommet)
{
	CSommet * pSOMDestination = nullptr;
	CArc * pARCArcPartant = nullptr, * pARCArcArrivant = nullptr, * pARCTrouverArc = nullptr;

	// Verification si la liste des sommets est vide
	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	// Recherche du sommet correspondant
	pSOMDestination = GRATrouverSommet(uiDestination);
	if(pSOMDestination == nullptr) {
		delete(pSOMSommet);
		pSOMSommet = nullptr;
		throw CException(ECHECNONTROUVE, "Erreur la uiDestination n'a pas été trouvée");
	}
		// Verification d'unicite dans le lien / Impossible d'avoir 1 -> 2 et 1 -> 2
		pARCTrouverArc = GRATrouverArc(pSOMSommet, pSOMDestination->SOMGetNum());

		if(pARCTrouverArc != nullptr)
			throw CException(ECHECDOUBLONARC, "Erreur doublon d'arc");

		// Creation d'un nouvel arc et affectation
		pARCArcPartant = new CArc(uiDestination);

		if(pARCArcPartant == nullptr)
			throw CException(ECHECADDARC, "Erreur le nouvel arc n'a pas été créé");

		pSOMSommet->SOMAddArcPartant(pARCArcPartant);

		pARCArcArrivant = new CArc(*pARCArcPartant);
		pSOMDestination->SOMAddArcArrivant(pARCArcArrivant);

		// Incrementation des compteurs d'arcs
		uiGRANbArcs++;
}

/*****************************
Methode : Supprimer Arc
******************************
Entrée : CArc * pARCArc, CSommet * pSOMSommet
Necessité : néant
Sortie : néant
Entraine : supprime un arc au graphe
*****************************/
void CGraphe::GRASupprimerArc(CArc * pARCArc, CSommet * pSOMSommet)
{
	CSommet * pSOMDestination = nullptr;
	CArc * pARCArcASupprimer = nullptr;

	if(pARCArc == nullptr || pSOMSommet == nullptr)
		throw CException(ERREURARGS, "Erreur l'argument n'est pas correcte");

	if (ppqGRASommets == nullptr)
		throw CException(ECHECLISTEVIDE, "Echec la liste des sommets est vide");

	// Affectation du sommet de destination (de l'arc)
	pSOMDestination = GRATrouverSommet(pARCArc->ARCGetDestination());
	if(pSOMDestination == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur sommet non trouvé");

	// SUPPRESSION SOMMET SOURCE :
	pARCArcASupprimer = GRATrouverArc(pSOMSommet, pARCArc->ARCGetDestination());
	if(pARCArcASupprimer == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouvé");

	 // Supprimer de la liste du sommet source
	delete[] pARCArcASupprimer;

	// SUPPRESSION SOMMET DESTINATION :
	pARCArcASupprimer = GRATrouverArc(pSOMDestination, pARCArc->ARCGetDestination());
	if(pARCArcASupprimer == nullptr)
		throw CException(ECHECNONTROUVE, "Erreur arc non trouvé");

	 // Supprimer de la liste du sommet destination
	delete[] pARCArcASupprimer;
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
	CArc ** ppARCArcPartant = nullptr;

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
				ppARCArcPartant = ppqGRASommets[uiBoucleSommet]->SOMGetListArcPartant();

				// Impossible d'etre ici s'il n'y a pas d'arc (verification au cas ou erreur ailleur)
				if(ppARCArcPartant == nullptr)
					throw new CException(ECHECNONTROUVE, "Erreur aucun arc trouvé");

				// Sinon ça rentre dans cette boucle et permet de parcourir les arcs du sommet
				for(unsigned int uiBoucleArc = 0 ; uiBoucleArc < uiNombreArcPartant ; uiBoucleArc++)
					cout << ppqGRASommets[uiBoucleSommet]->SOMGetNum() << " --> " << ppARCArcPartant[uiBoucleArc]->ARCGetDestination() << " ; ";

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
Methode : Trouver Arc
******************************
Entrée : CSommet * SOMSommetSource, unsigned int uiDestination
Necessité : néant
Sortie : CArc *
Entraine : cherche et renvoi l'arc
*****************************/
CArc * CGraphe::GRATrouverArc(CSommet * SOMSommetSource, unsigned int uiDestination)
{
	for(unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < SOMSommetSource->SOMGetNbrArcPartant() ; uiBoucleArcs++)
		if(SOMSommetSource->SOMGetNbrArcPartant() != 0)
			if(SOMSommetSource->SOMGetListArcPartant()[uiBoucleArcs]->ARCGetDestination() ==  uiDestination)
				return SOMSommetSource->SOMGetListArcPartant()[uiBoucleArcs];
	return nullptr;
}
