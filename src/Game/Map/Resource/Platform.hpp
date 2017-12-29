//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_PLATFORM_HPP
# define INDIE_STUDIO_PLATFORM_HPP

# include <string>
# include <vector>
#include <standards.hpp>
# include "irrlicht.hpp"
# include "Block.hpp"

namespace indie
{
  class Platform
  {
   private:
    std::vector<std::shared_ptr<Block> >	_blocks;
    irr::core::vector3df			_pos;
    size_t 					_uParticulePerCube;
    irr::f32 					_particuleSize;
    ColorShade					_colorShade;
    bool 					_destroyable;

   public:
    Platform(irr::scene::ISceneNode *parent,
	     irr::scene::ISceneManager *smgr,
	     const irr::core::vector3df &posPlatform,
	     const std::vector<irr::core::vector3df> &placements,
	     const size_t uParticulePerCube = 10,
	     const irr::f32 particuleSize = 1.0f,
	     const ColorShade color = ColorShade::GREY,
	     const bool &destroyable = false);

   public:
    irr::core::vector3df const		&getPosition() const;
    Sptr<Block>				&getBlockFromPos(Position const &pos);
    bool 				isPosBlock(Position const &pos) const;
  };
}

#endif //INDIE_STUDIO_PLATFORM_HPP
