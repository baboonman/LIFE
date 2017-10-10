#ifndef WORLD_HPP
# define WORLD_HPP


class							World
{
	public:
								World();
								World(int width, int height);
								~World();

		int						width();
		int						height();

		const bool &			operator[][](int i);


	private:
		int						_width;
		int						_height;
		std::vector<bool>		_grid;
};


#endif
