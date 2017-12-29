//
// Created by victor on 5/23/17.
//

#include "LemmingManager.hpp"

namespace indie
{

  LemmingManager::LemmingManager(Sptr<Graphic> graphic,
  				 Sptr<GameInfo> gameInfo,
				 Position const &startPosition,
				 size_t nbLemmings) :
	_graphic(graphic),
	_gameInfo(gameInfo),
	_startPosition(startPosition),
	_nbLemmings(nbLemmings),
	_timer(std::make_shared<Timer>())
  {
  }

  bool LemmingManager::turn(Sptr<Map> map)
  {
    if (_lemmingsL.size() < _nbLemmings
	&& _timer->elapsed() >= 3.00)
      {
	_lemmingsL.push_back(
		std::make_shared<Lemming>(_graphic, _gameInfo, _startPosition));
	_timer->reset();
      }

    for (auto& lemming : _lemmingsL) {
      /* Do Action & eventually erases lemming from Graphic */
      if (!lemming->doAction(map)) {
        lemming->setAction(AAction::DIE);
      }
      /* Update position of current lemming's mesh */
      _graphic->getNodeByID(lemming->getID())
	      ->setPosition(_graphic->posToVector3df(lemming->getPosition()));
      _graphic->getNodeByID(lemming->getID())
	      ->setRotation(_graphic->posToVector3df(lemming->getRotation()));
    }

    unsigned int	died = 0;
    for (auto& it : _lemmingsL) {
      if (!it->isAlive()) {
	++died;
      }
    }
    if (died == _nbLemmings) {
      return false;
    }

    return true;
  }

void LemmingManager::startLemmingAction(const AAction::ID actionID,
					const int lemmingID)
{
  for (auto& lemming : _lemmingsL) {
    if (lemming->getID() == lemmingID) {
      lemming->setAction(actionID);
    }
  }
}

void LemmingManager::countScore()
{
  for (auto& it : _lemmingsL) {
    if (it->isAlive() && it->getWin()) {
      _gameInfo->increaseScore(10);
    }
  }
}

}