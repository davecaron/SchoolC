/**
 * \file Annuaire.cpp
 * \brief Fonctions pour manipuler la classe Annuaire
 * \author Charles-David Lachance
 */

#include "Annuaire.h"
#include "validationFormat.h"
using namespace std;
using namespace util;

namespace tp
{
/**
 * \brief Constructeur de la classe Annuaire
 *
 * \param nom du club
 * \return Retourne un object Annuaire
 */
Annuaire::Annuaire(const string& p_nomClub) :
		m_nomClub(p_nomClub), m_vMembres(vector<Personne*>())
{
	PRECONDITION(validerFormatNom(p_nomClub) == true)
}

/**
 * \brief Destructeur de la classe Annuaire
 *
 * \return Détruit un object Annuaire
 */
Annuaire::~Annuaire()
{

}
/**
 * \brief Requiers le nom d'un objet Annuaire
 *
 * \return Retourne le nom du club de l'Annuaire
 */

string Annuaire::reqNom() const
{
	return m_nomClub;
}
/**
 * \brief Requiers les information d'un objet Annuaire
 *
 * \return Retourne les informations formatées des personnes d'un annuaire
 */
string Annuaire::reqAnnuaireFormate() const
{
	ostringstream annuaire;
	for (unsigned int i = 0; i < m_vMembres.size(); i++)
	{
		annuaire << m_vMembres[i]->reqPersonneFormate();

	}
	return annuaire.str();
}

bool Annuaire::PersonneEstDejaPresente(const Personne& p_personne) const;
{
	for(unsigned int i = 0; i < m_vMembres.size(); i++)
	{
		if (m_Membres[i] == p_personne)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
	
/**
 * \brief Ajoute une nouvelle personne à l'annuaire
 *
 * \param Prends en entrée une nouvelle personne
 */
void Annuaire::ajouterPersonne(const Personne& p_personne)
{
	PRECONDITION(validerFormatNom(p_personne.reqNom()) == true)
	PRECONDITION(validerFormatNom(p_personne.reqPrenom()) == true)
	PRECONDITION(validerTelephone(p_personne.reqTelephone()) == true)
	if (ici.PersonneEstDejaPresente(p_personne))
	{
	#ici charles ici watashi no fuuka
	}
	else
	{
		m_vMembres.push_back(p_personne.clone());
	}
}

}
