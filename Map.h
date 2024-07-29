#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
#include <vector>
#include "TileFactory.h"


class Map
{
private:
	int _width;//количество клеток
	int _height;
	std::vector<std::vector<std::shared_ptr<Tile>>> _map;
public: 
	Map();
	//Map(int w, int h);

	void draw(sf::RenderWindow& window);
};

