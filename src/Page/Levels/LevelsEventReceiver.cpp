#include <iostream>
#include "LevelsEventReceiver.hpp"

namespace indie
{

LevelsEventReceiver::LevelsEventReceiver(Sptr<GameInfo> gameInfo) :
	AEventReceiver(gameInfo)
{
  _eventTab[irr::gui::EGET_BUTTON_CLICKED] = {
	ID::LEVEL1,
	ID::LEVEL2,
	ID::LEVEL3,
	};
}

bool LevelsEventReceiver::OnEvent(const irr::SEvent& event)
{
  if (onMainEvent(event)) {
    return true;
  }

  if (event.EventType == irr::EET_GUI_EVENT) {
    int	id;
    id = event.GUIEvent.Caller->getID();

    for (auto& eventType : _eventTab) {
      if (eventType.first == event.GUIEvent.EventType) {
	for (auto& eventID : eventType.second) {
	  if (eventID == id) {
	    _event = (int)eventID;
	    _gameInfo->setSelectedLevel((int)eventID);
	    return true;
	  }
	}
      }
    }
  }

  return false;
}

}