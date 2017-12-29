//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Exception.hpp"
#include "ALevel.hpp"

namespace indie
{
  const int ALevel::_IRR_UNIT_PER_BLOCK = 4;
  const float ALevel::_Z_POS = -2;

  ALevel::ALevel(irr::scene::ISceneNode *parent,
		 irr::scene::ISceneManager *smgr,
		 std::string const &name, irr::f32 width, irr::f32 height,
		 irr::f32 depth) //copy billBoard wanted
	  : _name(name),
	    _parent(parent),
	    _smgr(smgr),
	    _width(width),
	    _height(height),
	    _depth(depth)
  {
    if ((static_cast<int>(width) % _IRR_UNIT_PER_BLOCK) != 0
	|| (static_cast<int>(height) % _IRR_UNIT_PER_BLOCK) != 0)
      throw exception::DataException("map definition must be a multiple of 4");
    else
      {
	_widthMap = (unsigned int)_width / _IRR_UNIT_PER_BLOCK;
	_heightMap = (unsigned int)_height / _IRR_UNIT_PER_BLOCK;
      }
  }

  void ALevel::drawBoard()
  {
    std::pair<ObjType, Position> pair;
    Position pos = {0,0,0};
    pair = std::make_pair(ObjType::AIR, pos);
    for (auto idx = 0; idx != (_height /_IRR_UNIT_PER_BLOCK)
			      * (_width / _IRR_UNIT_PER_BLOCK); ++idx)
      _objMap.push_back(pair);
    float xi = 0;
    for (float x = 0.0f; x != _width; x += _IRR_UNIT_PER_BLOCK)
      {
	_objMap[xi].first = ObjType::FLOOR;
	_objMap[xi + (_heightMap - 1) * _widthMap].first = ObjType::WALL;
	_objMap[xi + (_heightMap - 1) * _widthMap].second = {0,0,0};
	_objMap[xi++].second = {0,0,0};
      }
    int max_w = _width / 4 - 1;
    for (int y = 0; y != _height / 4 - 1; y += 1)
      {
	_objMap[y * max_w + y].first = ObjType::WALL;
	_objMap[y * max_w + y].second = {0,0,0};
	_objMap[y * max_w + max_w + y].first = ObjType::WALL;
	_objMap[y * max_w + max_w + y].second = {0,0,0};
      }
  }

  ObjMap ALevel::getObjMap() const
  {
    return _objMap;
  }

  void ALevel::setName(std::string const &name)
  {
    _name = name;
  }

  std::string const &ALevel::getName() const
  {
    return _name;
  }

  float ALevel::getUnitPerBlock() const
  {
    return _IRR_UNIT_PER_BLOCK;
  }

  int ALevel::getWidthObjMap() const
  {
    return _widthMap;
  }

  int ALevel::getHeightObjMap() const
  {
    return _heightMap;
  }

  float ALevel::getHeight() const
  {
    return _height;
  }

  Position const &ALevel::getStartPosition() const
  {
    return _startPos;
  }

  Position const &ALevel::getGatePosition() const
  {
    return _gatePos;
  }

  void ALevel::printMap() const
  {
        for (int y = 0; y < _height / _IRR_UNIT_PER_BLOCK; y++)
       {
 	for (int x = 0; x < _width / _IRR_UNIT_PER_BLOCK; ++x)
 	  {
 	    std::cout << _objMap[x + y * (_width / _IRR_UNIT_PER_BLOCK)].first;
 	  }
 	std::cout << std::endl;
       }
  }

  Sptr<Block> &ALevel::getBlockFromPos(Position const &pos)
  {
    for (auto &it : _vecPlatforms)
      {
	if (it->isPosBlock(pos))
	  {
	    return it->getBlockFromPos(pos);
	  }
      }
    return _vecPlatforms.front()->getBlockFromPos({0,0,0});
  }
}