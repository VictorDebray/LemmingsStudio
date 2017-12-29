//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Level1.hpp"

namespace indie
{
  Level1::Level1(irr::scene::ISceneNode *parent,
		 irr::scene::ISceneManager *smgr,
		 const std::string &name) :
	ALevel(parent, smgr, name)
  {
    _gatePos = Position(124, 0, 2);
  }

  void Level1::draw()
  {
    drawBoard();
    std::function<void(float x, float y, float z, float nb)> plat =
	    [=] (float x, float y, float z, float nb) {
	      std::vector<irr::core::vector3df> placements;
	      for (irr::f32 i = 0; i < nb; i += _IRR_UNIT_PER_BLOCK)
		{
		  for (irr::f32 zi = _Z_POS; zi < 9.0f;
		       zi += _IRR_UNIT_PER_BLOCK)
		    placements.push_back(irr::core::vector3df(x + i, y, z + zi));
		  std::pair<ObjType, Position> *vec = &_objMap[
			  (x + i - 1) / _IRR_UNIT_PER_BLOCK
			  + ((y + 1)/ _IRR_UNIT_PER_BLOCK)
			    * (getWidthObjMap())];
		  vec->first = ObjType::PLATFORM;
		  vec->second = {0,0,0};
		}
	      _vecPlatforms.push_back(
		      std::make_shared<Platform>
			      (_parent, _smgr,
			       irr::core::vector3df(0, 0, 0),
			       placements,
			       1, _IRR_UNIT_PER_BLOCK));
	    };

    plat(100, 79, _Z_POS, 40);//TOP MIDDLE PLATFORM
    plat(72, 59, _Z_POS, 32);//MIDDLE LEFT PLATFORM
    plat(164, 59, _Z_POS, 32);//FAIL MIDDLE RIGHT PLATFORM
    plat(48, 39, _Z_POS, 32);// MIDDLE LEFT PLATFORM
    plat(80, 19, _Z_POS, 16);//BOTTOM MIDDLE PLATFORM
    plat(180, 31, _Z_POS, 20);//FAILED LAST RIGHT PLATFORM
    {//GROUND
      std::vector<irr::core::vector3df> placements;
      for (irr::f32 z = _Z_POS; z < 8.0f; z += 2)
	{
	  for (irr::f32 i = -1; i != _width - 1; i += 2)
	    placements.push_back(irr::core::vector3df(0.0f + i, 0.0f, z));
	}
      _vecPlatforms.push_back(
	      std::make_shared<Platform>
		      (_parent, _smgr,
		       irr::core::vector3df(0, 0, 0),
		       placements,
		       1, _IRR_UNIT_PER_BLOCK / 2, BROWN));
    }
    {//Entry level
      std::pair<ObjType, Position> *vec = &_objMap[
	      _width / 2 / _IRR_UNIT_PER_BLOCK
	      + 23 * getWidthObjMap()];
      vec->first = ObjType::START_GATE;
      vec->second = {0, 0, 0};
      _startPos = {_widthMap / 2.0f, 23, 0};
    }
    {//End game
      std::pair<ObjType, Position> *vec = &_objMap[
	      _width / 2 / _IRR_UNIT_PER_BLOCK
	      + getWidthObjMap()];
      vec->first = ObjType::END_GATE;
      vec->second = {0,0,0};
      _gatePos = {_width / 2, 0, 2};
    }
  }

  const std::string Level1::getBg() const
  {
    return "ressources/img/cave.png";
  }

  void Level1::resetLevel()
  {
    std::cout << "reset" << std::endl;
  }

}