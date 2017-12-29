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

Position::Position(const float x, const float y, const float z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

MouseState::MouseState() :
	pos({0,0,0}),
	leftButtonDown(false)
{}

}