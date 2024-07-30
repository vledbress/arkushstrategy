#pragma once
#include "TileFactory.h"
#include "Header.h"


class AnimationI
{
public:
	virtual void update() = 0;
    virtual ~AnimationI() = default;
    virtual bool isFinished() = 0;
};


class ShiftAnimation : public AnimationI {
private:
    std::shared_ptr<Tile> _obj;
    sf::Vector2f _targetPosition;
    sf::Vector2f _delta;
    bool _isFinished = false;
public:
    ShiftAnimation(std::shared_ptr<Tile> obj, sf::Vector2f targetPosition, float time);

    void update();

    bool isFinished();
};


class AnimationManager {
private:
    std::vector<std::shared_ptr<AnimationI>> _animations;
public:
    void addAnimation(std::shared_ptr<AnimationI> an);

    void update();
};