/**
 * \file Joueur.cpp
 * \brief Fonctions pour manipuler la classe Joueur
 * \author Charles-David Lachance
 */
#include "Date.h"
#include "Joueur.h"
#include "Personne.h"
namespace tp {
using namespace util;
using namespace std;

/**
 * \brief Constructeur de la classe Joueur
 *
 * \param nom de la personne, prénom de la personne, date de naissance de la personne, numéro de téléphone de la personne et position du joueur. Le joueur doit être entre 15 et 17 ans.
 * \return Retourne un object Joueur
 */
Joueur::Joueur(const string& p_nom,
		const string& p_prenom,
		const Date& p_dateNaissance,
		const string& p_telephone,
		const string& p_position)
:Personne(p_nom, p_prenom, p_dateNaissance, p_telephone)
{
	PRECONDITION(util::validerTelephone(p_telephone) == true);
	PRECONDITION(util::validerFormatNom(p_nom) == true);
	PRECONDITION(util::validerFormatNom(p_prenom) == true);
	PRECONDITION(p_position == "ailier" or p_position == "centre"
			or p_position == "défenseur" or p_position == "gardien")
	PRECONDITION(Date() - p_dateNaissance >= 5478 and Date() - p_dateNaissance <= 6209)
	m_position = p_position;
}
/**
 * \brief Requiers le nom d'un objet Joueur
 *
 * \return Retourne le nom de la position d'un joueur
 */
string Joueur::reqPosition() const
{
	return m_position;
}

/**
 * \brief Clone d'un joueur
 *
 * \return Retourne un pointeur vers un objet Joueur
 */
Personne* Joueur::clone() const
{
	return new Joueur(*this);
}

/**
 * \brief Requiers les information d'un objet Joueur
 *
 * \return Retourne les informations formatées d'un joueur
 */
string Joueur::reqPersonneFormate() const
{
	return "Nom               : "+ reqNom() + "\n"
		  +"Prenom            : "+ reqPrenom() + "\n"
		  +"Date de naissance : "+ reqDateNaissance() + "\n"
		  +"Telephone         : "+ reqTelephone() + "\n"
		  +"Position          : "+ reqPosition() + "\n"
		  +"-----------------------------";
}

}



