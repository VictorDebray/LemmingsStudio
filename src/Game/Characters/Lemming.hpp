//
// Created by victor on 5/23/17.
//

#ifndef INDIE_STUDIO_LEMMING_HH
# define INDIE_STUDIO_LEMMING_HH

# include "ACharacter.hpp"
# include "AAction.hpp"
# include "Timer.hpp"
# include "Map.hpp"
# include "GameInfo.hpp"

namespace indie
{
  class Lemming : public ACharacter
  {
   private:
    static const float 		ACCELERATOR;
    static const float 		HEIGHT_TO_DIE;

    using jobFuncPtr_t = bool (Lemming::*)(Sptr<Map>);

    struct			Action
    {
      std::string		meshPath;
      std::string		texturePath;
      int			frameLoop;
      jobFuncPtr_t		action;
    };

    using actionTab_t = std::map<AAction::ID, Action>;

    Sptr<GameInfo>		_gameInfo;
    actionTab_t			_actionTab;
    AAction::ID 		_actionID;
    float	 		_willDie;
    Sptr<Timer>			_timer;
    bool			_climbing;

   public:
				Lemming(Sptr<Graphic>,
					Sptr<GameInfo>,
					Position const &startPosition = {0,0,0});

    bool			_moveUp();
    bool			_moveDown();
    bool			_moveLeft();
    bool			_moveRight();
    bool			_movePause();
    bool			isFalling() const;
    bool 			isSteppable(ObjType const &type) const;

    void			setAction(const AAction::ID&);
    AAction::ID			getAction() const;
    bool 			doAction(Sptr<Map> map);
    std::pair<ObjType, Position>	&getObjTypeAt(Direction const &dir,
						      Position const &,
						      Sptr<Map>);

    bool	 		_walker(Sptr<Map> map);
    bool	 		_stopper(Sptr<Map> map);
    bool 			_basher(Sptr<Map> map);
    bool 			_exploder(Sptr<Map> map);
    bool 			_floater(Sptr<Map> map);
    bool 			_climber(Sptr<Map> map);
    bool			_dead(Sptr<Map> map);
  };
}

#endif //INDIE_STUDIO_LEMMING_HH
