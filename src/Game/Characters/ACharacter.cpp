//
// Created by Victor on 24/03/2017.
//

#include "ACharacter.hpp"

namespace indie
{

const float ACharacter::_MOVING_SPEED	= 0.10f;
const int ACharacter::_ANIMATION_SPEED	= 24;

ACharacter::ACharacter(Sptr<Graphic> graphic) :
	_graphic(graphic),
	_alive(true),
	_win(false),
	_dir(Direction::RIGHT),
	_rot({0, 0, 0})
{
  _mapFuncMoves = {
	  {Direction::PAUSE, &ACharacter::_movePause},
	  {Direction::UP, &ACharacter::_moveUp},
	  {Direction::DOWN, &ACharacter::_moveDown},
	  {Direction::LEFT, &ACharacter::_moveLeft},
	  {Direction::RIGHT, &ACharacter::_moveRight}
  };
}

void ACharacter::move(indie::Direction dir)
{
  CALL_MEMBER_FN(*this, _mapFuncMoves[dir])();
}

Position const &ACharacter::getPosition() const
{
  return _pos;
}

void ACharacter::setPosition(const indie::Position& pos)
{
  _pos = pos;
}

Direction ACharacter::getDirection() const
{
  return _dir;
}

void ACharacter::setDirection(const indie::Direction& dir)
{
  _dir = dir;
}

Position ACharacter::getRotation() const
{
  return _rot;
}

void ACharacter::setRotation(const indie::Position& rot)
{
  _rot = rot;
}

bool ACharacter::isAlive() const
{
  return _alive;
}

void ACharacter::setAlive(bool alive)
{
  _alive = alive;
}

bool ACharacter::getWin() const
{
  return _win;
}

}