#ifndef		NODE_H
# define	NODE_H

namespace indie
{

class		Node
{
  protected:
    int		_id;
    static int	_idIdx;
  public:
		Node();
    int		getID() const;
};

}

#endif		/* !NODE_H */