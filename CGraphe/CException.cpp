#include "CException.h"

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CException::CException()
{
	uiEXCCode = 0;
	psEXCMessage = nullptr;
}

/*****************************
Constructeur à deux arguments
******************************
Entrée : unsigned int uiCodeErreur, char * psMessageErreur
Necessité : néant
Sortie : néant
Entraine : le paramètre est recopié et ainsi l'objet en cours est initialisé
*****************************/
CException::CException(unsigned int uiCodeErreur, char * psMessageErreur)
{
	uiEXCCode = uiCodeErreur;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessageErreur) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psEXCMessage, psMessageErreur, strlen(psMessageErreur) + 1);
}

/*****************************
Constructeur de recopie
******************************
Entrée : CException & EXCObjet
Necessité : néant
Sortie : néant
Entraine : l'object en cours en initialisé avec les même attributs que l'objet passé en paramètre
*****************************/
CException::CException(CException & EXCObjet)
{
	uiEXCCode = EXCObjet.uiEXCCode;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(EXCObjet.psEXCMessage) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psEXCMessage, EXCObjet.psEXCMessage, strlen(EXCObjet.psEXCMessage) + 1);
}

/*****************************
Destructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est détruit
*****************************/
CException::~CException()
{
	if (psEXCMessage != nullptr)
		delete psEXCMessage;
}

/*****************************
Methode : Lecture du code d'erreur
*****************************
Entrée : néant
Necessité : néant
Sortie : unsigned int
Entraine : retourne le code d'erreur
*****************************/
unsigned int CException::EXCLectureCode()
{
	return uiEXCCode;
}

/*****************************
Methode : Modification du code d'erreur
******************************
Entrée : unsigned int uiCodeErreur
Necessité : néant
Sortie : néant
Entraine : modification du code d'erreur
*****************************/
void CException::EXCEcritureCode(unsigned int uiCodeErreur)
{
	uiEXCCode = uiCodeErreur;
}

/*****************************
Methode : Lecture du message d'erreur
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : affiche le message d'erreur
*****************************/
char * CException::EXCLectureMessage()
{
	return psEXCMessage;
}

/*****************************
Methode : Modification du message d'erreur
******************************
Entrée : char * psMessage
Necessité : néant
Sortie : néant
Entraine : modification du message d'erreur
*****************************/
void CException::EXCEcritureMessage(char * psMessage)
{
	if (psEXCMessage == nullptr)
		delete psEXCMessage;

	psEXCMessage = (char*) malloc(sizeof(char) * strlen(psMessage) + 1);
	if (psEXCMessage == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	
	strncpy(psEXCMessage, psMessage, strlen(psMessage) + 1);
}