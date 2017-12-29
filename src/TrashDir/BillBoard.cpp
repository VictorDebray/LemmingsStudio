//
// Created by victor on 5/29/17.
//

#include "BillBoard.hpp"

namespace indie
{
  BillBoard::BillBoard(irr::scene::ISceneNode *parent,
		       irr::scene::ISceneManager *smgr, irr::s32 id,
		       irr::f32 width, irr::f32 height, irr::f32 depth)
	  : irr::scene::ISceneNode(parent, smgr, id)
  {
// set up vertices of flor as square
// we start with lower left vertex which will also be origin of node

// 1---2
// | / |
// 0---3

    /* FLOOR */
    FloorVertex[0].Pos = irr::core::vector3df(0, 0, 0);
    FloorVertex[1].Pos = irr::core::vector3df(0, 0, depth);
    FloorVertex[2].Pos = irr::core::vector3df(width, 0, depth);
    FloorVertex[3].Pos = irr::core::vector3df(width, 0, 0);

// set up their normals
    FloorVertex[0].Normal = irr::core::vector3df(0, 1, 0);
    FloorVertex[1].Normal = irr::core::vector3df(0, 1, 0);
    FloorVertex[2].Normal = irr::core::vector3df(0, 1, 0);
    FloorVertex[3].Normal = irr::core::vector3df(0, 1, 0);

// set up color
    FloorVertex[0].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    FloorVertex[1].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    FloorVertex[2].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    FloorVertex[3].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);

// set up texture UV coordinates,
// note that texture have origin in upper left corner not lower left as our flor have
    FloorVertex[0].TCoords = irr::core::vector2df(0, 1);
    FloorVertex[1].TCoords = irr::core::vector2df(0, 0);
    FloorVertex[2].TCoords = irr::core::vector2df(1, 0);
    FloorVertex[3].TCoords = irr::core::vector2df(1, 1);

// set up indices, in counter clockvise order
// numbers on the right are number of vertices in vertex array

// upper left triangle

// 1---2
// 0
// | /

    FloorIndex[0] = 0;
    FloorIndex[1] = 1;
    FloorIndex[2] = 2;

// lower right triangle

//     2
//   / |
// 0---3

    FloorIndex[3] = 0;
    FloorIndex[4] = 2;
    FloorIndex[5] = 3;

    /* LEFT WALL */
    // 2-31---2
    // |/|| / |
    // 1-00---3
    LeftWallVertex[0].Pos = FloorVertex[0].Pos;
    LeftWallVertex[1].Pos = irr::core::vector3df(0, height, 0);
    LeftWallVertex[2].Pos = irr::core::vector3df(0, height, depth);
    LeftWallVertex[3].Pos = FloorVertex[1].Pos;

// set up their normals
    LeftWallVertex[0].Normal = irr::core::vector3df(0, 1, 0);
    LeftWallVertex[1].Normal = irr::core::vector3df(0, 1, 0);
    LeftWallVertex[2].Normal = irr::core::vector3df(0, 1, 0);
    LeftWallVertex[3].Normal = irr::core::vector3df(0, 1, 0);

// set up color
    LeftWallVertex[0].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    LeftWallVertex[1].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    LeftWallVertex[2].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    LeftWallVertex[3].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);

// set up texture UV coordinates,
// note that texture have origin in upper left corner not lower left as our flor have
    LeftWallVertex[0].TCoords = irr::core::vector2df(0, 1);
    LeftWallVertex[1].TCoords = irr::core::vector2df(0, 0);
    LeftWallVertex[2].TCoords = irr::core::vector2df(1, 0);
    LeftWallVertex[3].TCoords = irr::core::vector2df(1, 1);

    LeftWallIndex[0] = 0;
    LeftWallIndex[1] = 1;
    LeftWallIndex[2] = 2;

// lower right triangle

//     2
//   / |
// 0---3

    LeftWallIndex[3] = 0;
    LeftWallIndex[4] = 2;
    LeftWallIndex[5] = 3;


    /* RIGHT WALL */
    // 1---20-1
    // | / ||\|
    // 0---33-2
    RightWallVertex[0].Pos = FloorVertex[2].Pos;
    RightWallVertex[1].Pos = irr::core::vector3df(width, height, depth);
    RightWallVertex[2].Pos = irr::core::vector3df(width, height, 0);
    RightWallVertex[3].Pos = FloorVertex[3].Pos;

