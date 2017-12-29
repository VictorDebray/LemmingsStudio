#ifndef			LEVELS_EVENT_RECEIVER_H
# define		LEVELS_EVENT_RECEIVER_H

# include		"AEventReceiver.hpp"

namespace indie
{

class			LevelsEventReceiver : public AEventReceiver
{
  public:
    enum		ID
    {
      LEVEL1 = 1,
      LEVEL2,
      LEVEL3
    };

  private:
    EventTab		_eventTab;

  public:
  			LevelsEventReceiver(Sptr<GameInfo> gameInfo);

    /* Inherited from IEventReceiver */
    virtual bool	OnEvent(const irr::SEvent&);
};

} // End of namespace


#endif			/* !LEVELS_EVENT_RECEIVER_H */