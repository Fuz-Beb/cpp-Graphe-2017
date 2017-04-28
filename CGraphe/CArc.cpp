#include "CArc.h"

/*****************************
Constructeur par defaut
******************************
Entree : neant
Necessite : neant
Sortie : neant
Entraine : l'objet en cours est initialise
*****************************/
CArc::CArc() 
{
	uiARCDestination = 0;
}

/*****************************
Constructeur de recopie
******************************
Entree : CArc & arc
Necessite : neant
Sortie : neant
Entraine : l'objet en parametre est recopie et initialise dans un nouvel objet
*****************************/
CArc::CArc(CArc & arc)
{
	uiARCDestination = arc.uiARCDestination;
}

/*****************************
Constructeur de confort
******************************
Entree : unsigned int uiDestination
Necessite : neant
Sortie : neant
Entraine : l'objet en cours est initialise
*****************************/
CArc::CArc(unsigned int uiNumDestination)
{
	uiARCDestination = uiNumDestination;
}

/*****************************
Surcharge de l'operateur =
******************************
Entree : CArc & ARCArc
Necessite : neant
Sortie : CArc &
Entraine : modification de l'objet a gauche du signe
*****************************/
CArc & CArc::operator=(CArc & ARCArc)
{
	uiARCDestination = ARCArc.uiARCDestination;
}

/*****************************
Destructeur par defaut
******************************
Entree : neant
Necessite : neant
Sortie : neant
Entraine : l'objet est detruit
*****************************/
CArc::~CArc()
{
}

/*****************************
Methode : Lire Destination
******************************
Entree : neant
Necessite : neant
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
Entree : unsigned int uiDestination
Necessite : neant
Sortie : neant
Entraine : affecte le parametre a l'attribut
*****************************/
void CArc::ARCSetDestination(unsigned int uiDestination) 
{
	uiARCDestination = uiDestination;
}
