/**
 * \file Personne.h
 * \brief Header de la classe Personne
 * \author Charles-David Lachance
 */


#ifndef PERSONNE_H_
#define PERSONNE_H_
#include "validationFormat.h"
#include "Date.h"



namespace tp{

/**
 * \class Personne
 * \brief Classe permettant de prendre les informations d'une personne comme son nom, prénom, date de naissance et numéro de téléphone
 */
class Personne {
public:
/*Constructeur*/
Personne(const std::string& p_nom,
			 const std::string& p_prenom,
			 const util::Date& p_dateNaissance,
			 const std::string& p_telephone);

/*Destructeur*/
virtual ~Personne() {} ;

/*Méthodes d'accès*/
		std::string reqNom() const;
		std::string reqPrenom() const;
		std::string reqDateNaissance() const;
		std::string reqTelephone() const;
virtual std::string reqPersonneFormate() const;


/*Méthode de comparaison*/
	bool operator==(const Personne& unePersonne);

	/*Méthode d'assignation*/
		void asgTelephone(const std::string& p_telephone);

virtual Personne* clone() const =0;

protected:


	std::string m_nom;
	std::string m_prenom;
	util::Date m_dateNaissance;
	std::string m_telephone;
};
}
#endif /* PERSONNE_H_ */
