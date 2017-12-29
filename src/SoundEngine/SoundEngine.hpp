#ifndef			SOUND_ENGINE_H
# define		SOUND_ENGINE_H

# include		<iostream>
# include		"irrKlang.h"

namespace indie
{

class			SoundEngine
{
  public:
    static const std::string	MUSIC_MENU;
    static const std::string	MUSIC_LEVEL1;

  private:
    irrklang::ISoundEngine	*_engine;
    bool			_musicActive;

  public:
  			SoundEngine();
			~SoundEngine();
    void		playMusic(const std::string&);
    bool		isMusicActive();
    void		setMusicActive();
};

}

#endif			/* !SOUND_ENGINE_H */
