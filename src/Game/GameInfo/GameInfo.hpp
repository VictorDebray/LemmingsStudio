#ifndef			GAME_INFO_H
# define		GAME_INFO_H

# include		<map>
# include		"irrlicht.hpp"
# include		"standards.hpp"

namespace indie
{

class			GameInfo
{
  public:
    enum		ID
    {
      MOVE_LEFT = 1,
      MOVE_RIGHT,
      MOVE_UP,
      MOVE_DOWN,
      MOUSE_DOWN,
    };

  private:

    using KeyMap_t = std::map<ID, irr::EKEY_CODE>;

    KeyMap_t		_keyMap;
    ID			_currKey;
    int			_selectedLevel;
    std::string		_pseudo;
    int			_score;
    ScoreTab_t		_scoreTab;

  public:
			GameInfo();
    int			getCurrKeyCode() const;
    int			getKeyCode(const int event) const;
    bool		iterOnKeyMap(const irr::SEvent& irrlichtEvent,
				     int& gameEvent) const;
    void		setSelectedLevel(const int selectedLevel);
    int			getSelectedLevel() const;
    const ScoreTab_t&	getScoreTab() const;
    void		addScore();
    void		increaseScore(const int increment);
};

}

#endif			/* !GAME_INFO_H */