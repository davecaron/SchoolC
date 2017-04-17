
/**
 * \file PersonneException.h
 * \brief Header de la classe Personne
 * \author Charles-David Lachance et Dave Caron
 */


#ifndef PERSONNEEXCEPTION_H_
#define PERSONNEEXCEPTION_H_

namespace tp{
  
  class PersonneException public std::runtime_error
  {
  public:
  PersonneException(const std::string& raison);
  
  private:
  std::string& raison;
  };
  }

#endif
