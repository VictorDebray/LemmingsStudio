//
// Created by victor on 5/23/17.
//

#include "Exception.hpp"
#include "Lemming.hpp"

namespace indie
{

  const float Lemming::ACCELERATOR = 0.8f;
  const float Lemming::HEIGHT_TO_DIE = 30;

  Lemming::Lemming(Sptr<Graphic> graphic,
  		   Sptr<GameInfo> gameInfo,
		   Position const &position) :
	  ACharacter(graphic),
	  _gameInfo(gameInfo),
	  _willDie(0),
	  _climbing(false)
  {
    _actionTab = {
	    {AAction::WALK,
		    {"ressources/mesh/walker/walker.b3d",
			    "ressources/mesh/model/model_text.png",
			    30,
			    &Lemming::_walker}},
	    {AAction::STOP,
		    {"ressources/mesh/stopper/stopper.b3d",
			    "ressources/mesh/model/model_text.png",
			    0,
			    &Lemming::_stopper}},
	    {AAction::BASH,
		    {"ressources/mesh/basher/basher.b3d",
			    "ressources/mesh/model/model_text.png",
			    20,
			    &Lemming::_basher}},
	    {AAction::EXPLODE,
		    {"ressources/mesh/exploder/exploder.b3d",
			    "ressources/mesh/model/model_text.png",
			    50,
			    &Lemming::_exploder}},
	    {AAction::FLOAT,
		    {"ressources/mesh/floater/floater.b3d",
			    "ressources/mesh/model/model_text.png",
			    55,
			    &Lemming::_floater}},
	    {AAction::CLIMB,
		    {"ressources/mesh/climber/climber.b3d",
			    "ressources/mesh/model/model_text.png",
			    30,
			    &Lemming::_climber}},
	    {AAction::DIE,
		    {"ressources/mesh/dead/dead.b3d",
			    "",
			    30,
			    &Lemming::_dead}},
    };
    _pos = {position.x * 4, position.y * 4, 0};
    _dir = RIGHT;
    _rot = {0, 0, 0};
    setAction(AAction::WALK);
  }

  void Lemming::setAction(const AAction::ID& actionID)
  {
    Graphic::MeshBlitSpec	blitSpec;

    if (actionID == AAction::STOP && _willDie > 0)
      return ;
    _actionID = actionID;
    blitSpec.path = _actionTab[_actionID].meshPath;
    blitSpec.texture = _actionTab[_actionID].texturePath;
    blitSpec.frameLoop = _actionTab[_actionID].frameLoop;
    blitSpec.animationSpeed = _ANIMATION_SPEED;
    blitSpec.ID = _id;
    blitSpec.position = _pos;
    blitSpec.rotation = _rot;
    blitSpec.scale = {1.8f, 1.8f, 1.8f};

    _graphic->blitMesh(blitSpec);

  }

  bool Lemming::doAction(Sptr<Map> map)
  {
    if (map->getObjType({getPosition().x, getPosition().y + 4, getPosition().z})
		.first == ObjType::END_GATE) {
      _graphic->setVisible(_id, false);
      _win = true;
    }
    return (this->*_actionTab[_actionID].action)(map);
  }

  std::pair<ObjType, Position> &Lemming::getObjTypeAt(Direction const &dir,
					      Position const &pos,
					      Sptr<Map> map)
  {
    static std::unordered_map<Direction, int> LR = {
	    {LEFT, -1},
	    {RIGHT, 1}
    };
    static std::unordered_map<Direction, int> UD = {
	    {DOWN, -1},
	    {UP, 1}
    };
    if (LR.find(dir) != LR.end())
      {
	Position tmpPos = pos;
	tmpPos.x += LR[dir];
	return map->getObjType(tmpPos);
      }
    else if (UD.find(dir) != UD.end())
	{
	  Position tmpPos = pos;
	  tmpPos.y += UD[dir];
	  return map->getObjType(tmpPos);
	}
      else
	throw exception::SyntaxException("Direction not found.");
  }

  bool Lemming::_moveUp()
  {
    _pos.y += ACharacter::_MOVING_SPEED;
    return true;
  }

  bool Lemming::_moveDown()
  {
    float y = _pos.y - ACharacter::_MOVING_SPEED - ACCELERATOR;
    if (y >= 0)
      _pos.y = y;
    return true;
  }

  bool Lemming::_moveLeft()
  {
    _pos.x -= ACharacter::_MOVING_SPEED;
    return true;
  }

  bool Lemming::_moveRight()
  {
    _pos.x += ACharacter::_MOVING_SPEED;
    return true;
  }

  bool Lemming::_movePause()
  {
    _dir = PAUSE;
    return true;
  }

  bool Lemming::isFalling() const
  {
    return (_willDie > 0);
  }

  bool Lemming::isSteppable(ObjType const &type) const
  {
    return (type == ObjType::FLOOR
	    || type == ObjType::PLATFORM
	    || type == ObjType::WALL
	    || type == ObjType::LEM_BLOCK);
  }

  AAction::ID Lemming::getAction() const
  {
    return _actionID;
  }

}