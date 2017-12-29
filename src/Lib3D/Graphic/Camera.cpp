#include		"Graphic.hpp"
#include <iostream>
namespace indie
{

Camera::Camera(const irr::core::vector3df& pos,
			irr::scene::ISceneManager *sceneManager) :
	_position(pos),
	_sceneManager(sceneManager)
{
  _id = Graphic::_CAMERA_ID;
  _target = pos;
  _target.Z = 0;
  _camera = _sceneManager->addCameraSceneNode(
	0,					// Camera parent
	pos,					// Look from
	_target,				// Look to
	_id);					// Camera ID
}

void Camera::setPosition(const irr::core::vector3df& newPos)
{
  _position = newPos;
  _target = _position;
  _target.Z = 0;
  _camera->setPosition(newPos);
  _camera->setTarget(_target);
}

Position Camera::getPosition() const
{
  Position	pos;

  pos.x = _position.X;
  pos.y = _position.Y;
  pos.z = _position.Z;
  return pos;
}

}
