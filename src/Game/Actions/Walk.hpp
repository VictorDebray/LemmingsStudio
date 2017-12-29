#ifndef			WALK_H
# define		WALK_H

# include		"AAction.hpp"

namespace indie
{

class			Walk : public AAction
{
  public:
  
  Walk()
  {
    _id = WALK;
  }
};

}

#endif			/* !WALK_H */