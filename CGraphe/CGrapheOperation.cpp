#include "CGrapheOperation.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CGrapheOperation::CGrapheOperation() : CGraphe()
{
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CGrapheOperation & graGraphe);
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
CGrapheOperation::CGrapheOperation(CGrapheOperation & graGrapheOperation) : CGraphe(graGrapheOperation)
{
}


/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNbSommets, unsigned int uiNbArcs
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CGrapheOperation::CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs) : CGraphe(uiNbSommets, uiNbArcs)
{
}

/*****************************
Destructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet est d�truit
*****************************/
CGrapheOperation::~CGrapheOperation()
{
}

/*****************************
Methode : Inverser un graphe
******************************
Entr�e : neant
Necessit� : neant
Sortie : CGrapheOperation *
Entraine : le graphe de sortie est inverse
*****************************/
CGrapheOperation * CGrapheOperation::GRAInverserGraphe()
{
	CGrapheOperation * newGraphe = new CGrapheOperation();
	unsigned int uiBuffer;

	// Creation des sommets
	for (unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < GRAGetNbSommets() ; uiBoucleSommets++)
		newGraphe->GRAAjoutSommet(GRAGetSommets()[uiBoucleSommets]->SOMGetNum(), nullptr, nullptr);
	// Creation des arcs
	for (unsigned int uiBoucleSommets = 0 ; uiBoucleSommets < GRAGetNbSommets() ; uiBoucleSommets++)
		for (unsigned int uiBoucleArcs = 0 ; uiBoucleArcs < GRAGetSommets()[uiBoucleSommets]->SOMGetNbrArcPartant() ; uiBoucleArcs++) {
			uiBuffer = GRAGetSommets()[uiBoucleSommets]->SOMGetListArcPartant()[uiBoucleArcs]->ARCGetDestination();
			newGraphe->GRAAjoutArc(GRAGetSommets()[uiBoucleSommets]->SOMGetNum(), newGraphe->GRATrouverSommet(uiBuffer));
	}
	return newGraphe;
}

/*****************************
Methode : Convertir un graphe orient� en non orient�
******************************
Entr�e : neant
Necessit� : neant
Sortie : CGrapheOperation *
Entraine : le graphe de sortie est converti en non orient�
*****************************/
CGrapheOperation * CGrapheOperation::GRAConvertirGraphe()
{
	CGrapheOperation * newGraphe = new CGrapheOperation(*this);

	for (unsigned int uiBoucle = 0 ; uiBoucle < newGraphe->GRAGetNbSommets() ; uiBoucle++)
		for (unsigned int uiBoucleArc = 0 ; uiBoucleArc < newGraphe->GRAGetSommets()[uiBoucle]->SOMGetNbrArcArrivant() ; uiBoucleArc++)
			if (newGraphe->GRATrouverArcPartant(newGraphe->GRAGetSommets()[uiBoucle], newGraphe->GRAGetSommets()[uiBoucle]->SOMGetListArcArrivant()[uiBoucleArc]->ARCGetDestination()) == nullptr)
				newGraphe->GRAAjoutArc(newGraphe->GRAGetSommets()[uiBoucle]->SOMGetListArcArrivant()[uiBoucleArc]->ARCGetDestination(), newGraphe->GRAGetSommets()[uiBoucle]);
	return newGraphe;
}

/*****************************
Methode : Trouver ensemble max sommets ind�pendants
******************************
Entr�e : CGraphe & GRAGrapheOrientee, CSommet ** SOMTabStable
Necessit� : neant
Sortie : void
Entraine : le graphe de sortie est inverse
*****************************/
void CGrapheOperation::calcStableMax(CGraphe * GRAGrapheOrientee, CSommet ** ppqSOMListeStable) {
	// Liste des sommets du graphe orient�e
	CSommet ** ppqSOMListeSommets = GRAGrapheOrientee->GRAGetSommets();
	CSommet * SOMSommetPosI;
	unsigned int uiNbrSommetsListe = 0, uiNbrSommetsListeStable = 0;

	// V�rification si la liste des sommets du graphe orient�e est nulle
	if(ppqSOMListeSommets == nullptr) {
		if(compterSommetsListe(ppqSOMListeStable) > compterSommetsListe(GROGetSommets())) {
			GROSetSommets(ppqSOMListeStable);
		}
	}
	else {
		uiNbrSommetsListe = compterSommetsListe(ppqSOMListeSommets);
		for(unsigned int uiBoucle = 1 ; uiBoucle < uiNbrSommetsListe ; uiBoucle++) {
			SOMSommetPosI = ppqSOMListeSommets[uiBoucle]; // SOMSommetPosI est le sommet en position i dans la liste des sommets restant de ppqSOMListeSommets
			uiNbrSommetsListeStable = compterSommetsListe(ppqSOMListeStable);

			// Revoir si l'indice est bon sinon +1
			ppqSOMListeStable = (CSommet **)realloc(ppqSOMListeStable, sizeof(CSommet *) * (uiNbrSommetsListeStable + 1));
			ppqSOMListeStable[uiNbrSommetsListeStable] = SOMSommetPosI;
		}
	}
}

/*****************************
Methode : Compter Sommets
******************************
Entr�e : CSommet ** SOMListeSommets
Necessit� : n�ant
Sortie : unsigned int
Entraine : retourne le nombre de sommet
*****************************/
unsigned int CGrapheOperation::compterSommetsListe(CSommet ** SOMListeSommets) {
	int uiNbrSommets = 0;

	if(SOMListeSommets != nullptr) {
		while(SOMListeSommets[uiNbrSommets + 1] != nullptr) {
			uiNbrSommets++;
		}
	}

	return uiNbrSommets;
}

// Accesseurs

/*****************************
Methode : Lire Sommets
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : CSommet **
Entraine : retourne l'attribut
*****************************/
CSommet ** CGrapheOperation::GROGetSommets()
{
	return SOMListeStableMax;
}

/*****************************
Methode : Modifier Sommets
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : CSommet **
Entraine : retourne l'attribut
*****************************/
void CGrapheOperation::GROSetSommets(CSommet ** SOMListe)
{
	SOMListeStableMax = SOMListe;
}