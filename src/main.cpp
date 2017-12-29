#include "Core/Core.hpp"

int		main()
{
  try
    {
      indie::Core	core;
      core.loop();
    }
  catch (std::exception const &e)
    {
      std::cout << e.what() << std::endl;
    }
  return (0);
}
