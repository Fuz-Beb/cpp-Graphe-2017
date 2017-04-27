#include "CGraphe.h"
#include "CGrapheOperation.h"
#include "CParseGraphe.h"
#include "CException.h"
#include <stdio.h>

#include <vld.h>
void main(unsigned int argc, char *argv[])
{
	// Exeception si l'utilisateur n'a pas renseigné de nom de fichier
	if (argc < 2)
		throw CException(ECHECOUVERTUREFICHIER, "Aucun nom de fichier n'a ete fourni en parametre");

	// Allocations
	CParseGraphe ** ppPARparse = (CParseGraphe**) malloc(sizeof(CParseGraphe*) * (argc - 1));
	if (ppPARparse == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	CGrapheOperation ** ppGRAGraphe = (CGrapheOperation **) malloc (sizeof(CGrapheOperation *) * (argc - 1));
	if (ppGRAGraphe == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	unsigned int uiBoucleTableau;

	try {
		for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau += 2) {
			ppPARparse[uiBoucleTableau] = new CParseGraphe();
			printf("\n\n ------ GRAPHE NON INVERSE ------ \n\n");
			ppPARparse[uiBoucleTableau]->PAGTraiterFichier(argv[uiBoucleTableau + 1]);
			ppGRAGraphe[uiBoucleTableau] = ppPARparse[uiBoucleTableau]->PAGRetournerGraphe();
			ppGRAGraphe[uiBoucleTableau + 1] = ppGRAGraphe[uiBoucleTableau]->GRAInverserGraphe();
			printf("\n\n ------ GRAPHE INVERSE ------ \n\n");
			ppGRAGraphe[uiBoucleTableau + 1]->GRAAfficherGraphe();
		}
	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}

	// Désallocation mémoire
	for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++) {
		delete(ppGRAGraphe[uiBoucleTableau]);
		delete(ppPARparse[uiBoucleTableau]);
	}
	delete(ppPARparse);
	//delete(ppGRAGraphe);
}

