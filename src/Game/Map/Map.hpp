//
// Created by victor on 5/30/17.
//

#ifndef INDIE_STUDIO_MAP_HPP
# define INDIE_STUDIO_MAP_HPP

# include <memory>
# include <vector>
# include "standards.hpp"
# include "Level1.hpp"
# include "Level2.hpp"
# include "Level3.hpp"
# include "Graphic.hpp"

namespace indie
{
  class Map
  {
    irr::scene::ISceneNode			*_parent;
    irr::scene::ISceneManager			*_smgr;
    Sptr<Graphic>				_graphic;
    std::vector<std::shared_ptr<ILevel> >	_levels;
    int						_levelNb;
    ObjMap					_objMap;

   public:
    Map(irr::scene::ISceneNode *parent, Sptr<Graphic> graphic);
    ~Map();

   public:
    void				initLevel(unsigned int level);
    std::pair<ObjType, Position>	&getObjType(Position const
						    &irrlichtPos);
    Position const			&getStartPosition() const;
    Position const			&getGatePosition() const;
    void				printMap() const;
    Sptr<Block>				&getBlockFromPos(Position const &pos);

   public:
    float				getHeightMap() const;
  };
}

#endif //INDIE_STUDIO_MAP_HPP
