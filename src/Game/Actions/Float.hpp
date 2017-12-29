#ifndef			FLOAT_H
# define		FLOAT_H

# include		"AAction.hpp"

namespace indie
{

class			Float : public AAction
{
  public:

  Float()
  {
    _id = FLOAT;
    _meshPath = "ressources/mesh/floater/floater.b3d";
    _texturePath = "ressources/mesh/model/model_text.png";
  }
};

}

#endif			/* !FLOAT_H */