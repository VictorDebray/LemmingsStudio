//
// Created by Victor on 24/04/2017.
//

#ifndef CPP_INDIER_TIMER_HPP
#define CPP_INDIER_TIMER_HPP

#include <iostream>
#include <chrono>

namespace indie
{
  class Timer
  {
   private:
    typedef std::chrono::high_resolution_clock t_clock;
    typedef std::chrono::duration<double, std::ratio<1> > t_second;
    std::chrono::time_point<t_clock> _beg;

   public:
    Timer();

   public:
    void reset();
    double elapsed() const;
  };
}

#endif //CPP_INDIER_TIMER_HPP
