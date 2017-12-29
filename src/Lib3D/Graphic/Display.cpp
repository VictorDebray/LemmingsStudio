#include "Graphic.hpp"

namespace indie
{

void Graphic::display()
{
  _state = _device->run();
  if (_driver->beginScene(true, true, irr::video::SColor(255, 255, 255, 255))) {
    displayImg2D();
    _sceneManager->drawAll();
    _gui->drawAll();
    _driver->endScene();
  }
}

void Graphic::displayImg2D()
{
  for (auto& image : _img2DTab) {
    _driver->draw2DImage(image.img,
			 image.uppLeftPos,
			 image.imgRect,
			 0,
			 image.color,
			 true);
  }
}


} // End of namespace