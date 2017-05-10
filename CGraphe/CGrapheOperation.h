#ifndef C_GRAPHEOPERATION_H
#define C_GRAPHEOPERATION_H
 
#include "CGraphe.h"
 
class CGrapheOperation : public CGraphe
{
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
    explicit CGrapheOperation();
 
    /*****************************
    Constructeur de recopie
    ******************************
    Entrée : CGrapheOperation & GRAgraphe
    Necessité : néant
    Sortie : néant
    Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
    *****************************/
    explicit CGrapheOperation(CGrapheOperation & GRAgrapheOperation);
 
    /*****************************
    Constructeur de confort
    ******************************
    Entrée : unsigned int uiNbSommets, unsigned int uiNbArcs
    Necessité : néant
    Sortie : néant
    Entraine : l'objet en cours est initialisé
    *****************************/
    explicit CGrapheOperation(unsigned int uiNbSommets, unsigned int uiNbArcs);
 
    /*****************************
    Surcharge de l'operateur =
    ******************************
    Entrée : CGrapheOperation & GRAGrapheOperation
    Necessité : néant
    Sortie : CGrapheOperation &
    Entraine : modification de l'objet a gauche du signe
    *****************************/
    CGrapheOperation & CGrapheOperation::operator=(CGrapheOperation & GRAGrapheOperation);
 
    /*****************************
    Destructeur par défaut
    ******************************
    Entrée : néant
    Necessité : néant
    Sortie : néant
    Entraine : l'objet est détruit
    *****************************/
    ~CGrapheOperation();
 
    // Methodes
 
    /*****************************
    Methode : Inverser un graphe
    ******************************
    Entrée : neant
    Necessité : neant
    Sortie : CGrapheOperation *
    Entraine : le graphe de sortie est inverse
    *****************************/
    CGrapheOperation * GRAInverserGraphe();
};
#endif