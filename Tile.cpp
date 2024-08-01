#include "Tile.h"

void Tile::reScale(float newW, float newH)
{
	sf::Vector2u textureSize = _texture.getSize();
	
	float scaleX = newW / (float)textureSize.x;
	float scaleY = newH / (float)textureSize.y;
	_sprite.setScale(scaleX, scaleY);
}

void Tile::setScale(sf::Vector2f scale)
{
	_sprite.setScale(scale);
}

//
//void Tile::oneMakesYouSmaller(float newW, float newH)
//{
//	sf::Vector2u curSize = _sprite.getTexture()->getSize();
//	sf::Vector2u newsize = curSize - sf::Vector2u{newW, newH};
//
//	
//
//
//	reScale(newsize.x, newsize.y);
//}




Tile::Tile(std::string path, int w, int h, float x, float y)
{
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_sprite.setPosition({ x,y });
	reScale(w, h);
}

sf::Vector2f Tile::getOrigSize()
{
	auto temp = _sprite.getTexture()->getSize();
	float x = temp.x;
	float y = temp.y;
	return { x,y };
}

sf::Vector2f Tile::getScaledSize()
{
	auto temp = getOrigSize();
	auto temp2 = _sprite.getScale();
	temp.x *= temp2.x;
	temp.y *= temp2.y;
	return temp;
}



void Tile::draw(sf::RenderWindow& window)
{
	window.draw(_sprite);
}

void Tile::setPosition(float x, float y)
{
	_sprite.setPosition({ x,y });
}

void Tile::setPosition(sf::Vector2f v)
{
	_sprite.setPosition(v);
}

sf::Vector2f Tile::getPosition()
{
	return _sprite.getPosition();
}

void Tile::incX(float x)
{
	_sprite.setPosition({ _sprite.getPosition().x + x, _sprite.getPosition().y });
}

void Tile::decX(float x)
{
	_sprite.setPosition({ _sprite.getPosition().x - x, _sprite.getPosition().y });
}

void Tile::incY(float y)
{
	_sprite.setPosition({ _sprite.getPosition().x, _sprite.getPosition().y + y });
}

void Tile::decY(float y)
{
	_sprite.setPosition({ _sprite.getPosition().x, _sprite.getPosition().y - y });
}

void Tile::print()
{
	auto a = _sprite.getPosition();
	std::cout << "Position: " << a.x << ", " << a.y << std::endl << std::endl;

	auto b = getOrigSize();
	std::cout << "pixel size: " << b.x << ", " << b.y << std::endl << std::endl;

	auto c = getScaledSize();
	std::cout << "Scaled size: " << c.x << ", " << c.y << std::endl << std::endl;

	auto d = _sprite.getScale();
	std::cout << "Scale size: " << d.x << ", " << d.y << std::endl << std::endl;

}



