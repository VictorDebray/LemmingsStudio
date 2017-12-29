#ifndef			SCORES_EVENT_RECEIVER_H
# define		SCORES_EVENT_RECEIVER_H

# include		"AEventReceiver.hpp"

namespace indie
{

class			ScoresEventReceiver : public AEventReceiver
{
  public:

  private:
    EventTab		_eventTab;

  public:
  			ScoresEventReceiver(Sptr<GameInfo> gameInfo);

    /* Inherited from IEventReceiver */
    virtual bool	OnEvent(const irr::SEvent&);
};

} // End of namespace


#endif			/* !SCORES_EVENT_RECEIVER_H */