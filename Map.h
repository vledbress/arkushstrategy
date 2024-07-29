#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
#include <vector>
#include "Tile.h"


class Map
{
private:
	int _width;//количество клеток
	int _height;
	std::vector<std::shared_ptr<Tile>> _map;
public: 
	Map() : _width(Consts::SCREEN_WIDTH / Consts::TILE_SIZE),
		_height(Consts::SCREEN_HEIGHT / Consts::TILE_SIZE) {};
	Map(int w, int h) :_width(w), _height(h) {};
};

