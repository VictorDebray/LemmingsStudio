#include "SettingsEventReceiver.hpp"

namespace indie
{

SettingsEventReceiver::SettingsEventReceiver(Sptr<GameInfo> gameInfo) :
	AEventReceiver(gameInfo)
{
  _eventTab[irr::gui::EGET_CHECKBOX_CHANGED] = {
 	ID::MUSIC_ON
 	};
}

bool SettingsEventReceiver::OnEvent(const irr::SEvent& event)
{
  if (onMainEvent(event)) {
    return true;
  }

  if (event.EventType == irr::EET_GUI_EVENT) {
    int	id;
    id = event.GUIEvent.Caller->getID();

    /* Events */
    for (auto& eventType : _eventTab) {
      if (eventType.first == event.GUIEvent.EventType) {
	for (auto& eventID : eventType.second) {
	  if (eventID == id) {
	    _event = eventID;
	    return true;
	  }
	}
      }
    }

  }

  return false;
}

}