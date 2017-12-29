//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Platform.hpp"

namespace indie
{

  Platform::Platform(irr::scene::ISceneNode *parent,
		     irr::scene::ISceneManager *smgr,
		     const irr::core::vector3df &posPlatform,
		     const std::vector<irr::core::vector3df> &placements,
		     const size_t uParticulePerCube,
		     const irr::f32 particuleSize,
		     const ColorShade color,
		     const bool &destroyable)
	  : _pos(posPlatform), _uParticulePerCube(uParticulePerCube),
	    _particuleSize(particuleSize), _colorShade(color),
	    _destroyable(destroyable)
  {
    for (auto &it : placements)
      {
	_blocks.push_back(std::make_shared<Block>
				  (parent,
				   smgr,
				   irr::core::vector3df(
					   _pos.X + it.X,
					   _pos.Y + it.Y,
					   _pos.Z + it.Z),
				   _uParticulePerCube,
				   _particuleSize,
				   _colorShade,
				  _destroyable)
	);
      }
  }

  irr::core::vector3df const	&Platform::getPosition() const
  {
    return _pos;
  }

  Sptr<Block>			&Platform::getBlockFromPos(Position const &pos)
  {
    for (auto &it: _blocks)
      {
	if (it->getPosition().X == pos.x
	    && it->getPosition().Y == pos.y
	    && it->getPosition().Z == pos.z)
	  return it;
      }
    return _blocks.front();
  }

  bool Platform::isPosBlock(Position const &pos) const
  {
    for (auto &it: _blocks)
      {
//	std::cout << it->getPosition().X << " " << it->getPosition().Y
//		  << std::endl << std::endl;
	if (it->getPosition().X == pos.x
	    && it->getPosition().Y == pos.y
	    && it->getPosition().Z == pos.z)
	  {
	    return true;
	  }
      }
    return false;
  }
}