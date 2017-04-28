#include "CParse.h"
#include "CException.h"
#pragma warning(disable:4996)

/*****************************
Constructeur par défaut
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParse::CParse()
{
	psPARChemin = nullptr;
	pPARFichier = nullptr;
}

/*****************************
Constructeur de confort
******************************
Entrée : char * psChemin
Necessité : néant
Sortie : néant
Entraine : l'objet en cours est initialisé
*****************************/
CParse::CParse(char * psChemin)
{
	CParse();
	PARModifierChemin(psChemin);
}

/*****************************
Destructeur par défaut
*****************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : l'objet est détruit
*****************************/
CParse::~CParse()
{
	delete(psPARChemin);
	PARFermerFicher();
}

/*****************************
Methode : Lire Chemin
******************************
Entrée : néant
Necessité : néant
Sortie : char *
Entraine : retourne le chemin de l'attribut
*****************************/
char * CParse::PARLireChemin()
{
	return psPARChemin;
}

/*****************************
Methode : Modifier Chemin
******************************
Entrée : char * sParam
Necessité : néant
Sortie : néant
Entraine : modification de l'attribut sPARChemin
*****************************/
void CParse::PARModifierChemin(char * psParam)
{
	unsigned int uiTaille = strlen(psParam);

	if(psPARChemin != NULL)
		delete(psPARChemin);

	psPARChemin = (char*) calloc(uiTaille + 1, sizeof(char));

	if(psPARChemin == NULL)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	strncpy(psPARChemin, psParam, uiTaille);
}

/*****************************
Methode : Ouvrir Fichier
*****************************
Entrée : char * sChaine
Necessité : Fichier
Sortie : néant
Entraine : ouverture un fichier
*****************************/
void CParse::PAROuvrirFichier(char * psParam)
{
	try {
		pPARFichier = fopen(psParam, "r");

		if(pPARFichier == nullptr)
			throw CException(ECHECOUVERTUREFICHIER, "Echec d'ouverture du fichier");

	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		cout << "Appuyer sur une touche pour quitter le programme";
		cin.get();
		exit(EXIT_FAILURE);
	}
}

/*****************************
Methode : Fermer Fichier
******************************
Entrée : néant
Necessité : néant
Sortie : néant
Entraine : Fermeture du fichier
*****************************/
void CParse::PARFermerFicher()
{
	if(pPARFichier != NULL)
		fclose(pPARFichier);
}

