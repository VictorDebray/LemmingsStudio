#ifndef			ACTION_MANAGER_H
# define		ACTION_MANAGER_H

# include		<vector>
# include		"AAction.hpp"
# include		"Graphic.hpp"

namespace indie
{

class			ActionManager
{
  private:
    Sptr<Graphic>		_graphic;
    std::vector<Sptr<AAction>>	_actionBar;

  public:
			ActionManager(Sptr<Graphic>);
    void		blitActionBar();
    Sptr<AAction>	getActionByID(const int) const;
};

}

#endif			/* !ACTION_MANAGER_H */