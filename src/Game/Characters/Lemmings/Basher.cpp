//
// Created by victor on 5/24/17.
//

#include <Game/Timer.hpp>
#include "Lemming.hpp"

namespace indie
{

  bool 	Lemming::_basher(Sptr<Map> map)
  {
    static bool trig = false;
    std::pair<ObjType, Position> *mapPos;
    Position myPos = getPosition();
    std::function<void(Position const &pos)> deleteBlock =
	    [&map] (Position const &pos) {
	      Position e = pos;
	      e.y += 4;
	      map->getBlockFromPos({floor(pos.x) + 4,
				    floor(pos.y) - 1,
				    floor(pos.z)})
		      ->remove();
	      map->getBlockFromPos({floor(e.x) + 4,
				    floor(e.y) - 1,
				    floor(e.z)})
		      ->remove();
	      map->getBlockFromPos({floor(pos.x) + 4,
				    floor(pos.y) - 1,
				    floor(pos.z - 4)})
		      ->remove();
	      map->getBlockFromPos({floor(e.x) + 4,
				    floor(e.y) - 1,
				    floor(e.z - 4)})
		      ->remove();

	      std::pair<ObjType, Position> *f = &map->getObjType(pos);
	      f->first = ObjType::AIR;
	    };
    myPos.y += 4;
    myPos.x += 4;
    mapPos = &map->getObjType(myPos);
    if (mapPos->first == ObjType::WALL)
      {
	trig = true;
	mapPos->first = ObjType::AIR;
	deleteBlock(myPos);
      }
    else if (trig && map->getObjType({myPos.x + 4, myPos.y + 4, myPos.z}).first
		     == ObjType::AIR)
	{
	  setAction(AAction::WALK);
	}
      else
	_walker(map);
    return true;
  }

}
