#ifndef TERMDISPLAY_HPP
# define TERMDISPLAY_HPP

# include <iostream>
# include <ncurses.h>

class					TermDisplay
{
	public:
						TermDisplay(int height, int width);
						~TermDisplay();

	void				display();

	private:

	WINDOW*				_win;
};


#endif
