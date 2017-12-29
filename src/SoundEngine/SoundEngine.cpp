#include "SoundEngine.hpp"
#include "FileHandler.hpp"
#include "Exception.hpp"
#include "standards.hpp"
#include <iostream>

namespace indie
{

const std::string SoundEngine::MUSIC_LEVEL1 = "ressources/music/levels.ogg";
const std::string SoundEngine::MUSIC_MENU = "ressources/music/menu_title.ogg";

SoundEngine::SoundEngine() :
	_musicActive(true)
{
  _engine = irrklang::createIrrKlangDevice();
  if (!FileHandler::fileExists(MUSIC_MENU.c_str())) {
    throw exception::FileException(FILE_NOT_FOUND);
  }
  playMusic(MUSIC_MENU);
}

SoundEngine::~SoundEngine()
{
  _engine->drop();
}

void SoundEngine::playMusic(const std::string& path)
{
  if (!FileHandler::fileExists(path.c_str())) {
    throw exception::FileException(FILE_NOT_FOUND);
  }
  _engine->stopAllSounds();
  if (_musicActive) {
    _engine->play2D(path.c_str(), true);
  }
}

bool SoundEngine::isMusicActive()
{
  return _musicActive;
}

void SoundEngine::setMusicActive()
{
  _musicActive = !_musicActive;
  if (!_musicActive) {
    _engine->stopAllSounds();
  } else {
    playMusic(MUSIC_MENU);
  }
}

}