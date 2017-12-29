//
// Created by Victor on 04/03/2017.
//

#ifndef GRAPHIC_EXCEPTION
#define GRAPHIC_EXCEPTION

namespace exception
{
  class GraphicException : public ProgException
  {
   private:
    static const std::string _HEAD;

   public:
    GraphicException(std::string const &message) throw();

    GraphicException(void) throw();

    virtual ~GraphicException(void) throw();
  };
}

#endif //GRAPHIC_EXCEPTION
