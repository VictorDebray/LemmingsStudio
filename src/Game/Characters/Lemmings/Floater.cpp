//
// Created by victor on 5/24/17.
//

#include "Lemming.hpp"

namespace indie
{

  bool 	Lemming::_floater(Sptr<Map> map)
  {
    std::unordered_map<Direction, int> tabDir = {
	    {LEFT, 2},
	    {RIGHT, -2}
    };
    static Direction oldDir = _dir;
    Position pos = getPosition();
    pos.x += tabDir[_dir];
    ObjType tilePos = map->getObjType(pos).first;
    if (tilePos == ObjType::AIR)
      _dir = DOWN;
    if (isFalling() && !isSteppable(tilePos))
      {
	move(_dir);
	_willDie = 0.8f;
      } else if (isFalling() && isSteppable(tilePos))
	{
	  _dir = oldDir;
	  setAction(AAction::WALK);
	  _willDie = 0.0f;
	}
      else
	_walker(map);
    return true;
  }

}
