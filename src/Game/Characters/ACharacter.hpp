/*
** arcade_nibbler for a in /home/EPITECH/tek2
**
** Made by Victor
** Login   <victor.debray@epitech.eu>
**
** Started on  27/03/2017
// Last update Wed Apr  5 03:00:06 2017 Victor
*/

#ifndef ACHARACTER_H_
# define ACHARACTER_H_

# include <iostream>
# include <unordered_map>
# include <list>
# include <memory>
# include "Graphic.hpp"
# include "Node.hpp"

namespace indie
{
  class ACharacter : public Node
  {
   public:
     static const int		_ANIMATION_SPEED;
   protected:

     static const float		_MOVING_SPEED;

     using t_move_func_ptr= bool (ACharacter::*)();
     using t_map_move_func = std::unordered_map<Direction, t_move_func_ptr>;

     Sptr<Graphic>		_graphic;
     bool			_alive;
     bool 			_win;
     Direction			_dir;
     Position			_pos;
     Position			_rot;
     t_map_move_func		_mapFuncMoves;

     virtual bool		_moveUp() = 0;
     virtual bool		_moveDown() = 0;
     virtual bool		_moveLeft() = 0;
     virtual bool		_moveRight() = 0;
     virtual bool		_movePause() = 0;

   public:
     ACharacter(Sptr<Graphic>);
     virtual ~ACharacter() {}

    virtual Position const 	&getPosition() const;
    virtual void		move(indie::Direction dir);
    virtual void		setPosition(const Position&);
    virtual Direction 		getDirection() const;
    virtual void		setDirection(const indie::Direction&);
    virtual bool 		getWin() const;
    virtual bool 		isAlive() const;
    virtual void 		setAlive(bool alive);
    virtual Position	 	getRotation() const;
    virtual void		setRotation(const Position&);

  };
}
#endif /* !ACHARACTER_H_ */
