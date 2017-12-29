//
// Created by Victor on 04/03/2017.
//

#ifndef CPP_NANOTEKSPICE_DATAEXCEPTION_HPP
#define CPP_NANOTEKSPICE_DATAEXCEPTION_HPP

namespace exception
{
  class DataException : public ProgException
  {
    static const std::string _HEAD;
   public:
    DataException(std::string const& message) throw();
    DataException(void) throw();
    virtual ~DataException(void) throw();
  };
}

#endif //CPP_NANOTEKSPICE_DATAEXCEPTION_HPP
