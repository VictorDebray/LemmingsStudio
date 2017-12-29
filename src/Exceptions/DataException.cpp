//
// Created by Victor on 04/03/2017.
//

#include "Exception.hpp"

namespace exception
{
  const std::string exception::DataException::_HEAD = "DataException: ";

  DataException::DataException(std::string const &message) throw()
	  : ProgException(_HEAD + message)
  {
  }

  DataException::DataException(void) throw()
  {
  }

  DataException::~DataException(void) throw()
  {
  }
}