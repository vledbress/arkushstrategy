#include "AnimationFactory.h"

std::shared_ptr<AnimationI> ShiftAnimationFactory::createAnimation(std::shared_ptr<Tile> obj, sf::Vector2f vec, float time)
{
    return std::make_shared<ShiftAnimation>(obj, vec, time);
}
