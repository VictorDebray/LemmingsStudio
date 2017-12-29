#ifndef			SETTINGS_H
# define 		SETTINGS_H

# include		"APage.hpp"

namespace indie
{

class			Settings : public APage
{
    void		checkbox();
    void		cameraSettings();
    void		blitKeyBinding(const Position& posText,
    				       const std::string& text,
				       const Position& posKeyBinding,
				       const int event);
    int			modifyKeycode(int keycode) const;

  public:
  			Settings(Sptr<Graphic>,
				 Sptr<SoundEngine>,
				 Sptr<GameInfo>);
			~Settings();
    virtual CoreEvent	loop();
    virtual void	initPage();
    virtual void	closePage();
};

}

#endif			/* !SETTINGS_H */