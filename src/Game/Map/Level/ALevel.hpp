//
// Created by victor on 5/31/17.
//

#ifndef INDIE_STUDIO_ALEVEL_HPP
# define INDIE_STUDIO_ALEVEL_HPP

# include "ILevel.hpp"
# include "Platform.hpp"

namespace indie
{
  class ALevel : public ILevel
  {
    using vecSPlatforms = std::vector<Sptr<indie::Platform> >;

   private:
    std::string					_name;

   protected:
    static const int 				_IRR_UNIT_PER_BLOCK;
    static const float				_Z_POS;
    irr::scene::ISceneNode			*_parent;
    irr::scene::ISceneManager			*_smgr;
    irr::f32 					_width;
    irr::f32 					_height;
    irr::f32 					_depth;
    unsigned int				_widthMap;
    unsigned int				_heightMap;
    vecSPlatforms				_vecPlatforms;
    ObjMap 					_objMap;
    Position					_startPos;
    Position					_gatePos;

   public:
    ALevel() {}
    ALevel(irr::scene::ISceneNode *parent,
	   irr::scene::ISceneManager *smgr,
	   std::string const &name, irr::f32 width = 240, irr::f32 height = 100,
	   irr::f32 depth = 16);//copy billBoard wanted
    virtual ~ALevel() {}

   public:
    virtual void		resetLevel() = 0;

    //DRAWING
   public:
    void 		drawBoard();
    virtual void	draw() = 0;

   public:
    void		setName(std::string const &name);
    std::string const	&getName() const;
    ObjMap 		getObjMap() const; //copy wanted
    float		getUnitPerBlock() const;
    int			getWidthObjMap() const;
    int			getHeightObjMap() const;
    float		getHeight() const;
    Position const	&getStartPosition() const;
    Position const	&getGatePosition() const;
    void		printMap() const;
    Sptr<Block>		&getBlockFromPos(Position const &pos);
  };
}

#endif //INDIE_STUDIO_ALEVEL_HPP
