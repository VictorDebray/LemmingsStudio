//
// Created by Victor on 04/03/2017.
//

#include "Exception.hpp"

namespace exception
{
  const std::string exception::FileException::_HEAD = "FileException: ";

  FileException::FileException(std::string const &message) throw()
	  : ProgException(_HEAD + message)
  {
  }

  FileException::FileException(void) throw()
  {
  }

  FileException::~FileException(void) throw()
  {
  }
}