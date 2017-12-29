//
// Created by Victor on 04/03/2017.
//

#include "Exception.hpp"

namespace exception
{
  const std::string exception::SyntaxException::_HEAD = "SyntaxException: ";

  SyntaxException::SyntaxException(std::string const &message) throw()
	  : ProgException(_HEAD + message)
  {
  }

  SyntaxException::SyntaxException(void) throw()
  {
  }

  SyntaxException::~SyntaxException(void) throw()
  {
  }
}