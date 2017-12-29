#include "Core.hpp"

namespace indie
{

Core::Core() :
	_graphic(std::make_shared<Graphic>()),
	_soundEngine(std::make_shared<SoundEngine>()),
	_gameInfo(std::make_shared<GameInfo>())
{
  initPageTab();
  initEventTab();
  _currPage = _pageTab[CoreEvent::GOTO_MENU];
}

Core::~Core()
{
}

void Core::initPageTab()
{
  _pageTab.insert(std::make_pair(CoreEvent::GOTO_PLAY,
		std::make_shared<Play>(_graphic, _soundEngine, _gameInfo)));
  _pageTab.insert(std::make_pair(CoreEvent::GOTO_LEVELS,
		std::make_shared<Levels>(_graphic, _soundEngine, _gameInfo)));
  _pageTab.insert(std::make_pair(CoreEvent::GOTO_SETTINGS,
		std::make_shared<Settings>(_graphic, _soundEngine, _gameInfo)));
  _pageTab.insert(std::make_pair(CoreEvent::GOTO_SCORES,
		std::make_shared<Scores>(_graphic, _soundEngine, _gameInfo)));
  _pageTab.insert(std::make_pair(CoreEvent::GOTO_MENU,
		std::make_shared<Menu>(_graphic, _soundEngine, _gameInfo)));
}

void Core::initEventTab()
{
  _eventTab.insert(std::make_pair(CoreEvent::QUIT, &Core::quit));
  _eventTab.insert(std::make_pair(CoreEvent::QUIT_PRG, &Core::quit));
  _eventTab.insert(std::make_pair(CoreEvent::GOTO_MENU, &Core::gotoPage));
  _eventTab.insert(std::make_pair(CoreEvent::GOTO_PLAY, &Core::gotoPage));
  _eventTab.insert(std::make_pair(CoreEvent::GOTO_LEVELS, &Core::gotoPage));
  _eventTab.insert(std::make_pair(CoreEvent::GOTO_SETTINGS, &Core::gotoPage));
  _eventTab.insert(std::make_pair(CoreEvent::GOTO_SCORES, &Core::gotoPage));
}

}