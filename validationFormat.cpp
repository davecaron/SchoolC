/**
 * \file validationFormat.cpp
 * \brief Fonctions pour vérifier si les entrées des classes Personnes, Joueur ou Entraineur sont sans erreurs
 * \author Charles-David Lachance
 */


#include <iomanip>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "validationFormat.h"

namespace util{
using namespace std;
/**
 * \brief Valide un numéro de téléphone canadien
 *
 * \param string qui est un numéro de téléphone canadien
 * \return Retourne un booléen, vrai si le numéro de téléphone est valide
 */
bool validerTelephone(const string& p_telephone)
{	/* Valide si l'utilisateur a entré un numéro de la bonne longueur*/
	if (p_telephone.length() != 12)
	{
			cout << "Veuillez entrer un téléphone sous le format XXX XXX-XXXX." << endl;
			return false;
	}
	/* Valide si l'utilisateur a entré un code régional canadien*/
	for (int i = 0; i < 26; i++)
	{
		if (p_telephone.substr(0,3) == CODE_REGIONAL_VALIDE[i])
		{
			break;
		}
		else if (p_telephone.substr(0,3) != CODE_REGIONAL_VALIDE[i] and i == 25)
		{
			cout << "Le code régional n'est pas valide." << endl;
			return false;
		}
	}
	/* Valide si l'utilisateur a fait un espace après le code régional */
	if (p_telephone.substr(3,1) != " ")
	{
		cout << "Vous n'avez pas écrit d'espace après le code régional." << endl;
		return false;
	}
	/* Valide si l'utilisateur a écrit un tiret après les trois premiers chiffres*/
	if (p_telephone.substr(7,1) != "-")
	{
		cout << "Vous n'avez pas écrit de tiret après les trois premiers chiffres de votre numéro de téléphone." << endl;
		return false;
	}
	/* Valide si l'utilisateur a écrit seulement des chiffres */
	for (int i = 4; i < 12; i++)
	{
		if (i != 7)
		{
			for (int j = 0; j < 10; j++)
			{
				if (p_telephone.substr(i,1) == NOMBRES[j])
				{
					break;
				}
				else if (p_telephone.substr(i,1) != NOMBRES[j] and j == 9)
				{
					cout << "Vous avez entré un caractère non valide." << endl;
					return false;
				}
			}
		}
	}
 return true;
}

/**
 * \brief Valide un numéro de RAMQ
 *
* \param Prends en entrée le numéro de RAMQ et le nom, le prénom, le jour de naissance, le mois de naissance, l'année de naissance et le sexe pour valider le numéro
 * \return Retourne un booléen, vrai si le numéro de RAMQ est valide
 */
bool validerNumRAMQ(const string& p_numero, const string& p_nom,
					const string& p_prenom, int p_jourNaissance,
					int p_moisNaissance, int p_anneeNaissance, char p_sex)
{	/* Valide si l'utilisateur a entré le bon nom avec le numéro de RAMQ. */
	if (p_numero.substr(0,3) != p_nom.substr(0,3))
	{
		cout << "Le nom de famille ne concorde pas avec le numéro de la RAMQ.";
				return false;
	}

	/* Valide si l'utilisateur a entré le bon prénom avec le numéro de RAMQ. */
	if (p_numero.substr(3,1) != p_prenom.substr(0,1))
	{
		cout << "Le prénom ne concorde pas avec le numéro de la RAMQ.";
		return false;
	}
	/* Valide si l'utilisateur a entré la bonne année de naissance avec le numéro de RAMQ. */
	if (0 < p_anneeNaissance)
	{
		string str_anneeNaissance;

		ostringstream convert;

		convert << p_anneeNaissance;

		str_anneeNaissance = convert.str();

		if (str_anneeNaissance.substr(2,2) != p_numero.substr(4,2))
		{
			cout << "L'année ne concorde pas avec le numéro de la RAMQ.";
			return false;
		}
	}


	/* Valide si l'utilisateur a entré un sexe valide */
	if (p_sex != 'f' and p_sex != 'F' and p_sex != 'm' and p_sex != 'M')
	{
		cout << "Le sexe est invalide.";
		return false;
	}

	/* Valide le mois de naissance si l'utilisateur est une femme */
	if (p_sex == 'f' or p_sex == 'F')
	{
		int mois_femme = p_moisNaissance + 50;

		string str_mois_femme;

		ostringstream convert;

		convert <<  mois_femme;

		str_mois_femme = convert.str();
		if (str_mois_femme != p_numero.substr(6,2))
		{
			cout << "Le mois ne concorde pas avec le numéro de la RAMQ.";
			return false;
		}
	}

	/* Valide le mois de naissance si l'utilisateur est un homme */
	if (p_sex == 'h' or p_sex == 'H')
	{
		string str_mois_homme;

		string temp_str_mois_homme;

		ostringstream convert;

		convert <<  p_moisNaissance;

		temp_str_mois_homme = convert.str();
		if (0 < p_moisNaissance and p_moisNaissance < 10)
		{
			str_mois_homme = "0" + temp_str_mois_homme;
		}

		if (p_moisNaissance >= 10)
		{
			str_mois_homme = temp_str_mois_homme;
		}

		if (temp_str_mois_homme != p_numero.substr(6,2))
		{
			cout << "Le mois ne concorde pas avec le numéro de la RAMQ.";
			return false;
		}
	}
	/* Valide si l'utilisateur a entré la bonne journée de naissance avec le numéro de RAMQ. */
	if (0 < p_jourNaissance and p_jourNaissance < 10)
	{
		string str_jour_naissance;
		string temp_str_jour_naissance;

		ostringstream convert;

		convert << p_jourNaissance;

		temp_str_jour_naissance = convert.str();

		str_jour_naissance = "0" + temp_str_jour_naissance;

		if (str_jour_naissance != p_numero.substr(8,2))
			{
				cout << "Le jour ne concorde pas avec le numéro de la RAMQ.";
				return false;
			}
	}
	else if (p_jourNaissance >= 10)
	{
		string str_jour_naissance;

		ostringstream convert;

		convert << p_jourNaissance;

		str_jour_naissance = convert.str();

		if (str_jour_naissance != p_numero.substr(8,2))
			{
				cout << "Le jour ne concorde pas avec le numéro de la RAMQ.";
				return false;
			}
	}

return true;
}
/**
 * \brief Valide un nom
 *
 * \param string qui est un nom ou prénom
 * \return Retourne un booléen, vrai si le nom est valide
 */
bool validerFormatNom(const string& p_nom)
{
	if (p_nom == "")
	{
		cout << "Impossible d'entrer un champs vide." << endl;
		return false;
	}

	for (int i = 0; i < p_nom.size(); i++)
	{
		if(isalpha(p_nom[i]) == 0)
		{
			cout << "Seulement les lettres sont acceptées comme caractère" << endl;
			return false;
		}

	}
	return true;
}
}
