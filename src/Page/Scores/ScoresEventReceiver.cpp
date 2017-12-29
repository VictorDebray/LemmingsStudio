#include <iostream>
#include "ScoresEventReceiver.hpp"

namespace indie
{

ScoresEventReceiver::ScoresEventReceiver(Sptr<GameInfo> gameInfo) :
	AEventReceiver(gameInfo)
{
}

bool ScoresEventReceiver::OnEvent(const irr::SEvent& event)
{
  if (onMainEvent(event)) {
    return true;
  }

  return false;
}

}