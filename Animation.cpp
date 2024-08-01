#include "Animation.h"
namespace mm {
    float minimizeByPercent(float num, float percent) {
        return num - ((percent / 100.f) * num);
    }
}


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

PulsatingAnimation::PulsatingAnimation(std::shared_ptr<Tile> obj, float percent, float time)
{
    _obj = obj;
    _percent = percent;
    _currentSteps = 0;
    std::cout << std::endl;
    obj->print();

    auto currscale = obj->getSprite().getScale();
    sf::Vector2f targetScale = { mm::minimizeByPercent(currscale.x, percent), mm::minimizeByPercent(currscale.y, percent) };
    _deltaScale = (currscale - targetScale) / time / (float)Consts::fps;
    _currentSteps = 0;
    _totalSteps = time * (float)Consts::fps;
    
    sf::Vector2f startPos = obj->getScaledSize();
    auto origSize = obj->getOrigSize();
    sf::Vector2f targetPos = { origSize.x * targetScale.x, origSize.y * targetScale.y };
   
    _deltaOffset = (startPos - targetPos)/2.f/(float)_totalSteps;



}


void PulsatingAnimation::update()
{
    if (_currentSteps < _totalSteps) {
        
        sf::Vector2f currentScale = _obj->getSprite().getScale();
        _obj->setScale(currentScale - _deltaScale);

        _currentSteps++;
        sf::Vector2f currentPosition = _obj->getPosition();
        sf::Vector2f newPosition = currentPosition + _deltaOffset;
        _obj->setPosition(newPosition);

    }
    else {
        _isFinished = true;
    }
    //std::cout << "current step = " << _currentSteps << std::endl;
}

bool PulsatingAnimation::isFinished()
{
    return _isFinished;
}






 