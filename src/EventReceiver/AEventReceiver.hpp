#ifndef			AEVENT_RECEIVER_H
# define		AEVENT_RECEIVER_H

# include		<memory>
# include		"GameInfo.hpp"
# include		"irrlicht.hpp"
# include		"standards.hpp"

namespace indie
{

class			AEventReceiver : public irr::IEventReceiver
{
  protected:
    using EventTab = std::map<int, std::vector<int>>;

    Sptr<GameInfo>	_gameInfo;
    EventTab		_coreEventTab;
    CoreEvent		_coreEvent;
    int			_event;
    MouseState		_mouseState;

    bool		onMainEvent(const irr::SEvent&);
  public:
  			AEventReceiver(Sptr<GameInfo> gameInfo);
    CoreEvent		getCoreEvent();
    int			getEvent();
    MouseState		getMouseState() const;
    int			getKeyCode(const int event) const;

};

} // End of namespace


#endif			/* !AEVENT_RECEIVER_H */