#ifndef			MENU_EVENT_RECEIVER_HPP
# define		MENU_EVENT_RECEIVER_HPP

# include		"AEventReceiver.hpp"

namespace indie
{

class			MenuEventReceiver : public AEventReceiver
{
  private:
    EventTab		_eventTab;

  public:
  			MenuEventReceiver(Sptr<GameInfo> gameInfo);

    /* Inherited from IEventReceiver */
    virtual bool	OnEvent(const irr::SEvent&);
};

} // End of namespace


#endif			/* !MENU_EVENT_RECEIVER_HPP */