#include "Animation.h"

ShiftAnimation::ShiftAnimation(std::shared_ptr<Tile> obj, sf::Vector2f targetPosition, float time)
    : _obj(obj), _targetPosition(targetPosition)
{
    sf::Vector2f _startPosition = obj->getPosition();

    float xmod = targetPosition.x - _startPosition.x;
    float ymod = targetPosition.y - _startPosition.y;

    _delta = { xmod / time , ymod / time };


    _delta.x /= Consts::fps;
    _delta.y /= Consts::fps;
}

void ShiftAnimation::update()
{
    if (!_obj) return;

    sf::Vector2f currentPosition = _obj->getPosition();
    sf::Vector2f newPosition = currentPosition + _delta;


    if ((_delta.x > 0 && newPosition.x > _targetPosition.x) ||
        (_delta.x < 0 && newPosition.x < _targetPosition.x)) {
        newPosition.x = _targetPosition.x;
    }
    if ((_delta.y > 0 && newPosition.y > _targetPosition.y) ||
        (_delta.y < 0 && newPosition.y < _targetPosition.y)) {
        newPosition.y = _targetPosition.y;
    }

    _obj->setPosition(newPosition);

    if (newPosition == _targetPosition) {
        _isFinished = true;
    }
}

bool ShiftAnimation::isFinished() 
{
    return _isFinished;
}

void AnimationManager::addAnimation(std::shared_ptr<AnimationI> an)
{
    if (an) {
        _animations.push_back(an);
    }
}

void AnimationManager::update()
{
    if (_animations.size() > 0) {
        for (const auto it : _animations) {
            it->update();
        }

        _animations.erase(
            std::remove_if(_animations.begin(), _animations.end(),
                [](const std::shared_ptr<AnimationI>& anim) { return anim->isFinished(); }),
            _animations.end()
        );
    }
    //std::cout << _animations.size() << std::endl;
}
