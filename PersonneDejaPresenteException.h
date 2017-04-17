/**
 * \file PersonneException.h
 * \brief Header de la classe Personne
 * \author Charles-David Lachance et Dave Caron
 */


#ifndef PERSONNEDEJAPRESENTEEXCEPTION_H_
#define PERSONNEDEJAPRESENTEEXCEPTION_H_

namespace tp{
  
  class PersonneException public PersonneException
  {
  public:
  PersonneException(const std::string& raison);
  
  private:
  std::string& raison;
  };
  }

#endif
