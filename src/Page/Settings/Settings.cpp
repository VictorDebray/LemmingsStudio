#include "Settings.hpp"
#include "SettingsEventReceiver.hpp"

namespace indie
{

Settings::Settings(Sptr<Graphic> graphic,
		   Sptr<SoundEngine> soundEngine,
		   Sptr<GameInfo> gameInfo)
	: APage(graphic, soundEngine, gameInfo)
{
}

Settings::~Settings()
{
}

CoreEvent Settings::loop()
{
  CoreEvent			coreEvent;
  int				event;
  const Sptr<AEventReceiver>	eventReceiver = _graphic->getCurrEventReceiver();

  do {
    coreEvent = eventReceiver->getCoreEvent();
    event = eventReceiver->getEvent();

    if (event == SettingsEventReceiver::ID::MUSIC_ON)
      _soundEngine->setMusicActive();

    _graphic->display();
  } while (_graphic->getState()
	   && coreEvent != CoreEvent::QUIT
	   && coreEvent != CoreEvent::GOTO_MENU);

  return coreEvent;
}

void Settings::initPage()
{
  initAPage();
  checkbox();
  cameraSettings();
  _graphic->setCurrEventReceiver(EventContext::SETTINGS);
}

void Settings::checkbox()
{
  Graphic::GUIBlitSpec	blitSpec;

  blitSpec.eventID = SettingsEventReceiver::ID::MUSIC_ON;
  blitSpec.uppLeftPos = {150, 150, 0};
  blitSpec.trigger = _soundEngine->isMusicActive();
  _graphic->blitCheckbox(blitSpec);

  blitSpec.uppLeftPos = {75, 90, 0};
  blitSpec.primaryText = (wchar_t *)L"Activate/Desactivate   the   music";
  _graphic->blitText(blitSpec);
}

void Settings::blitKeyBinding(const Position& posText,
			      const std::string& text,
			      const Position& posKeyBind,
			      const int event)
{
  /* Text */
  Graphic::GUIBlitSpec	blitSpec;
  wchar_t		buffer[40] = {0};

  blitSpec.uppLeftPos = posText;
  Graphic::stringToWide(text, buffer);
  blitSpec.primaryText = buffer;
  _graphic->blitText(blitSpec);

  /* KeyCode */
  Sptr<AEventReceiver>	eventReceiver = _graphic->getCurrEventReceiver();
  int			keyCode = eventReceiver->getKeyCode(event);

  blitSpec.uppLeftPos = posKeyBind;
  memset(buffer, 0, 40 * sizeof(wchar_t));
  swprintf(buffer, 10, L"%c", modifyKeycode(keyCode));
  blitSpec.primaryText = buffer;
  _graphic->blitText(blitSpec);
}

int Settings::modifyKeycode(int keycode) const
{
  switch (keycode) {
    case '%' :
      return '<';
    case '&' :
      return '^';
    case '\'' :
      return '>';
    case '(' :
      return '.';
    default:
      return keycode;
  }
}

void Settings::cameraSettings()
{
  blitKeyBinding({28, 65, 0}, "Move   Left", {50, 65, 0}, GameInfo::ID::MOVE_LEFT);
  blitKeyBinding({128, 65, 0}, "Move   Right", {150, 65, 0}, GameInfo::ID::MOVE_RIGHT);
  blitKeyBinding({28, 55, 0}, "Move   Up", {50, 55, 0}, GameInfo::ID::MOVE_UP);
  blitKeyBinding({126, 55, 0}, "Move   Down", {150, 55, 0}, GameInfo::ID::MOVE_DOWN);
}

void Settings::closePage()
{
}

}