/**
 * \file Joueur.h
 * \brief Header de la classe Joueur
 * \author Charles-David Lachance
 */
#ifndef JOUEUR_H_
#define JOUEUR_H_
#include "validationFormat.h"
#include "Date.h"
#include "Personne.h"
#include <string>
#include <sstream>

namespace tp
{
/**
 * \class Joueur
 * \brief Classe permettant de prendre les informations d'un joueur comme son nom, prénom, date de naissance, numéro de téléphone et sa position
 */
class Joueur: public Personne
{
public:
	/*Constructeur*/
	Joueur(const std::string& p_nom,
			const std::string& p_prenom,
			const util::Date& p_dateNaissance,
			const std::string& p_telephone,
			const std::string& p_position);

	/*Méthodes d'accès*/
	std::string reqPosition() const;
	std::string reqPersonneFormate() const;

	Personne* clone() const;

protected:

	std::string m_position;
};
}
#endif /* JOUEUR_H_ */



