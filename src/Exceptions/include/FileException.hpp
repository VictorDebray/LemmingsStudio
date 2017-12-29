//
// Created by Victor on 04/03/2017.
//

#ifndef CPP_NANOTEKSPICE_FILEEXCEPTION_HPP
#define CPP_NANOTEKSPICE_FILEEXCEPTION_HPP

namespace exception
{
  class FileException : public ProgException
  {
   private:
    static const std::string _HEAD;

   public:
    FileException(std::string const &message) throw();

    FileException(void) throw();

    virtual ~FileException(void) throw();
  };
}

#endif //CPP_NANOTEKSPICE_FILEEXCEPTION_HPP
