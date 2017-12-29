#include "Core.hpp"

namespace indie
{

void Core::loop()
{
  CoreEvent	event;

  while (_graphic->getState()) {
    event = _currPage->loop();
    treatCoreEvent(event);
  }
}

void Core::treatCoreEvent(const CoreEvent& event)
{
  if (_eventTab.count(event)) {
    (this->*_eventTab[event])(event);
  }
}

void Core::quit(const CoreEvent& event)
{
  if (event == CoreEvent::QUIT) {
    gotoPage(CoreEvent::GOTO_MENU);
  } else {
    _graphic->quit();
  }
}

void Core::gotoPage(const CoreEvent& idPage)
{
  _graphic->clearScreen();
  _currPage->closePage();
  if (_pageTab[idPage] != _currPage) {
    _currPage = _pageTab[idPage];
  }
  _currPage->initPage();
}

void Core::setMusicActive(const CoreEvent&)
{
  _soundEngine->setMusicActive();
}

} // End of namespace