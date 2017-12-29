#include <iostream>
#include "GameInfo.hpp"

namespace indie
{

GameInfo::GameInfo() :
	_selectedLevel(0),
	_pseudo(""),
	_score(0)
{
  _keyMap[ID::MOVE_UP] = irr::KEY_UP;
  _keyMap[ID::MOVE_DOWN] = irr::KEY_DOWN;
  _keyMap[ID::MOVE_LEFT] = irr::KEY_LEFT;
  _keyMap[ID::MOVE_RIGHT] = irr::KEY_RIGHT;

  for (int i = 0; i < 5; i++) {
    _scoreTab.push_back(0);
  }
}

int GameInfo::getCurrKeyCode() const
{
  return (int)_keyMap.at(_currKey);
}

int GameInfo::getKeyCode(const int event) const
{
  return (int)_keyMap.at((ID)event);
}

bool GameInfo::iterOnKeyMap(const irr::SEvent& irrlichtEvent,
			 int& gameEvent) const
{
  if (irrlichtEvent.EventType == irr::EET_KEY_INPUT_EVENT
      && irrlichtEvent.KeyInput.PressedDown) {
    for (auto& key : _keyMap) {
      if (key.second == irrlichtEvent.KeyInput.Key) {
	gameEvent = key.first;
	return true;
      }
    }
  }

  return false;
}

int GameInfo::getSelectedLevel() const
{
  return _selectedLevel;
}

void GameInfo::setSelectedLevel(const int selectedLevel)
{
  _selectedLevel = selectedLevel;
}

void GameInfo::addScore()
{
  for (int i = 0; i < 5; ++i) {
    if (_score > _scoreTab[i]) {
      for (int j = 4; j > i; --j) {
	_scoreTab[j] = _scoreTab[j - 1];
      }
      _scoreTab[i] = _score;
      _score = 0;
      return ;
    }
  }
}

const ScoreTab_t& GameInfo::getScoreTab() const
{
  return _scoreTab;
}

void GameInfo::increaseScore(const int increment)
{
  _score += increment;
}

}