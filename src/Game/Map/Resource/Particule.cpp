//
// Created by victor on 5/31/17.
//

#include <iostream>
#include "Particule.hpp"

namespace indie
{
  Particule::Particule(irr::scene::ISceneNode *parent,
			      irr::scene::ISceneManager *smgr,
			      const irr::core::vector3df &pos,
			      const irr::f32 size,
			      const irr::video::SColor &col,
			      const bool &destroyable)
	  : _cube(smgr->addCubeSceneNode(size, parent, -1, pos)), _color(col),
	    _destroyable(destroyable)
  {
    setColor(_color);
  }

  bool Particule::isVisible() const
  {
    return _cube->isVisible();
  }

  void Particule::setVisible(bool visible)
  {
    _cube->setVisible(visible);
  }

  void Particule::setColor(irr::video::SColor &col)
  {
    _cube->getMaterial(0).EmissiveColor = col;
  }

  irr::video::SColor const &Particule::getColor() const
  {
    return _color;
  }

  void Particule::setPosition(const irr::core::vector3df &pos)
  {
    _cube->setPosition(pos);
  }

  irr::core::vector3df const &Particule::getPosition() const
  {
    return _cube->getPosition();
  }

  void Particule::setScale(const irr::core::vector3df &scale)
  {
    _cube->setScale(scale);
  }

  irr::core::vector3df const &Particule::getScale() const
  {
    return _cube->getScale();
  }

  void Particule::setRotation(const irr::core::vector3df &rotation)
  {
    _cube->setRotation(rotation);
  }

  irr::core::vector3df const &Particule::getRotation() const
  {
    return _cube->getRotation();
  }

  bool Particule::isDestroyable()
  {
    return _destroyable;
  }

  void Particule::remove()
  {
    if (isDestroyable())
      _cube->remove();
  }
}