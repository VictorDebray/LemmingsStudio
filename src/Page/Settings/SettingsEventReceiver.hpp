#ifndef			SETTINGS_EVENT_RECEIVER_H
# define		SETTINGS_EVENT_RECEIVER_H

# include		"AEventReceiver.hpp"

namespace indie
{

class			SettingsEventReceiver : public AEventReceiver
{
  public:
    enum		ID
    {
      MUSIC_ON = 1,
    };

  private:
    EventTab		_eventTab;

  public:
  			SettingsEventReceiver(Sptr<GameInfo> gameInfo);

    /* Inherited from IEventReceiver */
    virtual bool	OnEvent(const irr::SEvent&);

};

} // End of namespace


#endif			/* !SETTINGS_EVENT_RECEIVER_H */