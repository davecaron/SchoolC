/**
 * \file Personne.cpp
 * \brief Fonctions pour manipuler la classe personne
 *  \author Charles-David Lachance
 */

#include <iostream>
#include "Personne.h"
#include "validationFormat.h"
#include "ContratException.h"
#include "Date.h"

namespace tp
{
using namespace std;
/**
 * \brief Constructeur de la classe personne
 *
 * \param nom de la personne, prénom de la personne, date de naissance de la personne, numéro de téléphone de la personne
 * \return Retourne un object Personne
 */
Personne::Personne(const string& p_nom,
		 const string& p_prenom,
		 const util::Date& p_dateNaissance,
		 const string& p_telephone)
: m_nom(p_nom), m_prenom(p_prenom), m_dateNaissance(p_dateNaissance), m_telephone(p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone) == true);
	PRECONDITION(util::validerFormatNom(p_nom) == true);
	PRECONDITION(util::validerFormatNom(p_prenom) == true);
}



/**
 * \brief Requiers le nom d'un objet Personne
 *
 * \return Retourne le nom de la personne
 */
string Personne::reqNom() const
{
	return m_nom;
}
/**
 * \brief Requiers le prénom d'un objet Personne
 *
 * \return Retourne le prénom de la personne
 */
string Personne::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief Requiers la date de naissance d'un objet Personne
 *
 * \return Retourne la date de naissance formatée d'une personne
 */
string Personne::reqDateNaissance() const
{
	return m_dateNaissance.reqDateFormatee();
}

/**
 * \brief Requiers le numéro de téléphone d'un objet Personne
 *
 * \return Retourne le numéro de téléphone d'une personne
 */
string Personne::reqTelephone() const
{
	return m_telephone;
}

/**
 * \brief Requiers les information d'un objet Personne
 *
 * \return Retourne les informations formatées d'une personne
 */
string Personne::reqPersonneFormate() const
{
	return "Nom               : "+ reqNom() + "\n"
		  +"Prenom            : "+ reqPrenom() + "\n"
		  +"Date de naissance : "+ reqDateNaissance() + "\n"
		  +"Telephone         : "+ reqTelephone() + "\n";
}

/**
 * \brief Assigne un nouveau numéro de téléphone à un objet Personne
 *
 * \param Prends en entrée le nouveau numéro de téléphone
 */
void Personne::asgTelephone(const std ::string& p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone) == false)

		m_telephone = p_telephone;
}

/**
 * \brief Opérateur permettant de vérifier si deux personnes sont identiques.
 *
 * \param Prends en entrée une personne
 * \return Retourne vrai si les deux personnes sont identiques.
 */
bool Personne::operator ==(const Personne& unePersonne)
{
	if (unePersonne.reqNom() != m_nom)
	{
		return false;
	}

	if (unePersonne.reqPrenom() != m_prenom)
	{
		return false;
	}
	if (unePersonne.reqDateNaissance() != m_dateNaissance.reqDateFormatee())
	{
		return false;
	}

	return true;
}
}

