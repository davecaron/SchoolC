/**
 * \file validationFormat.h
 * \brief Fonctions pour vérifier si les entrées des classes Personnes, Joueur ou Entraineur sont sans erreurs
 * \author Charles-David Lachance
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

namespace util{
bool validerTelephone(const std::string& p_telephone);
bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom,
					const std::string& p_prenom, int p_jourNaissance,
					int p_moisNaissance, int p_anneeNaissance, char p_sex);
bool validerFormatNom(const std::string& p_nom);

const std::string CODE_REGIONAL_VALIDE[27] = {"403", "780", "604", "236", "250", "778", "902",
								   "204", "506", "905", "519", "289", "705", "613",
								   "807", "416", "647", "438", "514", "450", "579",
								   "418", "581", "819", "306", "709", "867"};

const std::string NOMBRES[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
}

#endif /* VALIDATIONFORMAT_H_ */