// set up their normals
    RightWallVertex[0].Normal = irr::core::vector3df(0, 1, 0);
    RightWallVertex[1].Normal = irr::core::vector3df(0, 1, 0);
    RightWallVertex[2].Normal = irr::core::vector3df(0, 1, 0);
    RightWallVertex[3].Normal = irr::core::vector3df(0, 1, 0);

// set up color
    RightWallVertex[0].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    RightWallVertex[1].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    RightWallVertex[2].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);
    RightWallVertex[3].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 0, 0, 0);

// set up texture UV coordinates,
// note that texture have origin in upper left corner not lower left as our flor have
    RightWallVertex[0].TCoords = irr::core::vector2df(0, 1);
    RightWallVertex[1].TCoords = irr::core::vector2df(0, 0);
    RightWallVertex[2].TCoords = irr::core::vector2df(1, 0);
    RightWallVertex[3].TCoords = irr::core::vector2df(1, 1);

    RightWallIndex[0] = 0;
    RightWallIndex[1] = 1;
    RightWallIndex[2] = 2;

// lower right triangle

//     2
//   / |
// 0---3

    RightWallIndex[3] = 0;
    RightWallIndex[4] = 2;
    RightWallIndex[5] = 3;


    /* BACK WALL */
    // 1---2
    // 0---3
    // 1---2
    // | / |
    // 0---3
    BackWallVertex[0].Pos = FloorVertex[1].Pos;
    BackWallVertex[1].Pos = irr::core::vector3df(0, height, depth);
    BackWallVertex[2].Pos = irr::core::vector3df(width, height, depth);
    BackWallVertex[3].Pos = FloorVertex[2].Pos;

// set up their normals
    BackWallVertex[0].Normal = irr::core::vector3df(0, 1, 0);
    BackWallVertex[1].Normal = irr::core::vector3df(0, 1, 0);
    BackWallVertex[2].Normal = irr::core::vector3df(0, 1, 0);
    BackWallVertex[3].Normal = irr::core::vector3df(0, 1, 0);

// set up color
    BackWallVertex[0].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 125, 235, 34);
    BackWallVertex[1].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 125, 235, 34);
    BackWallVertex[2].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 125, 235, 34);
    BackWallVertex[3].Color = irr::video::SColor(TRANSPARENCY_BILLBOARD, 125, 235, 34);

// set up texture UV coordinates,
// note that texture have origin in upper left corner not lower left as our flor have
    BackWallVertex[0].TCoords = irr::core::vector2df(0, 1);
    BackWallVertex[1].TCoords = irr::core::vector2df(0, 0);
    BackWallVertex[2].TCoords = irr::core::vector2df(1, 0);
    BackWallVertex[3].TCoords = irr::core::vector2df(1, 1);

    BackWallIndex[0] = 0;
    BackWallIndex[1] = 1;
    BackWallIndex[2] = 2;

// lower right triangle

//     2
//   / |
// 0---3

    BackWallIndex[3] = 0;
    BackWallIndex[4] = 2;
    BackWallIndex[5] = 3;


// calculate bounding box
    BoundingBox.reset(FloorVertex[0].Pos);
    BoundingBox.reset(LeftWallVertex[0].Pos);
    BoundingBox.reset(RightWallVertex[0].Pos);
    BoundingBox.reset(BackWallVertex[0].Pos);
    for (irr::s32 i = 1; i < 4; ++i)
      {
	BoundingBox.addInternalPoint(FloorVertex[i].Pos);
	BoundingBox.addInternalPoint(LeftWallVertex[i].Pos);
	BoundingBox.addInternalPoint(RightWallVertex[i].Pos);
	BoundingBox.addInternalPoint(BackWallVertex[i].Pos);
      }

// setup material
    Material[0].Wireframe = false;
    Material[0].Lighting = false;
  }

  void BillBoard::OnRegisterSceneNode()
  {
    if (IsVisible)
      SceneManager->registerNodeForRendering(this);

    irr::scene::ISceneNode::OnRegisterSceneNode();
  }

  void BillBoard::render()
  {
    irr::video::IVideoDriver *driver = SceneManager->getVideoDriver();
    if (!driver)
      return;

    Material->MaterialType = irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL;
    driver->setMaterial(Material[0]);
    driver->setTransform(irr::video::ETS_WORLD, AbsoluteTransformation);

    // draw flor vertices
    // second argument is number of vertices
    // last argument is number of triangles
    driver->drawIndexedTriangleList(&FloorVertex[0], 4, &FloorIndex[0], 2);
    driver->drawIndexedTriangleList(&LeftWallVertex[0], 4, &LeftWallIndex[0],
				    2);
    driver->drawIndexedTriangleList(&RightWallVertex[0], 4, &RightWallIndex[0],
				    2);
    driver->drawIndexedTriangleList(&BackWallVertex[0], 4, &BackWallIndex[0],
				    2);

  }

  const irr::core::aabbox3d<irr::f32> &BillBoard::getBoundingBox() const
  {
    return BoundingBox;
  }

  irr::u32 BillBoard::getMaterialCount()
  {
    return 1;
  }

