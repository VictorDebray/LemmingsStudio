//
// Created by victor on 5/23/17.
//

#ifndef INDIE_STUDIO_LEMMINGMANAGER_HPP
# define INDIE_STUDIO_LEMMINGMANAGER_HPP

# include <vector>
# include "Graphic.hpp"
# include "Lemming.hpp"
# include "Timer.hpp"
# include "standards.hpp"
# include "GameInfo.hpp"

namespace indie
{
  class LemmingManager
  {
   private:
    std::vector<Sptr<Lemming>>	_lemmingsL;
    Sptr<Graphic>		_graphic;
    Sptr<GameInfo>		_gameInfo;
    Position			_startPosition;
    size_t			_nbLemmings;
    Sptr<Timer>			_timer;

   public:
    LemmingManager(Sptr<Graphic> graphic,
		   Sptr<GameInfo> gameInfo,
		   Position const &startPosition,
		   size_t nbLemmings = 10);

    void			displayLemmings();
    bool			turn(Sptr<Map> map);
    void			startLemmingAction(const AAction::ID ActionID,
						   const int LemmingID);
    void			countScore();
  };
}

#endif //INDIE_STUDIO_LEMMINGMANAGER_HPP
