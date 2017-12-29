#include "APage.hpp"

namespace indie
{

APage::APage(Sptr<Graphic> graphic,
	     Sptr<SoundEngine> soundEngine,
	     Sptr<GameInfo> gameInfo,
	     const std::string& bgPath) :
	_graphic(graphic),
	_soundEngine(soundEngine),
	_gameInfo(gameInfo),
	_bgPath(bgPath)
{
}

APage::~APage()
{
}

void APage::initAPage()
{
  background();
  staticGUI();
}

void APage::background()
{
  Position	pos;

  pos.x = pos.y = 0;

  _graphic->blitImage(_bgPath, pos);
}

void APage::staticGUI()
{
  indie::Position	pos;

  pos.x = 150;
  pos.y = 800;
  _graphic->blitButton(Graphic::GUIBlitSpec(CoreEvent::GOTO_MENU, (wchar_t *)L"\nMenu", pos));
}

} // End of namespace
