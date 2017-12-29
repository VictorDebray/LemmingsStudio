#include "ActionManager.hpp"
#include "Stop.hpp"
#include "Explode.hpp"
#include "Bash.hpp"
#include "Climb.hpp"
#include "Float.hpp"

namespace indie
{

ActionManager::ActionManager(Sptr<Graphic> graphic) :
	_graphic(graphic)
{
  _actionBar.push_back(std::make_shared<Stop>());
  _actionBar.push_back(std::make_shared<Explode>());
  _actionBar.push_back(std::make_shared<Bash>());
  _actionBar.push_back(std::make_shared<Climb>());
  _actionBar.push_back(std::make_shared<Float>());
  blitActionBar();
}

void ActionManager::blitActionBar()
{
  Graphic::MeshBlitSpec	blitSpec;
  Position		position;

  position = {-13, -24, 34};
  for (auto& action : _actionBar) {

    blitSpec.path = action->getMeshPath();
    blitSpec.texture = action->getTexturePath();
    blitSpec.position = position;
    blitSpec.parentID = Graphic::_CAMERA_ID;
    blitSpec.ID = action->getID();
    _graphic->blitMesh(blitSpec);

    position.x += 7;
  }
}

Sptr<AAction> ActionManager::getActionByID(const int id) const
{
  for (auto& action : _actionBar) {
    if (action->getID() == id) {
      return action;
    }
  }
  return nullptr;
}

}