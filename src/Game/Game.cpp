//
// Created by victor on 5/23/17.
//

#include "Game.hpp"

namespace indie
{

Game::Game(Sptr<Graphic> graphic,
	   Sptr<SoundEngine> soundEngine,
	   Sptr<GameInfo> gameInfo) :
	_graphic(graphic),
	_soundEngine(soundEngine),
	_gameInfo(gameInfo),
	_selectedAction(AAction::ID::WALK)
{
  _graphic->clearScreen();
  initCameraMoveTab();
  _graphic->setCurrEventReceiver(EventContext::GAME);
  _map = std::make_shared<Map>(_graphic->getRootSceneNode(), _graphic);
  _map->initLevel(_gameInfo->getSelectedLevel());
  blitGate(_map->getGatePosition());
  _actionManager = std::make_shared<ActionManager>(_graphic);
  _lemmingManager = std::make_shared<LemmingManager>(_graphic, _gameInfo, _map->getStartPosition());
  _soundEngine->playMusic(SoundEngine::MUSIC_LEVEL1);
}

Game::~Game()
{
  _soundEngine->playMusic(SoundEngine::MUSIC_MENU);
  _gameInfo->setSelectedLevel(0);
  _graphic->clearScreen();
}

void Game::initCameraMoveTab()
{
  _eventTab.insert(std::make_pair(GameInfo::ID::MOVE_LEFT, &Game::moveCamera));
  _eventTab.insert(std::make_pair(GameInfo::ID::MOVE_RIGHT, &Game::moveCamera));
  _eventTab.insert(std::make_pair(GameInfo::ID::MOVE_UP, &Game::moveCamera));
  _eventTab.insert(std::make_pair(GameInfo::ID::MOVE_DOWN, &Game::moveCamera));
  _eventTab.insert(std::make_pair(GameInfo::ID::MOUSE_DOWN, &Game::mouseClick));
}

CoreEvent Game::turn()
{
  CoreEvent			coreEvent;
  GameInfo::ID			event;
  const Sptr<AEventReceiver>	eventReceiver = _graphic->getCurrEventReceiver();
  bool				gameOn = true;

  do {
    coreEvent = eventReceiver->getCoreEvent();
    event = (GameInfo::ID)eventReceiver->getEvent();

    treatEvent(event);
    gameOn = _lemmingManager->turn(_map);
    _graphic->display();
    if (!gameOn) {
      coreEvent = CoreEvent::GOTO_MENU;
    }
  } while (gameOn && (_graphic->getState() && coreEvent != QUIT));

  _lemmingManager->countScore();
  _gameInfo->addScore();
  return coreEvent;
}

void Game::treatEvent(const GameInfo::ID& event)
{
  if (_eventTab.count(event)) {
    (this->*_eventTab[event])(event);
  }
}

void Game::moveCamera(const GameInfo::ID& event)
{
  Position				cameraPos;
  std::map<GameInfo::ID, Position>	cameraMovesTab;

  cameraMovesTab[GameInfo::ID::MOVE_LEFT] = {-1, 0, 0};
  cameraMovesTab[GameInfo::ID::MOVE_RIGHT] = {1, 0, 0};
  cameraMovesTab[GameInfo::ID::MOVE_UP] = {0, 1, 0};
  cameraMovesTab[GameInfo::ID::MOVE_DOWN] = {0, -1, 0};

  cameraPos = _graphic->getCameraPosition();
  for (auto& it : cameraMovesTab) {
    if (event == it.first) {
      cameraPos += it.second;
      _graphic->setCameraPos(cameraPos);
    }
  }
}

void Game::mouseClick(const GameInfo::ID&)
{
  int		tmp;
  Sptr<AAction>	action;
  int		lemmingID;

  if (_selectedAction != AAction::ID::WALK) {
    lemmingID = _graphic->getNodeID();
    _lemmingManager->startLemmingAction(_selectedAction, lemmingID);
    _selectedAction = AAction::ID::WALK;
  }

  tmp = _graphic->getNodeID();
  action = _actionManager->getActionByID(tmp);
  if (action) {
    _selectedAction = action->getActionID();
  }
}

void Game::blitGate(const Position& pos)
{
  Graphic::MeshBlitSpec	blitSpec;

  blitSpec.path = "ressources/mesh/gate.b3d";
  blitSpec.scale = Position(3.0f, 3.0f, 3.0f);
  blitSpec.position = pos;
  _graphic->blitMesh(blitSpec);
}

}