#include "AnimationFactory.h"

std::shared_ptr<AnimationI> ShiftAnimationFactory::createAnimation(std::shared_ptr<Tile> obj, sf::Vector2f vec, float time)
{
    return std::make_shared<ShiftAnimation>(obj, vec, time);
}

std::shared_ptr<AnimationI> PulsationAnimationFactory::createAnimation(std::shared_ptr<Tile> obj, float percent, float time)
{
    return std::make_shared<PulsatingAnimation>(obj, percent, time);
}
