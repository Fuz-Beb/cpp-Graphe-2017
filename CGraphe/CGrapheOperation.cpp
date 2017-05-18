#include "CGrapheOperation.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGrapheOperation::CGrapheOperation() : CGraphe()
{
}

/*****************************
Constructeur de recopie
******************************
Entrée : CGrapheOperation & graGraphe);
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CGrapheOperation::CGrapheOperation(CGrapheOperation & graGrapheOperation) : CGraphe(graGrapheOperation)
{
}


/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CGrapheOperation::CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs) : CGraphe(uiNbSommets, uiNbArcs)
{
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CGrapheOperation::~CGrapheOperation()
{
}

/*****************************
Methode : Inverser un graphe
******************************
Entrée : neant
Necessité : neant
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
Methode : Convertir un graphe orienté en non orienté
******************************
Entrée : neant
Necessité : neant
Sortie : CGrapheOperation *
Entraine : le graphe de sortie est converti en non orienté
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