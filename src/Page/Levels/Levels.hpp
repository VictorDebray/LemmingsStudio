#ifndef			LEVELS_H
# define		LEVELS_H

# include		"APage.hpp"
# include		"Game.hpp"

namespace indie
{

class			Levels : public APage
{
  private:
    void		button();
    Sptr<Game>		_game;

  public:
  			Levels(Sptr<Graphic>,
			       Sptr<SoundEngine> soundEngine,
			       Sptr<GameInfo> gameInfo);
			~Levels();
    virtual CoreEvent	loop();
    virtual void	initPage();
    virtual void	closePage();

};

} // End of namespace

#endif			/* !LEVELS_H */