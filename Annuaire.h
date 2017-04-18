/**
 * \file Annuaire.h
 * \brief Header de la classe Annuaire
 * \author Charles-David Lachance
 */
#ifndef ANNUAIRE_H_
#define ANNUAIRE_H_
#include <sstream>
#include <ostream>
#include "Date.h"
#include "Entraineur.h"
#include "Joueur.h"
#include <vector>

namespace tp
{
/**
 * \class Annuaire
 * \brief Classe permettant de créer un club de hockey et d'y ajouter des personnes
 */
class Annuaire
{
public:
	/*Constructeur*/
	Annuaire(const std::string& p_nomClub);

	/*Méthodes d'accès*/
	std::string reqNom() const;
	std::string reqAnnuaireFormate() const;

	/*Méthode d'assignation*/
	void ajouterPersonne(const Personne& p_personne);

	/*Destructeur*/
	virtual ~Annuaire();
	
	/*Méthode pour enlevé une personne dans l'annuaire*/
	void supprimerPersonne(const std::string& p_nom, const std::string& p_prenom);

protected:
	std::string m_nomClub;
	std::vector<Personne*> m_vMembres;

private:
	bool PersonneEstDejaPresente(const Personne& p_personne) const;

};
}

#endif
