#include "CArc.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CArc::CArc() 
{
	uiARCDestination = 0;
}

/*****************************
Constructeur de recopie
******************************
Entrée : CArc & arc
Necessité : néant
Sortie : néant
Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
*****************************/
CArc::CArc(CArc & arc)
{
	uiARCDestination = arc.uiARCDestination;
}

/*****************************
Constructeur de confort
******************************
Entrée : unsigned int uiDestination
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CArc::CArc(unsigned int uiNumDestination)
{
	uiARCDestination = uiNumDestination;
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CArc::~CArc()
{
}

/*****************************
Methode : Lire Destination
******************************
Entrée : néant
Necessité : néant
Sortie : unsigned int uiDestination
Entraine : retourne l'attribut
*****************************/
unsigned int CArc::ARCGetDestination()
{
	return uiARCDestination;
}

/*****************************
Methode : Modifier Destination
******************************
Entrée : unsigned int uiDestination
Necessité : néant
Sortie : néant
Entraine : affecte le paramètre à l'attribut
*****************************/
void CArc::ARCSetDestination(unsigned int uiDestination) 
{
	uiARCDestination = uiDestination;
}