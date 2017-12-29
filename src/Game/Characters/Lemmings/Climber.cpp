//
// Created by victor on 5/24/17.
//

#include "Lemming.hpp"

namespace indie
{

  bool 		Lemming::_climber(Sptr<Map> map)
  {
    std::unordered_map<Direction, std::pair<Direction, int> > chDirection = {
	    {LEFT,  std::make_pair(RIGHT, -2)},
	    {RIGHT, std::make_pair(LEFT, 2)}
    };
    std::pair<ObjType, Position> mapPos;
    Position myPos = getPosition();
    myPos.y += 4;
    myPos.x += 4;
    mapPos = map->getObjType(myPos);
    int result = static_cast<int>(myPos.x) % 4;
    if (result != 0 && mapPos.first == ObjType::PLATFORM)
      {
	_climbing = true;
	move(UP);
      }
    else if ((map->getObjType(myPos).first
		  == ObjType::AIR
	      || map->getObjType({myPos.x + 4, myPos.y, myPos.z}).first
		     == ObjType::AIR
	      || map->getObjType({myPos.x, myPos.y + 4, myPos.z}).first
		 != ObjType::AIR) && _climbing)
	{
	  if (map->getObjType({myPos.x, myPos.y + 4, myPos.z}).first
	      != ObjType::AIR)
	    {
	      Position newPos = getPosition();
	      newPos.x -= chDirection[_dir].second;
	      newPos.y -= chDirection[_dir].second;
	      setPosition(newPos);
	      _dir = chDirection[_dir].first;
	      setAction(AAction::WALK);
	    }
	  else if (_climbing)
	      {
		Position newPos = getPosition();
		newPos.x += chDirection[_dir].second * 3;
		setPosition(newPos);
	      }
	  setAction(AAction::WALK);
	  _climbing = false;
	}
      else
	_walker(map);
    return true;
  }

}