//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Level2.hpp"

namespace indie
{
  Level2::Level2(irr::scene::ISceneNode *parent,
		 irr::scene::ISceneManager *smgr,
		 const std::string &name) :
	ALevel(parent, smgr, name)
  {
  }

  void Level2::draw()
  {
    drawBoard();
    std::function<void(Position const &pos, float nb, ObjType const &type,
		       bool destroyable)> plat =
	    [=] (Position const &pos, float nb, ObjType const &type,
		 bool destroyable) {
	      std::vector<irr::core::vector3df> placements;
	      for (irr::f32 i = 0; i < nb; i += _IRR_UNIT_PER_BLOCK)
		{
		  for (irr::f32 zi = _Z_POS; zi < 9.0f;
		       zi += _IRR_UNIT_PER_BLOCK)
		    placements.push_back(irr::core::vector3df(pos.x + i,
							      pos.y,
							      pos.z + zi));
		  std::pair<ObjType, Position> *vec = &_objMap[
			  (pos.x + i - 1) / _IRR_UNIT_PER_BLOCK
			  + ((pos.y + 1)/ _IRR_UNIT_PER_BLOCK)
			    * (getWidthObjMap())];
		  vec->first = type;
		  vec->second = {0,0,0};
		}
	      _vecPlatforms.push_back(
		      std::make_shared<Platform>
			      (_parent, _smgr,
			       irr::core::vector3df(0, 0, 0),
			       placements,
			       1, _IRR_UNIT_PER_BLOCK, ColorShade::GREY,
			       destroyable));
	    };

    plat({0, 79, _Z_POS}, 112, ObjType::PLATFORM, false);//TOP LEFT PLATFORM
    plat({80, 83, _Z_POS}, 8, ObjType::WALL, true);//WALL LEFT PLATFORM
    plat({80, 87, _Z_POS}, 8, ObjType::WALL, true);//WALL LEFT PLATFORM
    plat({80, 91, _Z_POS}, 8, ObjType::WALL, true);//WALL LEFT PLATFORM
    plat({80, 95, _Z_POS}, 8, ObjType::WALL, true);//WALL LEFT PLATFORM
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
      _startPos = {13, 23, 0};
    }
    {//End game
      std::pair<ObjType, Position> *vec = &_objMap[
	      160 / _IRR_UNIT_PER_BLOCK
	      + getWidthObjMap() + 1];
      vec->first = ObjType::END_GATE;
      vec->second = {0,0,0};
      _gatePos = Position(164, 0, 2);
    }
  }

  const std::string Level2::getBg() const
  {
    return "ressources/img/Lava.png";
  }

  void Level2::resetLevel()
  {
    std::cout << "reset" << std::endl;
  }

}