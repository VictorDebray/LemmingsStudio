#include <iostream>
#include "MenuEventReceiver.hpp"

namespace indie
{

MenuEventReceiver::MenuEventReceiver(Sptr<GameInfo> gameInfo) :
	AEventReceiver(gameInfo)
{
}

bool MenuEventReceiver::OnEvent(const irr::SEvent& event)
{
  if (onMainEvent(event)) {
    return true;
  }
  return false;
}

}