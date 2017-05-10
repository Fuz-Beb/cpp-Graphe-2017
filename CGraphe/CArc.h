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
	Constructeur par d�faut
	******************************
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
	*****************************/
	explicit CArc();

	/*****************************
	Constructeur de recopie
	******************************
	Entr�e : CArc & arc
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en param�tre est recopi� et initialis� dans un nouvel objet
	*****************************/
	explicit CArc(CArc & arc);

	/*****************************
	Constructeur de confort
	******************************
	Entr�e : unsigned int uiNumDestination
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : l'objet en cours est initialis�
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
	Entr�e : n�ant
	Necessit� : n�ant
	Sortie : unsigned int uiDestination
	Entraine : retourne l'attribut
	*****************************/
	unsigned int ARCGetDestination();

	/*****************************
	Methode : Modifier Destination
	******************************
	Entr�e : unsigned int uiNumDestination
	Necessit� : n�ant
	Sortie : n�ant
	Entraine : affecte le param�tre � l'attribut
	*****************************/
	void ARCSetDestination(unsigned int uiNumDestination);
};
#endif