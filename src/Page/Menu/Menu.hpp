#ifndef			MENU_H
# define 		MENU_H

# include		"APage.hpp"
# include		"Lemming.hpp"

namespace indie
{

class			Menu : public APage
{
  private:
    static const std::string	_BG;
    static const std::string	_LOGO;

    Sptr<Lemming>	_lemming;

    void		logo();
    void		background();
    void		button();
    void		rightAnim();
    void		rotateRightAnim();
  public:
  			Menu(Sptr<Graphic>,
			     Sptr<SoundEngine>,
			     Sptr<GameInfo>);
			~Menu();
    virtual CoreEvent	loop();
    virtual void	initPage();
    virtual void	closePage();
};

} // End of namespace

#endif			/* !MENU_H */