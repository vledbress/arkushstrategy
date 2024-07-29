#include "GroundTile.h"

GroundTile::GroundTile(std::string path, int w, int h, float x, float y) :Tile(path, w, h, x, y) {};

void GroundTile::print()
{
	std::cout << "Ground Tile\n";
}

