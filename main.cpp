#include "Life.hpp"

int					main(int ac, char **av)
{
	Life			*life;

	(void)ac;
	(void)av;
	life = new Life;

	life->genesis();
	return (0);
}
