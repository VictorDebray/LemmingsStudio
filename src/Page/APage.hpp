#ifndef				APAGE_H
# define			APAGE_H

# include			"Graphic.hpp"
# include			"IPage.hpp"
# include			"SoundEngine.hpp"
# include			"GameInfo.hpp"

namespace indie
{

class				APage : public IPage
{
  protected:
    Sptr<Graphic>		_graphic;
    Sptr<SoundEngine>		_soundEngine;
    Sptr<GameInfo>		_gameInfo;
    std::string			_bgPath;
    std::vector<int>		_img2DTab;

    void			initAPage();
    void			background();
    void			staticGUI();
  public:
  				APage(Sptr<Graphic> graphic,
				      Sptr<SoundEngine> soundEngine,
				      Sptr<GameInfo> gameInfo,
				      const std::string& bgPath = "ressources/img/ground_1600x900.png");
    virtual			~APage();
};

} //End of namespace

#endif				/* !APAGE_H */