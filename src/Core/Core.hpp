#ifndef			CORE_H
# define		CORE_H

# include		<memory>
# include		<map>
# include		"Graphic.hpp"
# include		"Pages.hpp"
# include		"SoundEngine.hpp"
# include		"GameInfo.hpp"

namespace indie
{

class			Core
{
  private:
    Sptr<Graphic>			_graphic;
    std::map<int, Sptr<IPage>>		_pageTab;
    Sptr<IPage>				_currPage;
    std::map<int, eventFunc<Core>>	_eventTab;
    Sptr<SoundEngine>			_soundEngine;
    Sptr<GameInfo>			_gameInfo;

    void		initPageTab();
    void		initEventTab();
    void		treatCoreEvent(const CoreEvent& notif = NONE);
    void		gotoPage(const CoreEvent&);
    void		quit(const CoreEvent&);
    void		setMusicActive(const CoreEvent&);

  public:
  			Core();
			~Core();
    void		loop();
};

}

#endif			/* !CORE_H */