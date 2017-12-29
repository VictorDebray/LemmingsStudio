#include "GameEventReceiver.hpp"

namespace indie
{

GameEventReceiver::GameEventReceiver(Sptr<GameInfo> gameInfo) :
	AEventReceiver(gameInfo)
{
}

bool GameEventReceiver::OnEvent(const irr::SEvent& event)
{
  if (onMainEvent(event)) {
    return true;
  }

  if (_gameInfo->iterOnKeyMap(event, _event)) {
    return true;
  }

  /* Mouse */
  if (event.EventType == irr::EET_MOUSE_INPUT_EVENT) {
     switch (event.MouseInput.Event) {
       case irr::EMIE_LMOUSE_PRESSED_DOWN :
  	_mouseState.leftButtonDown = true;
  	_event = GameInfo::ID::MOUSE_DOWN;
  	return true;
      case irr::EMIE_LMOUSE_LEFT_UP :
  	_mouseState.leftButtonDown = false;
  	return true;
      case irr::EMIE_MOUSE_MOVED:
  	_mouseState.pos.x = (float)event.MouseInput.X;
  	_mouseState.pos.y = (float)event.MouseInput.Y;
  	return true;
      default:
  	break;
      }
    }

  return false;
}

}