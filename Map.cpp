#include "Map.h"

Map::Map() : _width(Consts::SCREEN_WIDTH / Consts::TILE_SIZE),
_height(Consts::SCREEN_HEIGHT / Consts::TILE_SIZE),
_map(_width, std::vector<std::shared_ptr<Tile>>(_height))
{
	
	GroundTileFactory GTF;


	
	for (int i = 0; i < _width; ++i) {
		
		for (int j = 0; j < _height; ++j) {
			_map[i][j] = GTF.createTile("res/sava.png", Consts::TILE_SIZE, Consts::TILE_SIZE, Consts::TILE_SIZE * i, Consts::TILE_SIZE * j);
		}
	}
}

void Map::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			_map[i][j]->draw(window);
		}
	}
}
