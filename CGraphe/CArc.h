#ifndef C_ARC_H
#define C_ARC_H

class CArc
{
private:
	// Attribut
	unsigned int uiARCDestination;

public:
	// Constructeurs / Destructeurs

	/*****************************
	Constructeur par defaut
	******************************
	Entree : neant
	Necessite : neant
	Sortie : neant
	Entraine : l'objet en cours est initialise
	*****************************/
	explicit CArc();

	/*****************************
	Constructeur de recopie
	******************************
	Entree : CArc & arc
	Necessite : neant
	Sortie : neant
	Entraine : l'objet en paramètre est recopie et initialise dans un nouvel objet
	*****************************/
	explicit CArc(CArc & arc);

	/*****************************
	Constructeur de confort
	******************************
	Entree : unsigned int uiDestination
	Necessite : neant
	Sortie : neant
	Entraine : l'objet en cours est initialise
	*****************************/
	explicit CArc(unsigned int uiNumDestination);
	
	/*****************************
	Surcharge de l'operateur =
	******************************
	Entree : unsigned int uiDestination
	Necessite : neant
	Sortie : neant
	Entraine : l'objet en cours est initialise
	*****************************/
	CArc::operator=(CArc & ARCArc)

	/*****************************
	Destructeur par defaut
	******************************
	Entree : neant
	Necessite : neant
	Sortie : neant
	Entraine : l'objet est detruit
	*****************************/
	~CArc();

	// Accesseurs

	/*****************************
	Methode : Lire Destination
	******************************
	Entree : neant
	Necessite : neant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int ARCGetDestination();

	/*****************************
	Methode : Modifier Destination
	******************************
	Entree : unsigned int uiDestination
	Necessite : neant
	Sortie : neant
	Entraine : affecte le parametre a l'attribut
	*****************************/
	void ARCSetDestination(unsigned int uiDestination);
};
#endif
