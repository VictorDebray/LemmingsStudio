#include "Levels.hpp"
#include "LevelsEventReceiver.hpp"

namespace indie
{

Levels::Levels(Sptr<Graphic> graphic,
	       Sptr<SoundEngine> soundEngine,
	       Sptr<GameInfo> gameInfo)
	: APage(graphic, soundEngine, gameInfo)
{
  initPage();
}

Levels::~Levels()
{
}

void Levels::initPage()
{
  _game = nullptr;
  _graphic->setCurrEventReceiver(EventContext::LEVELS);
  initAPage();
  button();
}

CoreEvent Levels::loop()
{
  CoreEvent	coreEvent;
  int		event;
  const Sptr<AEventReceiver>	eventReceiver = _graphic->getCurrEventReceiver();

  do {
    coreEvent = eventReceiver->getCoreEvent();
    event = eventReceiver->getEvent() - 1;

    /* event holds the number of selected level */
    if (event != -1) {
      _gameInfo->setSelectedLevel(event);
      _game = std::make_shared<Game>(_graphic, _soundEngine, _gameInfo);
      return _game->turn();
    }

    _graphic->display();
  } while (_graphic->getState() && coreEvent == CoreEvent::NONE);

  return coreEvent;
}

void Levels::button()
{
  Position	pos;

  pos.x = 150;
  pos.y = 300;
  _graphic->blitButton(Graphic::GUIBlitSpec(
	  LevelsEventReceiver::ID::LEVEL1, (wchar_t *)L"\nLevel 1", pos));
  pos.y += 125;
  _graphic->blitButton(Graphic::GUIBlitSpec(
	  LevelsEventReceiver::ID::LEVEL2, (wchar_t *)L"\nLevel 2", pos));
  pos.y += 125;
  _graphic->blitButton(Graphic::GUIBlitSpec(
	  LevelsEventReceiver::ID::LEVEL3, (wchar_t *)L"\nLevel 3", pos));
}

void Levels::closePage()
{
  if (_game) {
    _game.reset();
  }
}

}