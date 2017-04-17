/**
 * \file Entraineur.cpp
 * \brief Fonctions pour manipuler la classe Entraineur
 * \author Charles-David Lachance
 */

#include "Date.h"
#include "validationFormat.h"
#include "Entraineur.h"
#include "Personne.h"
namespace tp {
using namespace util;
using namespace std;
/**
 * \brief Constructeur de la classe Entraineur
 *
 * \param nom de la personne, prénom de la personne, date de naissance de la personne, numéro de téléphone de la personne, son numéro de RAMQ et son sexe. L'entraineur doit être majeur.
 * \return Retourne un object Entraineur
 */
Entraineur::Entraineur(const string& p_nom,
		const string& p_prenom,
		const Date& p_dateNaissance,
		const string& p_telephone,
		const string& p_numRAMQ,
		char p_sexe)
:Personne(p_nom, p_prenom, p_dateNaissance, p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone) == true);
	PRECONDITION(util::validerFormatNom(p_nom) == true);
	PRECONDITION(util::validerFormatNom(p_prenom) == true);
	PRECONDITION(Date() - p_dateNaissance >= 6574)
	m_sexe = p_sexe;
	m_numRAMQ = p_numRAMQ;
}
/**
 * \brief Requiers le nom d'un objet Entraineur
 *
 * \return Retourne le numéro de RAMQ de l'entraineur
 */
string Entraineur::reqNumRAMQ() const
{
	return m_numRAMQ;
}
/**
 * \brief Clone d'un Entraineur
 *
 * \return Retourne un pointeur vers un objet Entraineur
 */
Personne* Entraineur::clone() const
{
	return new Entraineur(*this);
}
/**
 * \brief Requiers les information d'un objet Entraineur
 *
 * \return Retourne les informations formatées d'un Entraineur
 */
string Entraineur::reqPersonneFormate() const
{
	return "Nom               : "+ reqNom() + "\n"
		  +"Prenom            : "+ reqPrenom() + "\n"
		  +"Date de naissance : "+ reqDateNaissance() + "\n"
		  +"Telephone         : "+ reqTelephone() + "\n"
		  +"Numero de RAMQ    : "+ reqNumRAMQ() + "\n"
		  +"-----------------------------";
}

}
