#ifndef			AACTION_H
# define		AACTION_H

# include		<iostream>
# include		"Node.hpp"

namespace indie
{

class			AAction : public Node
{
  public:
    enum		ID
    {
      WALK,
      STOP,
      BASH,
      EXPLODE,
      FLOAT,
      CLIMB,
      DIE,
    };

    			AAction() {}
    const ID&		getActionID() const;
    const std::string&	getMeshPath() const;
    const std::string&	getTexturePath() const;

  protected:
    ID			_id;
    std::string		_meshPath;
    std::string		_texturePath;
};

}

#endif			/* !AACTION_H */