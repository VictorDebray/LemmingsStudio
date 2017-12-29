#ifndef			BASH_H
# define		BASH_H

# include		"AAction.hpp"

namespace indie
{

class			Bash : public AAction
{
  public:

  Bash()
  {
    _id = BASH;
    _meshPath = "ressources/mesh/basher/basher.b3d";
    _texturePath = "ressources/mesh/model/model_text.png";
  }
};

}

#endif			/* !BASH_H */