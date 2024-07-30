#pragma once
#include "TileFactory.h"
#include "Header.h"


class AnimationI
{
public:
	virtual void update() = 0;
    virtual ~AnimationI() = default;
};


class ShiftAnimation : public AnimationI {
private:
    std::shared_ptr<Tile> _obj;
    sf::Vector2f _targetPosition;
    sf::Vector2f _delta;

public:
    ShiftAnimation(std::shared_ptr<Tile> obj, sf::Vector2f targetPosition, float time);

    void update();
};