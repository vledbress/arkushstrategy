#pragma once
#include "Animation.h"

class AnimationFactoryI
{
public:
	virtual std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, sf::Vector2f vec, float time) = 0;
	virtual std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, float percent, float time) = 0;
};


class ShiftAnimationFactory : public AnimationFactoryI
{
public:
	std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, sf::Vector2f vec, float time);
	std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, float percent, float time) { return nullptr; }
};

class PulsationAnimationFactory : public AnimationFactoryI
{
public:
	std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, float percent, float time);
	std::shared_ptr<AnimationI> createAnimation(std::shared_ptr<Tile> obj, sf::Vector2f vec, float time) { return nullptr; }
};