/*****************************
Methode : Lire Ligne
******************************
Entrée : néant
Necessité : Méthode Traiter fichier / Ouvrir fichier
Sortie : char *
Entraine : lecture d'une ligne du fichier et retourne sur le tas une chaîne
*****************************/
char * CParse::PARLireLigne()
{
	try {
		// Position de départ
		unsigned int uiCurseurInitial = ftell(pPARFichier);
		unsigned int uiSizeMaxBuffer = 0;

		// Mise du curseur à la fin du fichier pour le calcul de la taille de la chaine
		fseek(pPARFichier, 0, SEEK_END);

		// Récupération de la taille maximum du buffer
		uiSizeMaxBuffer = ftell(pPARFichier) - uiCurseurInitial + 1;
	
		// Allocation de la chaine avec la "bonne taille"
		char * psBuffer = (char*) malloc (sizeof(char) * uiSizeMaxBuffer);
		if(psBuffer == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		fseek(pPARFichier, uiCurseurInitial, SEEK_SET);

		// Récupération de la ligne
		psBuffer = fgets(psBuffer, uiSizeMaxBuffer, pPARFichier);
	
		if (psBuffer == nullptr)
			throw CException(ECHECLECTURELIGNEFICHIER, "Erreur lors de la lecture d'une ligne du fichier");

		// Mise à l'échelle de la chaine retournée
		psBuffer = (char*) realloc(psBuffer, sizeof(char) * (strlen(psBuffer) + 1));
		if (psBuffer == nullptr)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		return psBuffer;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : SubString
******************************
Entrée : char * sParam, unsigned int uiDebut, unsigned int uiTaille
Necessité : néant
Sortie : char *
Entraine : permet d'extraire une chaîne d'une position à une autre
*****************************/
char * CParse::PARSubString(char * psParam, unsigned int uiDebut, unsigned int uiTaille)
{
	try {
		char * psRetour = (char *) malloc(sizeof(char) * uiTaille + 1);
		if(psRetour == NULL)
			throw CException(ECHECALLOCATION, "Echec de l'allocation");

		memcpy(psRetour, &psParam[uiDebut], uiTaille);
		psRetour[uiTaille] = '\0';

		PARConvertirStrMinusc(psRetour);

		return psRetour;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : Concatener deux chaines
******************************
Entrée : const char * sStr1, const char * sStr2
Necessité : néant
Sortie : char *
Entraine : retourne sur le tas la concatenation des deux chaînes
*****************************/
char * CParse::PARConcatenateString(const char * psStr1, const char * psStr2) 
{
	try {
		size_t lengthStr1 = strlen(psStr1);
		size_t lengthStr2 = strlen(psStr2);
		char * psConcatenate = (char*)malloc(strlen(psStr1) + strlen(psStr2) + 1);

		if(psConcatenate == NULL) {
			free(psConcatenate);
			throw CException(ECHECALLOCATION, "Echec de l'allocation");
		}

		strncpy(psConcatenate, psStr1, lengthStr1);
		strncpy(psConcatenate + lengthStr1, psStr2, lengthStr2);

		return psConcatenate;
	} catch(CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
		return nullptr;
	}
}

/*****************************
Methode : Convertir Chaine Minuscule
******************************
Entrée : char * sChaine
Necessité : néant
Sortie : néant
Entraine : convertir la chaine en paramètre en minuscule
*****************************/
void CParse::PARConvertirStrMinusc(char * psParam)
{
    int uiBoucle = 0;

    while(psParam[uiBoucle] != '\0') {
        psParam[uiBoucle] = PARConvertirCharMinusc(psParam[uiBoucle]);
		uiBoucle++;
	}
}

/*****************************
Methode : Convertir un char en minuscule
******************************
Entrée : char cParam
Necessité : Méthode Ouvrir fichier
Sortie : char
Entraine : Conversion d'un char en char minuscule
*****************************/
char CParse::PARConvertirCharMinusc(char cParam) 
{
    int iTemp = (int)cParam;

    if(iTemp >= 'A' && iTemp <= 'Z') {
		iTemp = iTemp + ('a' - 'A');
        return (char)iTemp;
	}
    else
        return cParam;
}

/*****************************
Methode : Rechercher un caractère dans une chaine
******************************
Entrée : char sCaractere, char * psChaine
Necessité : Méthode Ouvrir fichier
Sortie : int
Entraine : retourne la position du caractere
*****************************/
int CParse::PARRechercheCaractere(char sCaractere, char * psChaine)
{
	unsigned int uiBoucle = 0;

	PARConvertirStrMinusc(psChaine);

	while (uiBoucle < strlen(psChaine) && psChaine[uiBoucle] != '\0')
	{
		if (psChaine[uiBoucle] == sCaractere)
			return uiBoucle;
		uiBoucle++;
	}
	return -1;
}

/*****************************
Methode : Recuperer la chaine presente apres le premier caractere '=' rencontre
******************************
Entrée : char * psChaineAvantEgal, char * sBuffer
Necessité : Méthode Ouvrir fichier
Sortie : int
Entraine : retourne le int apres le caractere '='
*****************************/
int CParse::PARValeurApresSigneEgal(char * psChaineAvantEgal, char * sBuffer) {

	// Déclarations des variables
	char * sRetour = nullptr;
	unsigned int uiReturnValue;

	// Récupération du préfixe a gauche du signe '='
	sRetour = PARSubString(sBuffer, 0, strlen(psChaineAvantEgal));

	// Comparaison du préfixe avec celui donné en paramètre
	if(strcmp(sRetour, psChaineAvantEgal) != 0) {
		delete(sBuffer);
		delete(sRetour);
		throw CException(FORMATFICHIERINCORRECTE, "Erreur : Balise incorrecte dans le fichier");
	}

	delete(sRetour);

	// Récupération de la valeur située à droite du signe '='
	sRetour = PARSubString(sBuffer, PARRechercheCaractere('=', sBuffer) + 1, strlen(sBuffer) - strlen(psChaineAvantEgal));

	if(sRetour == NULL) {
		delete(sBuffer);
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	}

	uiReturnValue = atoi(sRetour);

	delete(sBuffer);
	delete(sRetour);

	return uiReturnValue;
}

/*****************************
Methode : Compare deux chaines de caractères
******************************
Entrée : char * psChaineUn, char * psChaineDeux
Necessité : Méthode Ouvrir fichier
Sortie : boolean
Entraine : retourne true si les deux chaines sont identiques et faux sinon
*****************************/
int CParse::PARCompareChaine(char * psChaineUn, char * psChaineDeux)
{
	if (psChaineUn == nullptr || psChaineDeux == nullptr)
		throw CException(ERREURARGS, "Les deux chaines passées en paramètre ne peuvent pas être null");

	PARConvertirStrMinusc(psChaineUn);

	if (strcmp(psChaineUn, psChaineDeux) != 0) {
		delete(psChaineUn);
		return false;
	}
	else {
		delete(psChaineUn);
		return true;
	}
}