//
// Created by victor on 6/3/17.
//

#include "Exception.hpp"
#include "Lib3D.hpp"

namespace indie
{
  const irr::u32 Lib3D::_RES_X = 1600;
  const irr::u32 Lib3D::_RES_Y = 900;

  Lib3D::Lib3D()
  {
    initDevice();
    initDriver();
    initSceneManager();
    initCollisionManager();
  }

  Lib3D::~Lib3D()
  {
    _device->drop();
  }

  void Lib3D::initDevice()
  {
    _device = irr::createDevice(
	    irr::video::EDT_OPENGL,
	    irr::core::dimension2d<irr::u32>(_RES_X, _RES_Y),
	    32,
	    false,
	    true,
	    false,
	    0);
    if (!_device) {
      throw exception::GraphicException(GRAPHIC_FAIL);
    }
    _device->setWindowCaption(L"Lemmings");
    _device->setResizable(false);
  }

  void Lib3D::initDriver()
  {
    if (!(_driver = _device->getVideoDriver())) {
      throw exception::GraphicException(GRAPHIC_FAIL);
    }
  }

  void Lib3D::initSceneManager()
  {
    if (!(_sceneManager = _device->getSceneManager())) {
      throw exception::GraphicException(GRAPHIC_FAIL);
    }
  }

  void Lib3D::initCollisionManager()
  {
    if (!(_collisionManager = _sceneManager->getSceneCollisionManager())) {
      throw exception::GraphicException(GRAPHIC_FAIL);
    }
  }

}