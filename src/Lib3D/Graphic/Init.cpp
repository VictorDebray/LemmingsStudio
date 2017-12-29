#include "FileHandler.hpp"
#include "Exception.hpp"
#include "Graphic.hpp"
#include "EventReceiverList.hpp"
#include "GameInfo.hpp"

namespace indie
{

const std::string	Graphic::_LEMMINGS_FONT = "ressources/font/forte.png";
const int 		Graphic::_CAMERA_ID = 0;
const std::string	Graphic::_BUTTON_BG = "ressources/img/button_bg_638x80.png";

Graphic::Graphic() :
	_camera(nullptr),
	_state(true)
{
  initGui();
  initEventReceiverTab();
}

Graphic::~Graphic()
{
}

void Graphic::initGui()
{
  _gui = _device->getGUIEnvironment();
  _skin = _gui->getSkin();
  if (!FileHandler::fileExists(_LEMMINGS_FONT)
      || !(_font = _gui->getFont(_LEMMINGS_FONT.c_str()))) {
    throw exception::FileException(FILE_NOT_FOUND);
  }
  _skin->setFont(_font);
}

void Graphic::initEventReceiverTab()
{
  Sptr<AEventReceiver>	eventReceiver;
  Sptr<GameInfo>		gameInfo = std::make_shared<GameInfo>();

  eventReceiver = std::make_shared<MenuEventReceiver>(gameInfo);
  _eventReceiverTab.insert(std::make_pair(EventContext::MENU, eventReceiver));

  eventReceiver = std::make_shared<GameEventReceiver>(gameInfo);
  _eventReceiverTab.insert(std::make_pair(EventContext::GAME, eventReceiver));

  eventReceiver = std::make_shared<SettingsEventReceiver>(gameInfo);
  _eventReceiverTab.insert(std::make_pair(EventContext::SETTINGS, eventReceiver));

  eventReceiver = std::make_shared<LevelsEventReceiver>(gameInfo);
  _eventReceiverTab.insert(std::make_pair(EventContext::LEVELS, eventReceiver));

  eventReceiver = std::make_shared<ScoresEventReceiver>(gameInfo);
  _eventReceiverTab.insert(std::make_pair(EventContext::SCORES, eventReceiver));
}

} // End of namespace