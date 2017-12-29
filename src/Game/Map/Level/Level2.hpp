//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_LEVEL2_HPP
# define INDIE_STUDIO_LEVEL2_HPP

# include "ALevel.hpp"

namespace indie
{
  class Level2 : public indie::ALevel
  {
   public:
    Level2(irr::scene::ISceneNode *parent,
	   irr::scene::ISceneManager *smgr,
	   const std::string &name = "Level2");
    ~Level2() {}

   public:
    virtual const std::string	getBg() const;
    void	draw();
    void	resetLevel();
  };
}

#endif //INDIE_STUDIO_LEVEL2_HPP
