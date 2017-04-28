#include "CGraphe.h"
#include "CGrapheOperation.h"
#include "CParseGraphe.h"
#include "CException.h"
#include <stdio.h>

#include <vld.h>
void main(unsigned int argc, char *argv[])
{
	try {
		// Exeception si l'utilisateur n'a pas renseigné de nom de fichier
		if (argc < 2)
			throw CException(ECHECOUVERTUREFICHIER, "Aucun nom de fichier n'a ete fourni en parametre");
	} catch (CException EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}

	// Allocations
	CGrapheOperation ** ppqGRAGraphe = (CGrapheOperation **) malloc (sizeof(CGrapheOperation *) * (argc - 1));
	if (ppqGRAGraphe == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");
	CGrapheOperation ** ppqGRAGrapheInverse = (CGrapheOperation **) malloc (sizeof(CGrapheOperation *) * (argc - 1));
	if (ppqGRAGrapheInverse == nullptr)
		throw CException(ECHECALLOCATION, "Echec de l'allocation");

	CParseGraphe * ppqPARparse = nullptr;

	unsigned int uiBoucleTableau = 0;

	try {
		for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++) {
			ppqPARparse = new CParseGraphe();
			if (ppqPARparse == nullptr)
				throw CException(ECHECALLOCATION, "Echec de l'allocation");

			printf("\n\n ------ GRAPHE NON INVERSE ------ \n\n");
			ppqPARparse->PAGTraiterFichier(argv[uiBoucleTableau + 1]);
			ppqGRAGraphe[uiBoucleTableau] = ppqPARparse->PAGRetournerGraphe();
			ppqGRAGrapheInverse[uiBoucleTableau] = ppqGRAGraphe[uiBoucleTableau]->GRAInverserGraphe();
			printf("\n\n ------ GRAPHE INVERSE ------ \n\n");
			ppqGRAGrapheInverse[uiBoucleTableau]->GRAAfficherGraphe();
		}
	} catch (CException & EXCObjet) {
		std::cerr << "Code d'erreur : " << EXCObjet.EXCLectureCode() << std::endl << EXCObjet.EXCLectureMessage() << std::endl;
	}

	unsigned int uiBoucleSommet = 0, uiNbSommet = 0;


	// Désallocation mémoire
	for (uiBoucleTableau = 0 ; uiBoucleTableau < argc -1 ; uiBoucleTableau++) {
		delete(ppqGRAGraphe[uiBoucleTableau]);
		delete(ppqGRAGrapheInverse[uiBoucleTableau]);
	}

	delete(ppqPARparse);
	delete(ppqGRAGraphe);
	delete(ppqGRAGrapheInverse);
}