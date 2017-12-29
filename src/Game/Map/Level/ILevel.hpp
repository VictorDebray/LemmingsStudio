//
// Created by victor on 5/30/17.
//

#ifndef INDIE_STUDIO_ILEVEL_HPP
# define INDIE_STUDIO_ILEVEL_HPP

# include "Block.hpp"
# include "Platform.hpp"
# include "standards.hpp"

namespace indie
{
  class ILevel
  {
   public:
    virtual ~ILevel() {}
    virtual ObjMap 		getObjMap() const = 0;
    virtual float		getUnitPerBlock() const = 0;
    virtual int			getWidthObjMap() const = 0;
    virtual int			getHeightObjMap() const = 0;
    virtual float		getHeight() const = 0;
    virtual Position const	&getStartPosition() const = 0;
    virtual Position const	&getGatePosition() const = 0;
    virtual void		printMap() const = 0;
    virtual Sptr<Block>		&getBlockFromPos(Position const &pos) = 0;
    virtual void		draw() = 0;
    virtual const std::string	getBg() const = 0;
  };
}

#endif //INDIE_STUDIO_ILEVEL_HPP
