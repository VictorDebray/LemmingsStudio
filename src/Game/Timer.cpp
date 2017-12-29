//
// Created by Victor on 24/04/2017.
//

#include "Timer.hpp"

namespace indie
{
Timer::Timer() : _beg(t_clock::now())
{}

void Timer::reset()
{
  _beg = t_clock::now();
}

double Timer::elapsed() const
{
  return std::chrono::duration_cast<t_second>
	  (t_clock::now() - _beg).count();
}
}