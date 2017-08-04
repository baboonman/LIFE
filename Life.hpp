#ifndef LIFE_HPP
# define LIFE_HPP

# include <cstdlib>
# include <ctime>
# include <vector>
# include <iostream>
# include <unistd.h>

class							Life
{
	public:
								Life();
								~Life();
		void					genesis();

	private:
		void					_initWorld(int nb_cells);
		void					_display_world(std::vector<bool> &grid);
		int						_getIndex(int width_pos, int height_pos);
		bool					_evalCell(std::vector<bool> &grid, int pos);
	
	private:
		std::vector<bool>		_world;
		int						_world_size;
		int						_width;
		int						_height;
};


#endif
