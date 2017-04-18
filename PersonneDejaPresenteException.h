/**
 * \file PersonneDejaPresenteException.h
 * \brief Header de la classe PersonneDejaPresenteException
 * \author Charles-David Lachance et Dave Caron
 */


#ifndef PERSONNEDEJAPRESENTEEXCEPTION_H_
#define PERSONNEDEJAPRESENTEEXCEPTION_H_

namespace tp{
  
  class PersonneDejaPresenteException public PersonneException
  {
  public:
  PersonneDejaPresenteException(const std::string& raison): std::runtime_error(raison){};
  
 // private:
  //std::string& raison;
  };
  }

#endif
