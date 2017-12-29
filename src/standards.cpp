#include "standards.hpp"

namespace indie
{

Position& Position::operator+=(const Position& other)
{
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

Position::Position(const float x = 0, const float y = 0, const float z = 0)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Position::Position()
{
  x = y = z = 0;
}

MouseState::MouseState() :
	pos({0,0,0}),
	leftButtonDown(false)
{}

}