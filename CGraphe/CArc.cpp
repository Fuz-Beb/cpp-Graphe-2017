#include "CArc.h"

/*****************************
Constructeur par d�faut
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
*****************************/
CArc::CArc() 
{
	uiARCDestination = 0;
}

/*****************************
Constructeur de recopie
******************************
Entr�e : CArc & arc
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
*****************************/
CArc::CArc(CArc & arc)
{
	uiARCDestination = arc.uiARCDestination;
}

/*****************************
Constructeur de confort
******************************
Entr�e : unsigned int uiNumDestination
Necessit� : n�ant
Sortie : n�ant
Entraine : l'objet en cours est initialis�
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
	return *this;
}

/*****************************
Methode : Lire Destination
******************************
Entr�e : n�ant
Necessit� : n�ant
Sortie : unsigned int uiARCDestination
Entraine : retourne l'attribut
*****************************/
unsigned int CArc::ARCGetDestination()
{
	return uiARCDestination;
}

/*****************************
Methode : Modifier Destination
******************************
Entr�e : unsigned int uiNumDestination
Necessit� : n�ant
Sortie : n�ant
Entraine : affecte le param�tre � l'attribut
*****************************/
void CArc::ARCSetDestination(unsigned int uiNumDestination) 
{
	uiARCDestination = uiNumDestination;
}