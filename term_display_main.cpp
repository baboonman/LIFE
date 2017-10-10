#include "TermDisplay.hpp"

int			main()
{
	TermDisplay		*term;

	term = new TermDisplay(20, 40);
	term->display();
	delete(term);
	return (0);
}
