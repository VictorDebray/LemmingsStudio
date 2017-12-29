#ifndef			PLAY_H
# define		PLAY_H

# include		"APage.hpp"
# include		"Game.hpp"

namespace indie
{

class			Play : public APage
{
  private:
    Sptr<Game>		_game;

  public:
  			Play(Sptr<Graphic>,
			     Sptr<SoundEngine>,
			     Sptr<GameInfo>);
			~Play();
    virtual CoreEvent	loop();
    virtual void	initPage();
    virtual void	closePage();
};

}


#endif			/* !PLAY_H */