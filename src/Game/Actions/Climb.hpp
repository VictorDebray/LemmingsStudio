#ifndef			CLIMB_H
# define		CLIMB_H

# include		"AAction.hpp"

namespace indie
{

class			Climb : public AAction
{
  public:

  Climb()
  {
    _id = CLIMB;
    _meshPath = "ressources/mesh/climber/climber.b3d";
    _texturePath = "ressources/mesh/model/model_text.png";
  }
};

}

#endif			/* !CLIMB_H */