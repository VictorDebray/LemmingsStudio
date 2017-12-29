#include "AAction.hpp"

namespace indie
{

const AAction::ID&	AAction::getActionID() const
{
  return _id;
}

const std::string&	AAction::getMeshPath() const
{
  return _meshPath;
}

const std::string&	AAction::getTexturePath() const
{
  return _texturePath;
}

}