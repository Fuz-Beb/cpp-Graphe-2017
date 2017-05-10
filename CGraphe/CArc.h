#ifndef C_ARC_H
#define C_ARC_H

class CArc
{
private:
	// Attributs
	unsigned int uiARCDestination;

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
	explicit CArc();

	/*****************************
	Constructeur de recopie
	******************************
	Entrée : CArc & arc
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en paramètre est recopié et initialisé dans un nouvel objet
	*****************************/
	explicit CArc(CArc & arc);

	/*****************************
	Constructeur de confort
	******************************
	Entrée : unsigned int uiNumDestination
	Necessité : néant
	Sortie : néant
	Entraine : l'objet en cours est initialisé
	*****************************/
	explicit CArc(unsigned int uiNumDestination);

	/*****************************
	Surcharge de l'operateur =
	******************************
	Entree : CArc & ARCArc
	Necessite : neant
	Sortie : CArc &
	Entraine : modification de l'objet a gauche du signe
	*****************************/
	CArc & operator=(CArc & ARCArc);

	// Accesseurs

	/*****************************
	Methode : Lire Destination
	******************************
	Entrée : néant
	Necessité : néant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int ARCGetDestination();

	/*****************************
	Methode : Modifier Destination
	******************************
	Entrée : unsigned int uiNumDestination
	Necessité : néant
	Sortie : néant
	Entraine : affecte le paramètre à l'attribut
	*****************************/
	void ARCSetDestination(unsigned int uiNumDestination);
};
#endif