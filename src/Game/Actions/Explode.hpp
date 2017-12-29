#ifndef			EXPLODE_H
# define		EXPLODE_H

# include		"AAction.hpp"

namespace indie
{

class			Explode : public AAction
{
  public:

  Explode()
  {
    _id = EXPLODE;
    _meshPath = "ressources/mesh/exploder/exploder.b3d";
    _texturePath = "ressources/mesh/model/model_text.png";
  }
};

}

#endif			/* !EXPLODE_H */