// returns material
  irr::video::SMaterial &BillBoard::getMaterial(irr::u32 i)
  {
    return Material[i];
  }

// folowing functions are specific for our node and lets us manipulate it
// you can add your own functions

// change room dimensions
  void BillBoard::setWidth(irr::f32 newwidth)
  {
    FloorVertex[2].Pos.X = newwidth;
    FloorVertex[3].Pos.X = newwidth;
    RightWallVertex[0].Pos.X = FloorVertex[2].Pos.X;
    RightWallVertex[1].Pos.X = newwidth;
    RightWallVertex[2].Pos.X = newwidth;
    RightWallVertex[3].Pos.X = FloorVertex[3].Pos.X;
    BackWallVertex[2].Pos.X = FloorVertex[2].Pos.X;
    BackWallVertex[3].Pos.X = FloorVertex[2].Pos.X;



    // bounding box have to be recalculated
    BoundingBox.reset(FloorVertex[0].Pos);
    BoundingBox.reset(RightWallVertex[0].Pos);
    BoundingBox.reset(BackWallVertex[0].Pos);
    for (irr::s32 i = 1; i < 4; ++i)
      {
	BoundingBox.addInternalPoint(FloorVertex[i].Pos);
	BoundingBox.addInternalPoint(RightWallVertex[i].Pos);
	BoundingBox.addInternalPoint(BackWallVertex[i].Pos);
      }
  }

// change room dimensions
  void BillBoard::setDepth(irr::f32 newdepth)
  {
    FloorVertex[1].Pos.Z = newdepth;
    FloorVertex[2].Pos.Z = newdepth;
    LeftWallVertex[2].Pos.Z = newdepth;
    BackWallVertex[0].Pos.Z = FloorVertex[1].Pos.Z;
    BackWallVertex[1].Pos.Z = newdepth;
    BackWallVertex[2].Pos.Z = newdepth;
    BackWallVertex[3].Pos.Z = FloorVertex[2].Pos.Z;


    // bounding box have to be recalculated
    BoundingBox.reset(FloorVertex[0].Pos);
    BoundingBox.reset(LeftWallVertex[0].Pos);
    BoundingBox.reset(BackWallVertex[0].Pos);
    for (irr::s32 i = 1; i < 4; ++i)
      {
	BoundingBox.addInternalPoint(FloorVertex[i].Pos);
	BoundingBox.addInternalPoint(LeftWallVertex[i].Pos);
	BoundingBox.addInternalPoint(BackWallVertex[i].Pos);
      }
  }

  void BillBoard::setHeight(irr::f32 newheight)
  {
    LeftWallVertex[1].Pos.Y = newheight;
    LeftWallVertex[2].Pos.Y = newheight;
    BackWallVertex[0].Pos.Y = FloorVertex[1].Pos.Y;
    BackWallVertex[1].Pos.Y = newheight;
    BackWallVertex[2].Pos.Y = newheight;

    // bounding box have to be recalculated
    BoundingBox.reset(LeftWallVertex[0].Pos);
    BoundingBox.reset(BackWallVertex[0].Pos);
    for (irr::s32 i = 1; i < 4; ++i)
      {
	BoundingBox.addInternalPoint(LeftWallVertex[i].Pos);
	BoundingBox.addInternalPoint(BackWallVertex[i].Pos);
      }
  }

// return current dimensions of room, currently only 2d since room contain only flor
  irr::core::vector3df BillBoard::getDimension()
  {
    irr::core::vector3df roomdim;
    roomdim.X = FloorVertex[2].Pos.X - FloorVertex[0].Pos.X;
    roomdim.Y = LeftWallVertex[1].Pos.Y - FloorVertex[0].Pos.Y;
    roomdim.Z = LeftWallVertex[3].Pos.Z - FloorVertex[0].Pos.Z;

    return roomdim;
  }
}