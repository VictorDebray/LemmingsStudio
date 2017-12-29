#include "Node.hpp"

namespace indie
{

int Node::_idIdx = 1;

Node::Node() :
	_id(_idIdx++)
{
}

int Node::getID() const
{
  return _id;
}

}