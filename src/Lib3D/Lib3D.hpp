//
// Created by victor on 6/3/17.
//

#ifndef INDIE_STUDIO_LIB3D_HPP
# define INDIE_STUDIO_LIB3D_HPP

# include		"irrlicht.hpp"
# include		"standards.hpp"
# include		"AEventReceiver.hpp"

namespace indie
{
  class Lib3D
  {
   private:
    static const irr::u32	_RES_X;
    static const irr::u32	_RES_Y;

    void			initDevice();
    void			initDriver();
    void			initSceneManager();
    void			initCollisionManager();
   protected:
    irr::IrrlichtDevice			*_device;
    irr::video::IVideoDriver		*_driver;
    irr::scene::ISceneManager		*_sceneManager;
    irr::scene::ISceneCollisionManager	*_collisionManager;

   public:
    Lib3D();
    virtual ~Lib3D();
  };
}

#endif //INDIE_STUDIO_LIB3D_HPP
