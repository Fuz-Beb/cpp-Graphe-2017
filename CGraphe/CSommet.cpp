#include "CSommet.h"
#include "CException.h"

#define ECHECALLOCATION 1

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
Entr�e : CSommet & sommet);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
CSommet::CSommet(CSommet & SOMSommet)
{	
	// Mise � 0 des arcs partant
	uiSOMNbrArcArrivant = SOMSommet.SOMGetNbrArcArrivant();
	uiSOMNbrArcPartant = SOMSommet.SOMGetNbrArcPartant();

    // Affectation du num�ro
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
Entr�e : unsigned int uiNumSommet, CArc * pqSommetArcArrivant, CArc * pqSommetArcPartant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CSommet::CSommet(unsigned int uiNumSommet, CArc * pqSommetArcArrivant, CArc * pqSommetArcPartant)
{	
	// Mise � 0 des arcs partant
	uiSOMNbrArcArrivant = 0;
	uiSOMNbrArcPartant = 0;

	// Affectation du num�ro
	uiSOMNum = uiNumSommet;

	// Initialisation
	ppqSOMArcArrivant = nullptr;
	ppqSOMArcPartant = nullptr;

	// Allocation des arcs arrivant
	if (pqSommetArcArrivant != nullptr) {
		ppqSOMArcArrivant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcArrivant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
	
		ppqSOMArcArrivant[0] = pqSommetArcPartant;
		uiSOMNbrArcArrivant++;
	}
	
	// Allocation des arcs partant
	if (pqSommetArcPartant != nullptr) {
		ppqSOMArcPartant = (CArc **)malloc(sizeof(CSommet *));
		if(ppqSOMArcPartant == nullptr)
			throw new CException(ECHECALLOCATION, "Echec de l'allocation");
		
		ppqSOMArcPartant[0] = pqSommetArcPartant;
		uiSOMNbrArcPartant++;
	}
}

/*****************************
Surchage de l'operateur =
******************************
Entr�e : CSommet & SOMSommet
Necessit� : n�ant
Sortie : CSommet &
Entraine : modification de l'objet a gauche du signe
*****************************/
CSommet & CSommet::operator=(CSommet & SOMSommet)
{
	unsigned int uiBoucle;

	// Mise � 0 des arcs partant
	uiSOMNbrArcArrivant = SOMSommet.SOMGetNbrArcArrivant();
	uiSOMNbrArcPartant = SOMSommet.SOMGetNbrArcPartant();

    // Affectation du num�ro
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
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
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
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiSOMNum
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNum()
{
	return uiSOMNum;
}

/*****************************
Methode : Modifier Numero
******************************
Entr�e : unsigned int uiNum
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNum(unsigned int uiNum)
{
	uiSOMNum = uiNum;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiSOMNbrArcArrivant
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcArrivant()
{
	return uiSOMNbrArcArrivant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entr�e : unsigned int uiNbr
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNbrArcArrivant(unsigned int uiNbr)
{
	uiSOMNbrArcArrivant = uiNbr;
}

/*****************************
Methode : Lire Nombre Arc
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiSOMNbrArcPartant
Entraine : retourne l'attribut
*****************************/
unsigned int CSommet::SOMGetNbrArcPartant()
{
	return uiSOMNbrArcPartant;
}

/*****************************
Methode : Modifier Nombre Arc
******************************
Entr�e : unsigned int uiNbr
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetNbrArcPartant(unsigned int uiNbr)
{
	uiSOMNbrArcPartant = uiNbr;
}

/*****************************
Methode : Lire Arc Arrivant
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : CArc ** ppqARCarc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetListArcArrivant(CArc ** ppqARCarc)
{
	ppqSOMArcArrivant = ppqARCarc;
	SOMCompterArc(ppqSOMArcArrivant);
}

/*****************************
Methode : Lire Arc Partant
******************************
Entr�e : n�ant
Necessit� : n�ant
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
Entr�e : CArc ** arc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CSommet::SOMSetListArcPartant(CArc ** ppqARCarc)
{
	ppqSOMArcPartant = ppqARCarc;
	SOMCompterArc(ppqSOMArcPartant);
}

/*****************************
Methode : Ajouter Arc Arrivant
******************************
Entr�e : CArc * pARCArc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre arc � la liste des arcs
*****************************/
void CSommet::SOMAddArcArrivant(CArc * pARCArc)
{
	if (pARCArc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas �tre nul");

	// Allocation pour la premi�re fois
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
Entr�e : CArc * pARCArc
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre arc � la liste des arcs
*****************************/
void CSommet::SOMAddArcPartant(CArc * pARCArc)
{
	if (pARCArc == nullptr)
		throw new CException(ERREURARGS, "L'argument arc ne peut pas �tre nul");

	// Allocation pour la premi�re fois
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
Entr�e : CArc ** ppARCListArc
Necessit� : n�ant
Sortie : uiCompteur
Entraine : compte le nombre d'arcs dans la liste et retourne le nombre
*****************************/
unsigned int CSommet::SOMCompterArc(CArc ** ppARCListArc) 
{
	unsigned int uiCompteur = 0;

	if(ppARCListArc == nullptr)
		return 0;

	if(ppARCListArc[0] != nullptr)
		uiCompteur = 1;

	while(ppARCListArc[uiCompteur + 1] != nullptr) {
		uiCompteur++;
	}

	return uiCompteur;
}

/*****************************
Methode : Vider Sommet
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
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

