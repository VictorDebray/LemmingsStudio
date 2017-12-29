#include "standards.hpp"
#include "Menu.hpp"
#include "ACharacter.hpp"

namespace indie
{

const std::string	Menu::_BG = "ressources/img/menu_bg.jpg";
const std::string	Menu::_LOGO = "ressources/img/logo_freak.png";

Menu::Menu(Sptr<Graphic> graphic,
	   Sptr<SoundEngine> soundEngine,
	   Sptr<GameInfo> gameInfo) :
	APage(graphic, soundEngine, gameInfo, _BG),
	_lemming(std::make_shared<Lemming>(graphic, _gameInfo))
{
  _graphic->setCamera(Position(0, 0, -100));
  initPage();
}

Menu::~Menu()
{
}

void Menu::initPage()
{
  _graphic->setCurrEventReceiver(EventContext::MENU);
  initAPage();
  logo();
  button();
}

void Menu::closePage()
{
}

CoreEvent Menu::loop()
{
  CoreEvent	coreEvent;

  do {
    coreEvent = _graphic->getCurrEventReceiver()->getCoreEvent();
    rotateRightAnim();
    _graphic->display();
  } while (_graphic->getState() && coreEvent == CoreEvent::NONE);

  return coreEvent == CoreEvent::QUIT ? CoreEvent::QUIT_PRG : coreEvent;
}

void Menu::logo()
{
  indie::Position	pos;

  pos.x = 350;
  pos.y = 20;
  _graphic->blitImage(_LOGO, pos);
}

void Menu::rotateRightAnim()
{
  Position	rot;

  rot = _lemming->getRotation();
  rot.y -= 0.5f;
  if (rot.y == -360) {
    rot.y = 0;
  }
  _lemming->setRotation(rot);
  _graphic->getNodeByID(_lemming->getID())
	  ->setRotation(_graphic->posToVector3df(_lemming->getRotation()));
}

void Menu::rightAnim()
{
  Graphic::MeshBlitSpec	blitSpec;

  blitSpec.path = "ressources/mesh/walker/walker.b3d";
  blitSpec.texture = "ressources/mesh/model/model_text.png";
  blitSpec.animationSpeed = ACharacter::_ANIMATION_SPEED / 2;
  blitSpec.ID = _lemming->getID();
  blitSpec.parentID = Graphic::_CAMERA_ID;
  blitSpec.frameLoop = 30;
  blitSpec.parentID = 0;
  blitSpec.position = Position(3.3, -2.7, 5);
  blitSpec.rotation = _lemming->getRotation();
  _graphic->blitMesh(blitSpec);
}

void Menu::button()
{
  Position	pos;

  pos.x = 150;
  pos.y = 300;
  _graphic->blitButton(Graphic::GUIBlitSpec(CoreEvent::GOTO_PLAY, (wchar_t *)L"\nPlay", pos));
  pos.y += 125;
  _graphic->blitButton(Graphic::GUIBlitSpec(CoreEvent::GOTO_LEVELS, (wchar_t *)L"\nLevels", pos));
  pos.y += 125;
  _graphic->blitButton(Graphic::GUIBlitSpec(CoreEvent::GOTO_SETTINGS, (wchar_t *)L"\nSettings", pos));
  pos.y += 125;
  _graphic->blitButton(Graphic::GUIBlitSpec(CoreEvent::GOTO_SCORES, (wchar_t *)L"\nScores", pos));
  rightAnim();
}

}