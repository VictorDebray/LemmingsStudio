//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_PARTICULE_HPP
# define INDIE_STUDIO_PARTICULE_HPP

# include "irrlicht.hpp"
# include <memory>
#include <typedefs.hpp>
# include "ColorShade.h"

namespace indie
{
  class Particule
  {
   private:
    irr::scene::ISceneNode *			_cube;
    irr::video::SColor				_color;
    bool 					_destroyable;

   public:
    Particule(irr::scene::ISceneNode *parent,
	      irr::scene::ISceneManager *smgr,
	      const irr::core::vector3df &pos, const irr::f32 size,
	      const irr::video::SColor &col, const bool &destroyable);
    ~Particule() {}

   public:
    bool			isVisible() const;
    void			setVisible(bool visible);
    void			setColor(irr::video::SColor &col);
    irr::video::SColor const	&getColor() const;
    void			setPosition(const irr::core::vector3df &pos);
    irr::core::vector3df const	&getPosition() const;
    void			setScale(const irr::core::vector3df &scale);
    irr::core::vector3df const	&getScale() const;
    void			setRotation(const irr::core::vector3df &rotation);
    irr::core::vector3df const	&getRotation() const;
    void			remove();
    bool			isDestroyable();
  };
}

#endif //INDIE_STUDIO_PARTICULE_HPP
