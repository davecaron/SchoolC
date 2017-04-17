/**
 * \file Joueur.h
 * \brief Header de la classe Entraineur
 * \author Charles-David Lachance
 */
#ifndef ENTRAINEUR_H_
#define ENTRAINEUR_H_
#include "validationFormat.h"
#include "Date.h"
#include "Personne.h"
#include <string>
#include <sstream>

namespace tp
{

class Entraineur: public Personne
{
public:
	/*Constructeur*/
	Entraineur(const std::string& p_nom,
			const std::string& p_prenom,
			const util::Date& p_dateNaissance,
			const std::string& p_telephone,
			const std::string& p_numRAMQ,
			char p_sexe);

	/*Méthodes d'accès*/
	std::string reqNumRAMQ() const;
	std::string reqPersonneFormate() const;

	Personne* clone() const;

protected:

	std::string m_numRAMQ;
	char m_sexe;
};
}
#endif /* ENTRAINEUR_H_ */
