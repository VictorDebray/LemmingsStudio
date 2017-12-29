#include "Scores.hpp"

namespace indie
{

Scores::Scores(Sptr<Graphic> graphic,
	       Sptr<SoundEngine> soundEngine,
	       Sptr<GameInfo> gameInfo)
	: APage(graphic, soundEngine, gameInfo)
{
  initPage();
}

Scores::~Scores()
{
}

CoreEvent Scores::loop()
{
  CoreEvent			coreEvent;
  const Sptr<AEventReceiver>	eventReceiver = _graphic->getCurrEventReceiver();

  do {
    coreEvent = eventReceiver->getCoreEvent();

   ScoreTab_t		scores;
   int			i = 0;
   wchar_t		buffer[11] = {0};
   Graphic::GUIBlitSpec	blitSpec;

   scores = _gameInfo->getScoreTab();
   blitSpec.uppLeftPos = {125, 100, 0};
   for (auto& score : scores) {
     if (i++ < 5) {
       blitSpec.uppLeftPos.y -= 18;
       Graphic::stringToWide(std::to_string(score), buffer);
       blitSpec.primaryText = buffer;
       _graphic->blitText(blitSpec);
     }
   }

    _graphic->display();
  } while (_graphic->getState()
	   && coreEvent != CoreEvent::QUIT
	   && coreEvent != CoreEvent::GOTO_MENU);

  return coreEvent;
}

void Scores::initPage()
{
  initAPage();
  _graphic->setCurrEventReceiver(EventContext::SCORES);
}

void Scores::closePage()
{
}


} // End of namespace