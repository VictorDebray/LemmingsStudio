//
// Created by victor on 5/24/17.
//

#include "Lemming.hpp"

namespace indie
{

bool 	Lemming::_exploder(Sptr<Map> map)
{
  static bool	trigger = true;

  if (trigger) {
    _timer = std::make_shared<Timer>();
    trigger = false;
  }

  if (_timer->elapsed() >= 1.0) {
      Position pos = getPosition();
    std::pair<ObjType, Position> *tile = &map->getObjType({pos.x, pos.y + 4,
							   pos.z});
      tile->first = ObjType::AIR;
    trigger = true;
    return false;
  }

  return true;
}

}