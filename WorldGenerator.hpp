#ifndef WORLDGENERATOR_HPP
# define WORLDGENERATOR_HPP


class							WorldGenerator
{
	public:
								WorldGenerator();
								WorldGenerator(int width, int height, int nb_cells);
								WorldGenerator(std::string filename);
								~WorldGenerator();

		void					generateWorld();
		std::vector<bool>		getWorld();
		int						getWidth();
		int						getHeight();

	private:
		std::vector<bool>		_world;
		int						_width;
		int						_height;

	
};



#endif
