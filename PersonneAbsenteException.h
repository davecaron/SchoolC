/**
 * \file PersonneAbsenteException.h
 * \brief Header de la classe PersonneAbsenteException
 * \author Charles-David Lachance et Dave Caron
 */


#ifndef PERSONNEABSENTEEXCEPTION_H_
#define PERSONNEABSENTEEXCEPTION_H_

namespace tp{
  
  class PersonneAbsenteException public PersonneException
  {
  public:
  PersonneAbsenteException(const std::string& raison);
  
  private:
  std::string& raison;
  };
  }

#endif
