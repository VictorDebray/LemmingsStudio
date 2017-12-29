#include <algorithm>
#include "Lemming.hpp"

namespace indie
{
  bool Lemming::_walker(Sptr<Map> map)
  {
    std::unordered_map<Direction, std::pair<int, float>> tab = {
	    {LEFT, std::make_pair(2, 0)},
	    {RIGHT, std::make_pair(-2, 180)}
    };
    _rot = {0, tab[_dir].second, 0};
    std::function<void()> changeDir = [&]() {
      if (_dir == LEFT)
	_dir = RIGHT;
      else if (_dir == RIGHT)
	  _dir = LEFT;
    };
    std::pair<ObjType, Position> mapDown;
    Position pos;
    pos = getPosition();
    pos.x += tab[_dir].first;
    mapDown = map->getObjType(pos);
    int result = static_cast<int>(pos.y) % 4;
    if (result == 0 && isSteppable(mapDown.first))
      {
	if (_willDie >= HEIGHT_TO_DIE) {
	  _actionID = AAction::DIE;
	  return true;
	}
	_willDie = 0;
	std::pair<ObjType, Position> mapPos;
	Position myPos = getPosition();
	myPos.y += 4;
	mapPos = map->getObjType(myPos);
	if (mapPos.first == ObjType::LEM_BLOCK
	    || isSteppable(mapPos.first))
	  {
	    changeDir();
	  }
	else if (mapPos.first == ObjType::WALL)
	    changeDir();
	move(_dir);
      }
    else {
      _willDie += ACCELERATOR;
      move(DOWN);
    }
    return true;
  }
}