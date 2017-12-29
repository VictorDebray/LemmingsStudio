#ifndef			STOP_H
# define		STOP_H

# include		"AAction.hpp"

namespace indie
{

class			Stop : public AAction
{
  public:

  Stop()
  {
    _id = STOP;
    _meshPath = "ressources/mesh/stopper/stopper.b3d";
    _texturePath = "ressources/mesh/model/model_text.png";
  }
};

}

#endif			/* !STOP_H */