//
// Created by victor on 6/1/17.
//

#include <random>
#include <iostream>
#include <chrono>
#include <functional>
#include "ColorShadeGen.hpp"

namespace indie
{
  ColorShadeGen::ColorShadeGen()
  {
    _colorTab = {
	    {GREY, std::make_pair(
		    irr::video::SColor(255, 105, 105, 105),
		    irr::video::SColor(255, 150, 150, 150))},
	    {BROWN, std::make_pair(
		    irr::video::SColor(255, 139, 69, 19),
		    irr::video::SColor(255, 205, 133, 63))},
	    {GREEN , std::make_pair(
		    irr::video::SColor(255, 0, 100, 0),
		    irr::video::SColor(255, 34, 205, 34))},
	    {RED, std::make_pair(
		    irr::video::SColor(255, 139, 0, 0),
		    irr::video::SColor(255, 205, 20, 30))},
    };
  }

  irr::video::SColor ColorShadeGen::genRandomColor(
	  const ColorShade color)
  {
    if (color >= GREY && color <= RED)
      {
	const irr::video::SColor min = _colorTab[color].first;
	const irr::video::SColor max = _colorTab[color].second;
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto dice_randR = std::bind(std::uniform_int_distribution<irr::u32>(
		min.getRed(), max.getRed()), std::mt19937(seed));
	auto dice_randG = std::bind(std::uniform_int_distribution<irr::u32>(
		min.getGreen(), max.getGreen()), std::mt19937(seed));
	auto dice_randB = std::bind(std::uniform_int_distribution<irr::u32>(
		min.getBlue(), max.getBlue()), std::mt19937(seed));
	irr::u32 red = dice_randR();
	irr::u32 green = dice_randG();
	irr::u32 blue = dice_randB();
	return irr::video::SColor(255, red, green, blue);
      }
    return irr::video::SColor(255, 0, 0, 0);
  }
}
