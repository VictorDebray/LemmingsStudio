//
// Created by Victor on 04/03/2017.
//

#include "Exception.hpp"

namespace exception
{
  const std::string exception::GraphicException::_HEAD = "GraphicException: ";

  GraphicException::GraphicException(std::string const &message) throw()
	  : ProgException(_HEAD + message)
  {
  }

  GraphicException::GraphicException(void) throw()
  {
  }

  GraphicException::~GraphicException(void) throw()
  {
  }
}