#include "CParseGraphe.h"
#include "CException.h"

/*****************************
Constructeur par defaut
******************************
Entree : neant
Necessite : neant
Sortie : neant
Entraine : l'objet en cours est initialise
*****************************/
CParseGraphe::CParseGraphe()
{
	graGraphe = CGrapheOperation();
}

/*****************************
Methode : Retourner Graphe
******************************
Entree : neant
Necessite : neant
Sortie : Retourne un pointeur sur l'attribut de graGraphe
Entraine : Creation d'un objet/pointeur en appellant le constructeur de recopie de CGraphe
*****************************/
CGrapheOperation * CParseGraphe::PAGRetournerGraphe()
{
	return new CGrapheOperation(graGraphe);
}

/*****************************
Methode : Lire Nombre Sommets
******************************
Entree : neant
Necessite : neant
Sortie : unsigned int
Entraine : Retourne le nombre de sommets precedemment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbSommets()
{
	return uiNbSommets;
}

/*****************************
Methode : Lire Nombre Arcs
******************************
Entree : neant
Necessite : neant
Sortie : unsigned int
Entraine : Retourne le nombre d'arcs qui a ete precedemment lu
*****************************/
unsigned int CParseGraphe::PAGLireNbArcs()
{
	return uiNbArcs;
}

/*****************************
Methode : Traiter Sommets
******************************
Entree : neant
Necessite :  Methode Traiter fichier / Ouvrir fichier
Sortie : neant
Entraine : La lecture du fichier et creation des sommets du graphe
*****************************/
void CParseGraphe::PAGTraiterSommets()
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = nullptr;

	// Verification que la declaration des sommets est bien e la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "sommets=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Sommets=[");

	// Debut de la recuperation de la valeur de chaque sommets
	for (unsigned int uiBoucleSommets = 1 ; uiBoucleSommets <= uiNbSommets ; uiBoucleSommets++) {
		sBuffer = PARLireLigne();
		
		if (PARCompareChaine(PARSubString(sBuffer, 0, 1), "]")) {
			delete(sBuffer);
			throw CException(FORMATFICHIERINCORRECTE, "Il manque un sommet dans le fichier");
		} else
			graGraphe.GRAAjoutSommet(PARValeurApresSigneEgal("numero", sBuffer), nullptr, nullptr);
	}

	// Verification de la fin de la declaration des sommets
	sBuffer = PARLireLigne();

	// Verification que c'est bien la fin de la declaration des sommets
	if (!PARCompareChaine(PARSubString(sBuffer, 0, 1), "]")) {
		delete(sBuffer);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des sommets [");
	}

	delete(sBuffer);
}

/*****************************
Methode : Traiter Arcs
******************************
Entree : neant
Necessite :  Methode Traiter fichier / Ouvrir fichier
Sortie : neant
Entraine : La lecture du fichier et creation des arcs du graphe
*****************************/
void CParseGraphe::PAGTraiterArcs()
{
	// Initialisation du buffer ligne par ligne
	char * sBuffer = nullptr;

	// Initialisation Variables d'indice de boucles
	unsigned int uiBufferDebut, uiBufferFin;

	// Verification que la declaration des arcs est bien a la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "arcs=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Arcs=[");

	// Debut de la recuperation de la valeur de chaque sommets
	for (unsigned int uiBoucleArcs = 1 ; uiBoucleArcs <= uiNbArcs ; uiBoucleArcs++)
	{
		// Lecture d'une ligne contenant la mention debut et fin
		sBuffer = PARLireLigne();

		// Verification qu'il ne manque pas un arc dans le fichier
		if (PARCompareChaine(PARSubString(sBuffer, 0, 1), "]")) {
			delete(sBuffer);
			throw CException(FORMATFICHIERINCORRECTE, "Il manque un arc dans le fichier");
		}

		// Memorisation de l'arc de debut puis de fin
		uiBufferDebut = PARValeurApresSigneEgal("debut", PARSubString(sBuffer, 0, PARRechercheCaractere(',', sBuffer)));
		uiBufferFin = PARValeurApresSigneEgal("fin", PARSubString(sBuffer, PARRechercheCaractere('f', sBuffer), strlen(sBuffer)));

		delete(sBuffer);

		// Ajout des arcs au graphe
		if (graGraphe.GRATrouverSommet(uiBufferDebut) == nullptr || graGraphe.GRATrouverSommet(uiBufferFin) == nullptr)
			throw CException(FORMATFICHIERINCORRECTE, "Un arc essaye de rejoindre un sommet qui n'existe pas");

		graGraphe.GRAAjoutArc(uiBufferFin, graGraphe.GRATrouverSommet(uiBufferDebut));
	}

	// Verification de la fin de la declaration des sommets
	sBuffer = PARLireLigne();

	// Verification que c'est bien la fin de la declaration des sommets
	if (!PARCompareChaine(PARSubString(sBuffer, 0, 1), "]")) {
		delete(sBuffer);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des arcs [");
	}

	delete(sBuffer);
}

/*****************************
Methode : Traiter fichier
******************************
Entree : char * sChemin
Necessite : neant
Sortie : neant
Entraine : La lecture du fichier et creation de la matrice associee
*****************************/
void CParseGraphe::PAGTraiterFichier(char * sChemin)
{
	// Mise en place de l'ouverture du fichier
	PARModifierChemin(sChemin);
	PAROuvrirFichier(sChemin);

	// Lecture et ecriture attribut du nombre de sommets
	uiNbSommets = PARValeurApresSigneEgal("nbsommets", PARLireLigne());

	// Lecture et ecriture attribut du nombre d'arcs
	uiNbArcs = PARValeurApresSigneEgal("nbarcs", PARLireLigne());
	
	// Creation du graphe selon sa taille lu
	graGraphe = CGrapheOperation();

	// Initialisation des sommets du graphe
	PAGTraiterSommets();

	// Initialisation des arcs du graphe
	PAGTraiterArcs();

	// Affichage du graphe
	graGraphe.GRAAfficherGraphe();
}