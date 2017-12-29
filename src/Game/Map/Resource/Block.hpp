//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_BLOCK_HPP
# define INDIE_STUDIO_BLOCK_HPP

# include <vector>
# include "Particule.hpp"
# include "ColorShadeGen.hpp"

namespace indie
{
  class Block
  {
   private:
    std::vector<std::shared_ptr<Particule> >	_vecParticule;
    irr::core::vector3df			_pos;
    size_t					_unitParticule;
    ColorShade					_colorShade;
    bool					_destroyable;

   public:
    Block(irr::scene::ISceneNode *parent, irr::scene::ISceneManager *smgr,
	  const irr::core::vector3df &pos, const size_t unitParticule,
	  const irr::f32 particuleSize,
	  const ColorShade &color,
	  const bool &destroyable);

   public:
    irr::core::vector3df const			&getPosition() const;
    size_t 					getSizeUP() const;
    bool 					isDestroyable() const;
    void					remove();
  };
}

#endif //INDIE_STUDIO_BLOCK_HPP
