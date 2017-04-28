#include "CSommet.h"
#include "CException.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CSommet::CSommet()
{
	uiSOMNum = 0;
	ppqSOMArcArrivant = nullptr;
	ppqSOMArcPartant = nullptr;

	uiSOMNbrArcArrivant = 0;
	uiSOMNbrArcPartant = 0;
}

/*****************************
Constructeur de recopie
******************************
Entrée : CSommet & sommet);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CSommet::CSommet(CSommet & SOMSommet)
{	
	// Mise à 0 des arcs partant
	uiSOMNbrArcArrivant = SOMSommet.SOMGetNbrArcArrivant();
	uiSOMNbrArcPartant = SOMSommet.SOMGetNbrArcPartant();

    // Affectation du numéro
	uiSOMNum = SOMSommet.SOMGetNum();

    // Initialisation
    ppqSOMArcArrivant = nullptr;
    ppqSOMArcPartant = nullptr;

    // Allocation des arcs arrivant
		if(uiSOMNbrArcArrivant > 0) {
			ppqSOMArcArrivant = (CArc **)malloc(sizeof(CSommet *) * uiSOMNbrArcArrivant);
			if(ppqSOMArcArrivant == nullptr)
				throw new CException(ECHECALLOCATION, "Echec de l'allocation");
        
			for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcArrivant ; uiBoucle++)
				ppqSOMArcArrivant[uiBoucle] = new CArc(*SOMSommet.ppqSOMArcArrivant[uiBoucle]);
        }
        
        // Allocation des arcs partant
        if (uiSOMNbrArcPartant > 0) {
			ppqSOMArcPartant = (CArc **)malloc(sizeof(CSommet *) * uiSOMNbrArcPartant);
            if(ppqSOMArcPartant == nullptr)
				throw new CException(ECHECALLOCATION, "Echec de l'allocation");
                
			for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcPartant ; uiBoucle++)
				ppqSOMArcPartant[uiBoucle] = new CArc(*SOMSommet.ppqSOMArcPartant[uiBoucle]);
        }
}

/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CSommet::CSommet(unsigned int uiNumSommet, CArc * ppqSommetArcArrivant, CArc * ppqSommetArcPartant)
{	
	// Mise à 0 des arcs partant
	uiSOMNbrArcArrivant = 0;
	uiSOMNbrArcPartant = 0;

	// Affectation du numéro
	uiSOMNum = uiNumSommet;

	// Initialisation
	ppqSOMArcArrivant = nullptr;
	ppqSOMArcPartant = nullptr;

	// Allocation des arcs arrivant
	if (ppqSommetArcArrivant != nullptr) {
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcArrivant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	
		ppqSOMArcArrivant[0] = ppqSommetArcPartant;
		uiSOMNbrArcArrivant++;
	}
	
	// Allocation des arcs partant
	if (ppqSommetArcPartant != nullptr) {
		ppqSOMArcPartant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcPartant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		
		ppqSOMArcPartant[0] = ppqSommetArcPartant;
		uiSOMNbrArcPartant++;
	}
}

/*****************************
Surchage de l'operateur =
******************************
Entrée : CSommet & SOMSommet
Necessité : néant
Sortie : CSommet &
Entraine : modification de l'objet a gauche du signe
*****************************/
CSommet & CSommet::operator=(CSommet & SOMSommet)
{
	unsigned int uiBoucle;

	// Mise à 0 des arcs partant
	uiSOMNbrArcArrivant = SOMSommet.SOMGetNbrArcArrivant();
	uiSOMNbrArcPartant = SOMSommet.SOMGetNbrArcPartant();

    // Affectation du numéro
	uiSOMNum = SOMSommet.SOMGetNum();

	// Supprersion des anciens arcs partant
	for (uiBoucle = 0 ; uiBoucle < SOMGetNbrArcPartant() ; uiBoucle++)
		delete(ppqSOMArcPartant[uiBoucle]);

	// Realocation des arcs partant
	ppqSOMArcPartant = (CArc **) realloc(ppqSOMArcPartant, sizeof(CArc *) * SOMSommet.SOMGetNbrArcPartant());

	if(ppqSOMArcPartant == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	// Allocation des nouveaux arcs partant
	for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcPartant ; uiBoucle++)
		ppqSOMArcPartant[uiBoucle] = new CArc(*SOMSommet.ppqSOMArcPartant[uiBoucle]);

	// Supprersion des anciens arcs arrivant
	for (uiBoucle = 0 ; uiBoucle < SOMGetNbrArcArrivant() ; uiBoucle++)
		delete(ppqSOMArcArrivant[uiBoucle]);

	// Realocation des arcs arrivant
	ppqSOMArcArrivant = (CArc **) realloc(ppqSOMArcArrivant, sizeof(CArc *) * SOMSommet.SOMGetNbrArcArrivant());

	if(ppqSOMArcArrivant == nullptr)
		throw new CException(ECHECALLOCATION, "Echec de l'allocation");

	// Allocation des nouveaux arcs arrivant
	for(unsigned int uiBoucle = 0 ; uiBoucle < uiSOMNbrArcArrivant ; uiBoucle++)
		ppqSOMArcArrivant[uiBoucle] = new CArc(*SOMSommet.ppqSOMArcArrivant[uiBoucle]);

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
CSommet::~CSommet()
{
	unsigned int uiBoucle = 0;

	for(uiBoucle = 0 ; uiBoucle < uiSOMNbrArcArrivant ; uiBoucle++)
		if(ppqSOMArcArrivant[uiBoucle] != nullptr)
			delete ppqSOMArcArrivant[uiBoucle];

	if(ppqSOMArcArrivant != nullptr)
		free(ppqSOMArcArrivant);

	for(uiBoucle = 0 ; uiBoucle < uiSOMNbrArcPartant; uiBoucle++)
		if(ppqSOMArcPartant[uiBoucle] != nullptr)
			delete ppqSOMArcPartant[uiBoucle];
	if(ppqSOMArcPartant != nullptr)
		free(ppqSOMArcPartant);
}

/*****************************
Methode : Lire Numero
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiDestination
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNum()
{
	return uiSOMNum;
}

/*****************************
Methode : Modifier Numero
******************************
Entrée : unsigned int uiNum
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNum(unsigned int uiNum)
{
	uiSOMNum = uiNum;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiNbr
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcArrivant()
{
	return uiSOMNbrArcArrivant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entrée : unsigned int uiNbr
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNbrArcArrivant(unsigned int uiNbr)
{
	uiSOMNbrArcArrivant = uiNbr;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiNbr
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcPartant()
{
	return uiSOMNbrArcPartant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entrée : unsigned int uiNbr
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetNbrArcPartant(unsigned int uiNbr)
{
	uiSOMNbrArcPartant = uiNbr;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entrée : néant
Necessité : néant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetListArcArrivant()
{
	return ppqSOMArcArrivant;
}

/*****************************
Methode : Modifier Arc Arrivant
******************************
Entrée : CArc ** arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetListArcArrivant(CArc ** arc)
{
	ppqSOMArcArrivant = arc;
	SOMCompterArc(ppqSOMArcArrivant);
}

/*****************************
Methode : Lire Arc Partant
******************************
Entrée : néant
Necessité : néant
Sortie : CArc **
Entraine : retourne l'attribut
*****************************/
CArc ** CSommet::SOMGetListArcPartant()
{
	return ppqSOMArcPartant;
}

/*****************************
Methode : Modifier Arc Partant
******************************
Entrée : CArc ** arc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CSommet::SOMSetListArcPartant(CArc ** arc)
{
	ppqSOMArcPartant = arc;
	SOMCompterArc(ppqSOMArcPartant);
}

/*****************************
Methode : Ajouter Arc Arrivant
******************************
Entrée : CArc * pARCArc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre arc à la liste des arcs
*****************************/
void CSommet::SOMAddArcArrivant(CArc * pARCArc)
{
	if (pARCArc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas être nul");

	// Allocation pour la première fois
	if(ppqSOMArcArrivant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(CArc *));
		if(ppqSOMArcArrivant == nullptr) {
			delete(pARCArc);
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcArrivant[0] = pARCArc;
	}
	// Sinon reallocation
	else {
		// Reallocation des arcs arrivant
		ppqSOMArcArrivant = (CArc **)realloc(ppqSOMArcArrivant, sizeof(CArc *) * (uiSOMNbrArcArrivant + 1));
		if(ppqSOMArcArrivant == nullptr) {
			delete(pARCArc);
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcArrivant[uiSOMNbrArcArrivant] = pARCArc;
	}
	uiSOMNbrArcArrivant++;
}

/*****************************
Methode : Ajouter Arc Parant
******************************
Entrée : CArc * pARCArc
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre arc à la liste des arcs
*****************************/
void CSommet::SOMAddArcPartant(CArc * pARCArc)
{
	if (pARCArc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas être nul");

	// Allocation pour la première fois
	if(ppqSOMArcPartant == nullptr) {
		// Allocation des arcs arrivant
		ppqSOMArcPartant = (CArc **)malloc(sizeof(CArc *));
		if(ppqSOMArcPartant == nullptr) {
			delete(pARCArc);
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}
		ppqSOMArcPartant[0] = pARCArc;
	}
	// Sinon reallocation
	else {
		// Reallocation des arcs arrivant
		ppqSOMArcPartant = (CArc **)realloc(ppqSOMArcPartant, sizeof(CArc *) * (uiSOMNbrArcPartant + 1));
		if(ppqSOMArcPartant == nullptr) {
			delete(pARCArc);
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		ppqSOMArcPartant[uiSOMNbrArcPartant] = pARCArc;
	}
	uiSOMNbrArcPartant++;
}

/*****************************
Methode : Compter le nombre d'arc dans la liste
******************************
Entrée : CArc ** ARCListArc
Necessité : néant
Sortie : uiCompteur
Entraine : compte le nombre d'arcs dans la liste et retourne le nombre
*****************************/
unsigned int CSommet::SOMCompterArc(CArc ** ARCListArc) 
{
	unsigned int uiCompteur = 0;

	if(ARCListArc == nullptr)
		return 0;

	if(ARCListArc[0] != nullptr)
		uiCompteur = 1;

	while(ARCListArc[uiCompteur + 1] != nullptr) {
		uiCompteur++;
	}

	return uiCompteur;
}

/*****************************
Methode : Vider Sommet
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : vide un sommet de ses arcs
*****************************/
void CSommet::SOMViderSommet()
{
	unsigned int uiBoucle = 0;

	// Boucle de suppression des arcs arrivant
	for (uiBoucle = 0 ; uiBoucle < uiSOMNbrArcArrivant ; uiBoucle++)
		delete(ppqSOMArcArrivant[uiBoucle]);
	uiSOMNbrArcArrivant = 0;

	// Boucle de suppression des arcs partant
	for (uiBoucle = 0 ; uiBoucle < uiSOMNbrArcPartant ; uiBoucle++)
		delete(ppqSOMArcPartant[uiBoucle]);
	uiSOMNbrArcPartant = 0;
}

