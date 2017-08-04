#include "Life.hpp"

Life::Life()
{
	this->_width = 40;
	this->_height = 20;
	this->_world_size = this->_width * this->_height;
	this->_world.resize(this->_world_size, false);
	this->_initWorld(200);
	this->_display_world(this->_world);
}

Life::~Life()
{
}

void					Life::genesis()
{
	std::vector<bool>	*gridA = &this->_world;
	std::vector<bool>	*gridB = &this->_world;
	std::vector<bool>	*tmp;
	int					generation = 0;
	int					max_generation = 2;

	do
	{
		for (int i = 0 ; i < this->_world_size ; i++)
		{
			(*gridB)[i] = this->_evalCell(*gridA, i);
		}
		this->_display_world(*gridB);
		tmp = gridA;
		gridA = gridB;
		gridB = tmp;
		generation++;
	} while (generation < max_generation);
}

bool					Life::_evalCell(std::vector<bool> &grid, int pos)
{
	int					nb_neighbours = 0;
	int					nh, nw;
	int					h = pos / this->_width;
	int					w = pos % this->_width;
	bool				is_alive = grid[pos];

	for (int a = -1 ; a < 2 ; a++)
	{
		for (int b = -1 ; b < 2 ; b++)
		{
			if (a != 0 || b != 0)
			{
				nh = h + a;
				nw = w + b;
				if (nh >= this->_height)
					nh = 0;
				else if (nh < 0)
					nh = this->_height - 1;
				if (nw >= this->_width)
					nw = 0;
				else if (nw < 0)
					nw = this->_width - 1;
				if (grid[this->_getIndex(nw, nh)])
					nb_neighbours++;
			}
		}
	}

	if (is_alive)
	{
		if (nb_neighbours >= 4 || nb_neighbours <= 1)
			return (false);
	}
	else
	{
		if (nb_neighbours == 3)
			return (true);
	}
	return (is_alive);
}

void					Life::_initWorld(int nb_cells)
{
	int					pos;
	srand(time(NULL));

	while (nb_cells > 0)
	{
		pos = rand() % this->_world_size;
		if (!this->_world[pos]) {
			this->_world[pos] = true;
			nb_cells--;
		}
	}
}

int						Life::_getIndex(int width_pos, int height_pos)
{
	return (height_pos * this->_width + width_pos);
}

void					Life::_display_world(std::vector<bool> &grid)
{
	int 				ind;

//	sleep(10);
//	std::cout << "\033[2J";

	for (int i = 0 ; i < this->_width + 2 ; i++)
	{
		if (i == 0 || i == this->_width + 1)
			std::cout << '+';
		else
			std::cout << '-';
	}
	
	std::cout << std::endl;

	for (int i = 0 ; i < this->_height ; i++)
	{
		for (int j = 0 ; j < this->_width + 2 ; j++)
		{
			if (j == 0 || j == this->_width + 1)
				std::cout << "|";
			else
			{
				ind = this->_getIndex(j - 1, i);
				std::cout << ((grid[ind]) ? '#' : '.');
			}
		}
		std::cout << std::endl;
	}

	for (int i = 0 ; i < this->_width + 2 ; i++)
	{
		if (i == 0 || i == this->_width + 1)
			std::cout << '+';
		else
			std::cout << '-';
	}
	std::cout << std::endl;
}
