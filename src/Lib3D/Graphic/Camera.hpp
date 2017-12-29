#ifndef				CAMERA_H
# define			CAMERA_H

# include			"irrlicht.hpp"

namespace indie
{

class				Camera : public Node
{
  private:
    irr::core::vector3df		_position;
    irr::core::vector3df		_target;
    irr::scene::ISceneManager		*_sceneManager;
    irr::scene::ICameraSceneNode	*_camera;

  public:
				Camera(const irr::core::vector3df&,
				       irr::scene::ISceneManager *);
    void			setPosition(const irr::core::vector3df&);
    Position			getPosition() const;
};

}

#endif				/* !CAMERA_H */