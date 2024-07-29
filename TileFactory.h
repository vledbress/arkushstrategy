#pragma once
#include "Tile.h"
#include "GroundTile.h"

class TileFactoryI
{
public:
	virtual ~TileFactoryI() = default;
	virtual std::shared_ptr<Tile> createTile(std::string path, int w, int h, float x, float y) const = 0;
};


class GroundTileFactory : public TileFactoryI {
public:
	std::shared_ptr<Tile> createTile(std::string path, int w, int h, float x, float y) const override {
		return std::make_shared<GroundTile>(path, w, h, x, y);
	}
};


class SimpleTileFactory : public TileFactoryI {
public: 
	std::shared_ptr<Tile> createTile(std::string path, int w, int h, float x, float y) const override {
		return std::make_shared<Tile>(path, w, h, x, y);
	}
};


