#ifndef			IPAGE_H
# define		IPAGE_H

# include		<vector>
# include		"standards.hpp"

namespace indie
{

class			IPage
{
  public:
    virtual		~IPage() {}
    virtual CoreEvent	loop() = 0;
    virtual void	initPage() = 0;
    virtual void	closePage() = 0;
};

} // End of namespace

#endif			/* !IPAGE_H */