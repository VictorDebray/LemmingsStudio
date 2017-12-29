//
// Created by victor on 6/1/17.
//

#ifndef MAP_COLORSHADEGEN_HPP
# define MAP_COLORSHADEGEN_HPP

# include <unordered_map>
# include "irrlicht.hpp"
# include "ColorShade.h"

namespace indie
{
  class ColorShadeGen
  {
   public:
    typedef std::unordered_map<ColorShade,
	    std::pair<irr::video::SColor, irr::video::SColor> > t_color_tab;
    t_color_tab			_colorTab;
   public:
    ColorShadeGen();
    ~ColorShadeGen() {}

   public:
    irr::video::SColor genRandomColor(const ColorShade color);
  };
}

#endif //MAP_COLORSHADEGEN_HPP
