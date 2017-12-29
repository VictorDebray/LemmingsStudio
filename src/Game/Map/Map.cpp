//
// Created by victor on 5/30/17.
//

#include <cmath>
#include <iostream>
#include "Exception.hpp"
#include "Map.hpp"

namespace indie
{
  Map::Map(irr::scene::ISceneNode *parent, Sptr<Graphic> graphic) :
	  _parent(parent),
	  _smgr(graphic->getSceneManager()),
	  _graphic(graphic),
	  _levelNb(-1)
  {
    _levels.push_back(std::make_shared<Level1>(_parent, _smgr));
    _levels.push_back(std::make_shared<Level2>(_parent, _smgr));
    _levels.push_back(std::make_shared<Level3>(_parent, _smgr));
  }

  Map::~Map()
  {
  }

  void Map::initLevel(unsigned int level)
  {
    if (level < _levels.size())
      {
	_levelNb = level;
	_levels[_levelNb]->draw();
	_objMap = _levels[_levelNb]->getObjMap();
	_graphic->blitImage(_levels[_levelNb]->getBg(), {0, 0, 0});
      }
    else
      throw exception::DataException("Level number is not in map container");
  }

  std::pair<ObjType, Position> &Map::getObjType(Position const &irrlichtPos)
  {
    Position2D pos;
    pos.x = floor(irrlichtPos.x / _levels[_levelNb]->getUnitPerBlock());
    pos.y = floor(irrlichtPos.y / _levels[_levelNb]->getUnitPerBlock());
    return _objMap[(unsigned int)pos.x  + 
		(unsigned int)pos.y *
		_levels[_levelNb]->getWidthObjMap()];
  }

  Position const& Map::getStartPosition() const
  {
    return _levels[_levelNb]->getStartPosition();
  }

  Position const& Map::getGatePosition() const
  {
    return _levels[_levelNb]->getGatePosition();
  }

  Sptr<Block> 	&Map::getBlockFromPos(Position const &pos)
  {
    return _levels[_levelNb]->getBlockFromPos(pos);
  }

  float Map::getHeightMap() const
  {
    return _levels[_levelNb]->getHeight();
  }

  void Map::printMap() const
  {
    _levels[_levelNb]->printMap();
  }
}