//
// Created by Victor on 04/03/2017.
//

#ifndef CPP_NANOTEKSPICE_SYNTAXEXCEPTION_HPP
# define CPP_NANOTEKSPICE_SYNTAXEXCEPTION_HPP

namespace exception
{
  class SyntaxException : public ProgException
  {
   private:
    static const std::string _HEAD;

   public:
    SyntaxException(std::string const& message) throw();
    SyntaxException(void) throw();
    virtual ~SyntaxException(void) throw();
  };
}

#endif //CPP_NANOTEKSPICE_SYNTAXEXCEPTION_HPP
