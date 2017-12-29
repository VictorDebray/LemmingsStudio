#include "Graphic.hpp"
#include "FileHandler.hpp"
#include "Exception.hpp"
#include <iostream>

namespace indie
{

/*
** Save a 2D image in memory
*/


void Graphic::blitImage(const std::string& path,
		        const Position& uppLeft)
{
  Img2D					newImg;
  irr::core::dimension2d<irr::s32>	imgSize;
  irr::video::SColor			color(255, 255, 255, 255);

  if (!FileHandler::fileExists(path)) {
    throw exception::FileException(FILE_NOT_FOUND);
  }
  newImg.img = _driver->getTexture(path.c_str());
  imgSize = newImg.img->getSize();
  newImg.color = color;

  newImg.uppLeftPos.X = uppLeft.x;
  newImg.uppLeftPos.Y = uppLeft.y;
  newImg.imgRect.UpperLeftCorner.X = 0;
  newImg.imgRect.UpperLeftCorner.Y = 0;
  newImg.imgRect.LowerRightCorner.X = imgSize.Width;
  newImg.imgRect.LowerRightCorner.Y = imgSize.Height;

  _img2DTab.push_back(newImg);
}

void Graphic::addImgToButton(irr::gui::IGUIButton *button,
			     const std::string& path)
{
  irr::video::IImage		*image;
  irr::video::ITexture		*texture;

  image = _driver->createImageFromFile(path.c_str());
  texture = _driver->addTexture("Texture", image);
  button->setUseAlphaChannel();
  button->setImage(texture);
}

/*
** Save a button in memory
*/
void Graphic::blitButton(const GUIBlitSpec& blitSpec)
{
  irr::core::rect<irr::s32>		rect;
  irr::core::position2d<irr::s32>	lowRightPos, uppLeftPos;
  irr::gui::IGUIButton			*button;

  uppLeftPos.X = blitSpec.uppLeftPos.x;
  uppLeftPos.Y = blitSpec.uppLeftPos.y;
  lowRightPos.X = blitSpec.uppLeftPos.x + 638;
  lowRightPos.Y = blitSpec.uppLeftPos.y + 80;
  rect.UpperLeftCorner = uppLeftPos;
  rect.LowerRightCorner = lowRightPos;
  button = _gui->addButton(rect,
			   nullptr,
			   blitSpec.eventID,
			   blitSpec.primaryText,
			   blitSpec.secondaryText);
  if (blitSpec.trigger) {
    addImgToButton(button, Graphic::_BUTTON_BG);
  }
}

void Graphic::blitCheckbox(const GUIBlitSpec& blitSpec)
{
  irr::core::rect<irr::s32>	rect;

  rect.UpperLeftCorner.X = blitSpec.uppLeftPos.x;
  rect.UpperLeftCorner.Y = blitSpec.uppLeftPos.y;
  rect.LowerRightCorner.X = blitSpec.uppLeftPos.x + 20;
  rect.LowerRightCorner.Y = blitSpec.uppLeftPos.y + 20;
  _gui->addCheckBox(blitSpec.trigger,
		    rect,
		    nullptr,
		    blitSpec.eventID,
		    blitSpec.primaryText);
}

void Graphic::blitText(const GUIBlitSpec& blitSpec)
{
  irr::core::vector3df	pos;

  pos.X = blitSpec.uppLeftPos.x;
  pos.Y = blitSpec.uppLeftPos.y;
  pos.Z = blitSpec.uppLeftPos.z;
  _sceneManager->addTextSceneNode(
	  _font,
	  blitSpec.primaryText,
	  irr::video::SColor(255, 255, 255, 255),
	  0,
	  pos);
}

Graphic::MeshBlitSpec::MeshBlitSpec() :
	path(""), texture(""),
	ID(-1), parentID(-1),
	frameLoop(1), animationSpeed(0),
	scale({1.0f, 1.0f, 1.0f}),
	position({0, 0, 0}),
	rotation({0, 0, 0})
{}

Graphic::GUIBlitSpec::GUIBlitSpec(const int eventID,
				  wchar_t *primaryText,
				  const Position& pos,
				  wchar_t *secondaryText,
				  bool trigger) :
	eventID(eventID),
	primaryText(primaryText),
	uppLeftPos(pos),
	secondaryText(secondaryText),
	trigger(trigger)
{}

/*
** Save a mesh in memory
*/
void Graphic::blitMesh(const MeshBlitSpec& blitSpec)
{
  irr::scene::ISceneNode		*node;
  irr::scene::IAnimatedMeshSceneNode	*animation = NULL;
  irr::scene::IAnimatedMesh		*model = NULL;
  irr::core::vector3df			position, rotation, scale;

  /* Remove eventual mesh (previous action animation) */
  if ((node = getNodeByID(blitSpec.ID))) {
    node->remove();
  }
  if (!FileHandler::fileExists(blitSpec.path)) {
    throw exception::FileException(FILE_NOT_FOUND);
  }
  model = _sceneManager->getMesh(blitSpec.path.c_str());
  if (!model) {
    return ;
  }
  position = posToVector3df(blitSpec.position);
  rotation = posToVector3df(blitSpec.rotation);
  scale = posToVector3df(blitSpec.scale);
  animation = _sceneManager->addAnimatedMeshSceneNode(
	  model,
	  getNodeByID(blitSpec.parentID),
	  blitSpec.ID,
	  position,
	  rotation,
	  scale);
  animation->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  if (blitSpec.texture != "") {
    animation->setMaterialTexture(0, _driver->getTexture(blitSpec.texture.c_str()));
  }
  animation->setFrameLoop(0, blitSpec.frameLoop);
  animation->setAnimationSpeed(blitSpec.animationSpeed);
}

}
