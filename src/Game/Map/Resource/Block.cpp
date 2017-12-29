//
// Created by victor on 5/31/17.
//

#include <random>
#include <iostream>
#include "Block.hpp"

namespace indie
{
  Block::Block(irr::scene::ISceneNode *parent,
		      irr::scene::ISceneManager *smgr,
		      const irr::core::vector3df &pos,
		      const size_t unitParticule, const irr::f32 particuleSize,
		      const ColorShade &color, const bool &destroyable)
	  : _pos(pos), _unitParticule(unitParticule), _colorShade(color),
	    _destroyable(destroyable)
  {

    for (size_t y = 0; y != unitParticule; y++)
      {
	for (size_t z = 0; z != unitParticule; z++)
	  {
	    for (size_t x = 0; x != unitParticule; ++x)
	      {
		ColorShadeGen colorShadeGen;
		_vecParticule.push_back(std::make_shared<Particule>(
			parent,
			smgr, irr::core::vector3df(
				pos.X + particuleSize * x,
				pos.Y + particuleSize * y,
				pos.Z + particuleSize * z),
			particuleSize,
			colorShadeGen.genRandomColor(_colorShade),
			_destroyable)
		);
	      }
	  }
      }
  }

  irr::core::vector3df const &Block::getPosition() const
  {
    return _pos;
  }

  size_t Block::getSizeUP() const
  {
    return _unitParticule;
  }

  bool Block::isDestroyable() const
  {
    return _destroyable;
  }

  void Block::remove()
  {
    if (isDestroyable())
      for (auto &it: _vecParticule)
	  it->remove();
  }
}

