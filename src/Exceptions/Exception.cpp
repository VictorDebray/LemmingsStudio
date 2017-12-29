//
// Created by Victor on 05/02/2017.
//

#include "Exception.hpp"

namespace exception
{
  ProgException::ProgException(std::string const &message) throw()
  {
    _message = message;
  }

  ProgException::ProgException(void) throw()
  {
    _message = "";
  }

  ProgException::~ProgException(void) throw()
  {
  }

  const char *ProgException::what(void) const throw()
  {
    return (_message.data());
  }
}