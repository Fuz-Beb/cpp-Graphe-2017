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
	PAGgraphe = CGrapheOperation();
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
	return new CGrapheOperation(PAGgraphe);
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
	return uiPAGNbSommets;
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
	return uiPAGNbArcs;
}

/*****************************
Methode : Traiter Sommets
******************************
Entree : neant
Necessite : methode Traiter fichier / Ouvrir fichier
Sortie : neant
Entraine : La lecture du fichier et creation des sommets du graphe
*****************************/
void CParseGraphe::PAGTraiterSommets()
{
	// Initialisation du buffer ligne par ligne
	char * psBuffer = nullptr;

	// Verification que la declaration des sommets est bien a la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "sommets=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Sommets=[");

	// Debut de la recuperation de la valeur de chaque sommets
	for (unsigned int uiBoucleSommets = 1 ; uiBoucleSommets <= uiPAGNbSommets ; uiBoucleSommets++) {
		psBuffer = PARLireLigne();
		
		if (PARCompareChaine(PARSubString(psBuffer, 0, 1), "]")) {
			delete(psBuffer);
			throw CException(FORMATFICHIERINCORRECTE, "Il manque un sommet dans le fichier");
		} else
			PAGgraphe.GRAAjoutSommet(PARValeurApresSigneEgal("numero", psBuffer), nullptr, nullptr);
	}

	// Verification de la fin de la declaration des sommets
	psBuffer = PARLireLigne();

	// Verification que c'est bien la fin de la declaration des sommets
	if (!PARCompareChaine(PARSubString(psBuffer, 0, 1), "]")) {
		delete(psBuffer);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des sommets [");
	}

	delete(psBuffer);
}

/*****************************
Methode : Traiter Arcs
******************************
Entree : neant
Necessite : methode Traiter fichier / Ouvrir fichier
Sortie : neant
Entraine : la lecture du fichier et creation des arcs du graphe
*****************************/
void CParseGraphe::PAGTraiterArcs()
{
	// Initialisation du buffer ligne par ligne
	char * psBuffer = nullptr;

	// Initialisation Variables d'indice de boucles
	unsigned int uiBufferDebut, uiBufferFin;

	// Verification que la declaration des arcs est bien a la suite du fichier
	if (!PARCompareChaine(PARLireLigne(), "arcs=[\n"))
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de Arcs=[");

	// Debut de la recuperation de la valeur de chaque sommets
	for (unsigned int uiBoucleArcs = 1 ; uiBoucleArcs <= uiPAGNbArcs ; uiBoucleArcs++)
	{
		// Lecture d'une ligne contenant la mention debut et fin
		psBuffer = PARLireLigne();

		// Verification qu'il ne manque pas un arc dans le fichier
		if (PARCompareChaine(PARSubString(psBuffer, 0, 1), "]")) {
			delete(psBuffer);
			throw CException(FORMATFICHIERINCORRECTE, "Il manque un arc dans le fichier");
		}

		// Memorisation de l'arc de debut puis de fin
		uiBufferDebut = PARValeurApresSigneEgal("debut", PARSubString(psBuffer, 0, PARRechercheCaractere(',', psBuffer)));
		uiBufferFin = PARValeurApresSigneEgal("fin", PARSubString(psBuffer, PARRechercheCaractere('f', psBuffer), strlen(psBuffer)));

		delete(psBuffer);

		// Ajout des arcs au graphe
		if (PAGgraphe.GRATrouverSommet(uiBufferDebut) == nullptr || PAGgraphe.GRATrouverSommet(uiBufferFin) == nullptr)
			throw CException(FORMATFICHIERINCORRECTE, "Un arc essaye de rejoindre un sommet qui n'existe pas");

		PAGgraphe.GRAAjoutArc(uiBufferFin, PAGgraphe.GRATrouverSommet(uiBufferDebut));
	}

	// Verification de la fin de la declaration des sommets
	psBuffer = PARLireLigne();

	// Verification que c'est bien la fin de la declaration des sommets
	if (!PARCompareChaine(PARSubString(psBuffer, 0, 1), "]")) {
		delete(psBuffer);
		throw CException(FORMATFICHIERINCORRECTE, "Lecture incorrect de la fin des arcs [");
	}

	delete(psBuffer);
}

/*****************************
Methode : Traiter fichier
******************************
Entree : char * psChemin
Necessite : neant
Sortie : neant
Entraine : La lecture du fichier et creation de la matrice associee
*****************************/
void CParseGraphe::PAGTraiterFichier(char * psChemin)
{
	// Mise en place de l'ouverture du fichier
	PARModifierChemin(psChemin);
	PAROuvrirFichier(psChemin);

	// Lecture et ecriture attribut du nombre de sommets
	uiPAGNbSommets = PARValeurApresSigneEgal("nbsommets", PARLireLigne());

	// Lecture et ecriture attribut du nombre d'arcs
	uiPAGNbArcs = PARValeurApresSigneEgal("nbarcs", PARLireLigne());
	
	// Creation du graphe selon sa taille lu
	PAGgraphe = CGrapheOperation();

	// Initialisation des sommets du graphe
	PAGTraiterSommets();

	// Initialisation des arcs du graphe
	PAGTraiterArcs();

	// Affichage du graphe
	PAGgraphe.GRAAfficherGraphe();
}