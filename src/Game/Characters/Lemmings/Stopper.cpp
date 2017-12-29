//
// Created by victor on 5/24/17.
//

#include "Lemming.hpp"

namespace indie
{

bool 	Lemming::_stopper(Sptr<Map> map)
{
  Position pos;
  pos = getPosition();
  pos.y += 4;
  std::pair<ObjType, Position> &mapType = map->getObjType(pos);
  mapType.first = ObjType::LEM_BLOCK;
  mapType.second = pos;
  _rot = {0, 0, 0};
  return true;
}

}
