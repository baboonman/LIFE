# include "TermDisplay.hpp"

TermDisplay::TermDisplay(int height, int width)
{
	int			start_h, start_w;

	std::cout << "Init NCurses" << std::endl;
	initscr();
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	refresh();

	start_h = (LINES - height) / 2;
	start_w = (COLS - width) / 2;

	std::cerr << "LINES: " << LINES << " - COLS: " << COLS << std::endl;
	std::cerr << "height: " << height << " - width: " << width << std::endl;
	std::cerr << "start_h: " << start_h << " - start_w: " << start_w << std::endl;
	this->_win = newwin(height, width, start_h, start_w);
	wborder(this->_win, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	wrefresh(this->_win);

}

TermDisplay::~TermDisplay()
{
	delwin(this->_win);
	endwin();
	std::cout << "Close NCurses" << std::endl;
}

void			TermDisplay::display()
{
	int			row, col;

	getmaxyx(this->_win, row, col);
	mvwprintw(this->_win, row / 2, (col - 11) - 2, "Hello World");
	wrefresh(this->_win);
	getch();
}
