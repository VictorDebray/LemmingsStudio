#include "Graphic.hpp"

namespace indie
{

bool Graphic::getState() const
{
  return (_state);
}

Sptr<AEventReceiver> Graphic::getCurrEventReceiver() const
{
  return _currEventReceiver;
}

void Graphic::setCurrEventReceiver(indie::EventContext eC)
{
  _currEventReceiver = _eventReceiverTab[eC];
  _device->setEventReceiver(_currEventReceiver.get());
}

void Graphic::setCamera(const Position& pos)
{
  irr::core::vector3df	irrPos(pos.x, pos.y, pos.z);

  _camera = std::make_shared<Camera>(irrPos, _sceneManager);
}

void Graphic::setCameraPos(const Position& tmp)
{
  irr::core::vector3df	newPos(tmp.x, tmp.y, tmp.z);

  _camera->setPosition(newPos);
}

Position Graphic::getCameraPosition() const
{
  return _camera->getPosition();
}

irr::scene::ISceneNode *Graphic::getNodeByID(const int id)
{
  return _sceneManager->getSceneNodeFromId(id);
}

int Graphic::getNodeID()
{
  irr::scene::ISceneNode		*selectedNode;
  irr::core::position2d<irr::s32>	pos;

  pos.X = getCurrEventReceiver()->getMouseState().pos.x;
  pos.Y = getCurrEventReceiver()->getMouseState().pos.y;
  selectedNode = _collisionManager->getSceneNodeFromScreenCoordinatesBB(pos);
  return (selectedNode->getID());
}

const irr::core::vector3df Graphic::posToVector3df(const Position& pos)
{
  return (irr::core::vector3df(pos.x, pos.y, pos.z));
}

void Graphic::stringToWide(const std::string& sInput, wchar_t *dest)
{ 
   size_t* sizeOut = new size_t;
   size_t sizeInWords = 256;
   
   const char* cStr;
   cStr = sInput.c_str();
   //mbstowcs_s( sizeOut, m_wCharBuffer, sizeInWords, cStr, strlen(cStr)+1);
   mbstowcs(dest, cStr, sizeInWords);
   
   delete sizeOut;
}

irr::scene::ISceneNode* Graphic::getRootSceneNode()
{
  return _sceneManager->getRootSceneNode();
}

irr::scene::ISceneManager* Graphic::getSceneManager()
{
  return _sceneManager;
}

void Graphic::setVisible(const int nodeID, bool val)
{
  getNodeByID(nodeID)->setVisible(val);
}

} // End of namespace