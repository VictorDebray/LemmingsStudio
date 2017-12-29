//
// Created by Victor on 05/02/2017.
//

#ifndef CPP_NANOTEKSPICE_EXCEPTION_HPP
#define CPP_NANOTEKSPICE_EXCEPTION_HPP

# include <string>
# include <exception>

namespace exception
{
  class ProgException : public std::exception
  {
   public:
    ProgException(std::string const& e) throw();
    ProgException(void) throw();
    virtual ~ProgException(void) throw();
    virtual const char *what(void) const throw();

   private:
    std::string _message;
  };
}

# include "DataException.hpp"
# include "GraphicException.hpp"
# include "FileException.hpp"
# include "SyntaxException.hpp"

#endif //CPP_NANOTEKSPICE_EXCEPTION_HPP
