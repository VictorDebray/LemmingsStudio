//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Level3.hpp"

namespace indie
{
  Level3::Level3(irr::scene::ISceneNode *parent,
		 irr::scene::ISceneManager *smgr,
		 const std::string &name) :
	ALevel(parent, smgr, name)
  {
  }

  void Level3::draw()
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

    std::function<void(Position const &pos, float nb, int height, ObjType const &type,
		       bool destroyable)> col =
	    [=] (Position const &pos, float nb, int height, ObjType const &type,
		 bool destroyable) {
	      int i = 0;
	      while (i != height)
		{
		  plat({pos.x, pos.y + i * 4, pos.z}, nb, type, destroyable);
		  ++i;
		}
	    };
    col({120, -1, _Z_POS}, 20, 10, ObjType::PLATFORM, false);
    col({140, -1, _Z_POS}, 40, 15, ObjType::PLATFORM, false);
    col({180, -1, _Z_POS}, 60, 20, ObjType::PLATFORM, false);
    {//GROUND
      std::vector<irr::core::vector3df> placements;
      for (irr::f32 z = _Z_POS + _Z_POS - 1; z < 7.0f; z += 2)
	{
	  for (irr::f32 i = -1; i != _width - 1; i += 2)
	    {
	      placements.push_back(irr::core::vector3df(0.0f + i, -2, z));
	      placements.push_back(irr::core::vector3df(0.0f + i, 0, z));
	    }
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
	      20 + getWidthObjMap() + 1];
      vec->first = ObjType::START_GATE;
      vec->second = {0, 0, 0};
      //_startPos = {20, 5, 0};
      _startPos = {20, 5, 0};
    }
    {//End game
      std::pair<ObjType, Position> *vec = &_objMap[
	      55 + getWidthObjMap() * 20];
      vec->first = ObjType::END_GATE;
      vec->second = {0,0,0};
      _gatePos = {220, 77, 2};
    }
  }

  const std::string Level3::getBg() const
  {
    return "ressources/img/jungle.png";
  }

  void Level3::resetLevel()
  {
    std::cout << "reset" << std::endl;
  }

}
