#include "Graphic.hpp"

namespace indie
{

void Graphic::clearScreen()
{
  _gui->clear();
  _sceneManager->clear();
  _img2DTab.clear();
  setCamera({120, 50, -100});
}

void Graphic::quit()
{
  _device->closeDevice();
  _state = false;
}

void Graphic::eraseNode(const int id)
{
  if (getNodeByID(id))
    getNodeByID(id)->remove();
}

} // End of namespace