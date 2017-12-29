#include "Play.hpp"

namespace indie
{

Play::Play(Sptr<Graphic> graphic,
	   Sptr<SoundEngine> soundEngine,
	   Sptr<GameInfo> gameInfo)
	: APage(graphic, soundEngine, gameInfo)
{
}

Play::~Play()
{
}

CoreEvent Play::loop()
{
  return _game->turn();
}

void Play::initPage()
{
  _game = std::make_shared<Game>(_graphic, _soundEngine, _gameInfo);
}

void Play::closePage()
{
  _game.reset();
}

} // End of namespace
