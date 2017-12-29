//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_LEVEL3_HPP
# define INDIE_STUDIO_LEVEL3_HPP

# include "ALevel.hpp"

namespace indie
{
  class Level3 : public indie::ALevel
  {
   public:
    Level3(irr::scene::ISceneNode *parent,
	   irr::scene::ISceneManager *smgr,
	   const std::string &name = "Level3");
    ~Level3() {}

   public:
    virtual const std::string	getBg() const;
    void	draw();
    void	resetLevel();
  };
}

#endif //INDIE_STUDIO_LEVEL3_HPP
