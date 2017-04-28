#ifndef C_PARSE_H
#define C_PARSE_H

#include <fstream>

using namespace std;

class CParse
{
private:
	// Attributs
	char * psPARChemin;
	FILE * pPARFichier;

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
	explicit CParse();

	/*****************************
	Constructeur de confort
	******************************
	Entrée : char * psChemin
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CParse(char * psChemin);

	/*****************************
	Destructeur par défaut
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : l'objet est détruit
	*****************************/
	~CParse();

	// Accesseurs

	/*****************************
	Methode : Lire Chemin
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : char *
	Entraine : retourne le chemin de l'attribut
	*****************************/
	char * PARLireChemin();

	/*****************************
	Methode : Modifier Chemin
	******************************
	Entrée : char * sParam
	Necessité : néant
	Sortie : néant
	Entraine : modification de l'attribut sPARChemin
	*****************************/
	void PARModifierChemin(char * psParam);

	/*****************************
	Methode : Ouvrir Fichier
	******************************
	Entrée : char * sChaine
	Necessité : Fichier
	Sortie : néant
	Entraine : ouverture un fichier
	*****************************/
	void PAROuvrirFichier(char * psParam);

	/*****************************
	Methode : Fermer Fichier
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : néant
	Entraine : Fermeture du fichier
	*****************************/
	void PARFermerFicher();

	// Méthodes

	/*****************************
	Methode : Lire Ligne
	******************************
	Entrée : néant
	Necessité : Méthode Traiter fichier / Ouvrir fichier
	Sortie : char *
	Entraine : lecture d'une ligne du fichier et retourne sur le tas une chaîne
	*****************************/
	char * PARLireLigne();

	/*****************************
	Methode : SubString
	******************************
	Entrée : char * sParam, unsigned int uiDebut, unsigned int uiTaille
	Necessité : néant
	Sortie : char *
	Entraine : permet d'extraire une chaîne d'une position à une autre
	*****************************/
	char * PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille);

	/*****************************
	Methode : Concatener deux chaines
	******************************
	Entrée : const char * sStr1, const char * sStr2
	Necessité : néant
	Sortie : char *
	Entraine : retourne sur le tas la concatenation des deux chaînes
	*****************************/
	char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2);

	/*****************************
	Methode : Convertir Chaine Minuscule
	******************************
	Entrée : char * sChaine
	Necessité : néant
	Sortie : néant
	Entraine : convertir la chaine en paramètre en minuscule
	*****************************/
	void PARConvertirStrMinusc(char * psParam);

	/*****************************
	Methode : Convertir un char en minuscule
	******************************
	Entrée : char cParam
	Necessité : Méthode Ouvrir fichier
	Sortie : char
	Entraine : Conversion d'un char en char minuscule
	*****************************/
	char PARConvertirCharMinusc(char cParam);

	/*****************************
	Methode : Rechercher un caractère dans une chaine
	******************************
	Entrée : char sCaractere, char * psChaine
	Necessité : Méthode Ouvrir fichier
	Sortie : int
	Entraine : retourne la position du caractere
	*****************************/
	int PARRechercheCaractere(char sCaractere, char * psChaine);

	/*****************************
	Methode : Recuperer la chaine presente apres le premier caractere '=' rencontre
	******************************
	Entrée : char * psChaineAvantEgal, char * sBuffer
	Necessité : Méthode Ouvrir fichier
	Sortie : int
	Entraine : retourne le int apres le caractere '='
	*****************************/
	int PARValeurApresSigneEgal(char * psChaineAvantEgal, char * sBuffer);

	/*****************************
	Methode : Compare deux chaines de caractères
	******************************
	Entrée : char * psChaineUn, char * psChaineDeux
	Necessité : Méthode Ouvrir fichier
	Sortie : boolean
	Entraine : retourne true si les deux chaines sont identiques et faux sinon
	*****************************/
	int PARCompareChaine(char * psChaineUn, char * psChaineDeux);
};
#endif
