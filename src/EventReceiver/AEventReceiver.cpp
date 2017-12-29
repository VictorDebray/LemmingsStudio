#include <iostream>
#include "AEventReceiver.hpp"
#include "standards.hpp"

namespace indie
{

AEventReceiver::AEventReceiver(Sptr<GameInfo> gameInfo) :
	_gameInfo(gameInfo),
	_coreEvent(CoreEvent::NONE),
	_event(0)
{
  _coreEventTab[irr::gui::EGET_BUTTON_CLICKED] = {
	CoreEvent::GOTO_PLAY,
	CoreEvent::GOTO_MENU,
	CoreEvent::GOTO_LEVELS,
	CoreEvent::GOTO_SETTINGS,
	CoreEvent::GOTO_SCORES,
	};
}

bool	AEventReceiver::onMainEvent(const irr::SEvent& event)
{

  if (event.EventType == irr::EET_KEY_INPUT_EVENT
      && event.KeyInput.PressedDown) {
    _coreEvent = CoreEvent::NONE;
    switch (event.KeyInput.Key) {
      case irr::KEY_ESCAPE :
	_coreEvent = CoreEvent::QUIT;
	return true;
      default:
	break;
    }
  }

  if (event.EventType == irr::EET_GUI_EVENT) {
    int	id;
    id = event.GUIEvent.Caller->getID();
    for (auto& eventType : _coreEventTab) {
      if (eventType.first == event.GUIEvent.EventType) {
        _coreEvent = CoreEvent::NONE;
	for (auto& eventID : eventType.second) {
	  if (eventID == id) {
	    _coreEvent = (CoreEvent)eventID;
	    return true;
	  }
	}
      }
    }
  }

  return false;
}

CoreEvent AEventReceiver::getCoreEvent()
{
  CoreEvent	tmp = _coreEvent;

  _coreEvent = CoreEvent::NONE;
  return tmp;
}

int AEventReceiver::getEvent()
{
  int		tmp = _event;

  _event = 0;
  return tmp;
}

MouseState AEventReceiver::getMouseState() const
{
  return _mouseState;
}

int AEventReceiver::getKeyCode(const int event) const
{
  if (event == CoreEvent::NONE) {
    return _gameInfo->getCurrKeyCode();
  }
  return _gameInfo->getKeyCode(event);
}

} // End of namespace