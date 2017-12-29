#ifndef			STANDARDS_H
# define		STANDARDS_H

# include		<unordered_map>
# include		<list>
# include		"typedefs.hpp"

# define FILE_NOT_FOUND	("Could not find a ressource file. Please start the program in its directory")
# define GRAPHIC_FAIL	("Graphic Engine did not start properly.")

namespace indie
{

enum		Direction
{
  PAUSE = -1,
  LEFT = 0,
  UP,
  RIGHT,
  DOWN,
};

enum		ObjType
{
  START_GATE,
  AIR,
  PLATFORM,
  EARTH,
  WALL,
  FLOOR,
  LEM_BLOCK,
  LEM_KILL,
  END_GATE,
};

struct		Position
{
  float		x;
  float		y;
  float		z;
		Position();
		Position(const float x, const float y, const float z);
  Position&	operator+=(const Position&);
};

struct		Position2D
{
  float		x;
  float		y;
};

enum		EventContext
{
  MENU,
  GAME,
  SETTINGS,
  LEVELS,
  SCORES,
};

enum		CoreEvent
{
  NONE = 1950,		// Birth of Bjarne Stroustrup, C++ inventor

  GOTO_MENU,
  GOTO_PLAY,
  GOTO_LEVELS,
  GOTO_SETTINGS,
  GOTO_SCORES,

  QUIT_PRG,
  QUIT,
};

struct		MouseState
{
  Position	pos;
  bool		leftButtonDown;
  MouseState();
};

template <typename T>
using eventFunc		= void (T::*)(const CoreEvent&);
using ObjMap		= std::vector<std::pair<ObjType, Position>>;
using ScoreTab_t	= std::vector<int>;

}

#endif			/* !STANDARDS_H */