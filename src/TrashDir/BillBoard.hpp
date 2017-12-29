//
// Created by victor on 5/29/17.
//

#ifndef INDIE_STUDIO_BILLBOARD_HPP
# define INDIE_STUDIO_BILLBOARD_HPP

# include <memory>
# include "irrlicht.hpp"

# define TRANSPARENCY_BILLBOARD		(0)

namespace indie
{
  class BillBoard : public irr::scene::ISceneNode
  {
    // array of vertices of flor
    // flor will have 2 triangles = 4 vertices
    irr::video::S3DVertex FloorVertex[4];
    irr::video::S3DVertex LeftWallVertex[4];
    irr::video::S3DVertex RightWallVertex[4];
    irr::video::S3DVertex BackWallVertex[4];

    // array of indices of flor
    // each triangle have 3 indices (corners)
    irr::u16 FloorIndex[6];
    irr::u16 LeftWallIndex[6];
    irr::u16 RightWallIndex[6];
    irr::u16 BackWallIndex[6];

    // bounding box of room
    irr::core::aabbox3d<irr::f32> BoundingBox;

    // node have just flor jet so we use only one material
    // if we add wall we add materials for them
    irr::video::SMaterial Material[1];

   public:

    BillBoard(irr::scene::ISceneNode *parent,
	      irr::scene::ISceneManager *smgr,
	      irr::s32 id, irr::f32 width, irr::f32 height, irr::f32 depth);

    // folowing functions must have been defined in order of our node to work

    // frame
    virtual void OnRegisterSceneNode();

    // render room
    virtual void render();

    // returns bounding box of node
    virtual const irr::core::aabbox3d<irr::f32>& getBoundingBox() const;

    // return number of materials room node have ...currently 1
    virtual irr::u32 getMaterialCount();

    // returns material
    virtual irr::video::SMaterial& getMaterial(irr::u32 i);

    // folowing functions are specific for our node and lets us manipulate it
    // you can add your own functions

    // change room dimensions
    virtual void setWidth(irr::f32 newwidth);

    // change room dimensions
    virtual void setHeight(irr::f32 newheight);

    virtual void setDepth(irr::f32 newDepth);

    // return current dimensions of room, currently only 2d since room contain only flor
    virtual irr::core::vector3df getDimension();
  };
}

#endif //INDIE_STUDIO_BILLBOARD_HPP
