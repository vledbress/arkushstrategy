#pragma once
#include "Tile.h"
class GroundTile : public Tile
{
private:
	bool _free = true;
public:
	GroundTile(std::string path, int w, int h, float x, float y);

	void print() override;
};

