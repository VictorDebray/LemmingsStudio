#ifndef			SCORES_H
# define		SCORES_H

# include		"APage.hpp"

namespace indie
{

class			Scores : public APage
{
  public:
  			Scores(Sptr<Graphic>,
			       Sptr<SoundEngine>,
			       Sptr<GameInfo>);
			~Scores();
    virtual CoreEvent	loop();
    virtual void	initPage();
    virtual void	closePage();

};

}

#endif			/* !SCORES_H */