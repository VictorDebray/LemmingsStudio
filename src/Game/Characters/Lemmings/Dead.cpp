//
// Created by victor on 5/24/17.
//

#include "Lemming.hpp"

namespace indie
{

bool 		Lemming::_dead(Sptr<Map>)
{
  setAction(AAction::DIE);
  _alive = false;
  return true;
}

}