//
// Created by victor on 5/23/17.
//

#ifndef INDIE_STUDIO_GAME_H
# define INDIE_STUDIO_GAME_H

# include <list>
# include <memory>
# include "LemmingManager.hpp"
# include "ActionManager.hpp"
# include "Graphic.hpp"
# include "GameInfo.hpp"
# include "SoundEngine.hpp"

namespace indie
{
  class Game
  {
   private:
    using gameFunc = void (Game::*)(const GameInfo::ID&);

    Sptr<Graphic>		_graphic;
    Sptr<LemmingManager>	_lemmingManager;
    Sptr<ActionManager>		_actionManager;
    Sptr<SoundEngine>		_soundEngine;
    Sptr<GameInfo>		_gameInfo;
    AAction::ID			_selectedAction;
    Sptr<Map>			_map;

    std::map<GameInfo::ID, gameFunc>	_eventTab;

    void			initCameraMoveTab();
    void			treatEvent(const GameInfo::ID&);
    void			moveCamera(const GameInfo::ID&);
    void			mouseClick(const GameInfo::ID&);
    void			blitGate(const Position&);
   public:
				Game(Sptr<Graphic>,
				     Sptr<SoundEngine>,
				     Sptr<GameInfo>);
				~Game();

    CoreEvent			turn();
  };
}

#endif //INDIE_STUDIO_GAME_H
