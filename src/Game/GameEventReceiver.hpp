#ifndef			GAME_EVENT_RECEIVER
# define		GAME_EVENT_RECEIVER

# include		<map>
# include		"AEventReceiver.hpp"

namespace indie
{

class			GameEventReceiver : public AEventReceiver
{
  private:
    EventTab		_eventTab;

  public:
  			GameEventReceiver(Sptr<GameInfo> gameInfo);

    /* Inherited from IEventReceiver */
    virtual bool	OnEvent(const irr::SEvent&);

};

} // End of namespace


#endif			/* !GAME_EVENT_RECEIVER */