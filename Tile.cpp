#include "Tile.h"

void Tile::reScale(float newW, float newH)
{
	sf::Vector2u textureSize = _texture.getSize();
	float scaleX = newW / (float)textureSize.x;
	float scaleY = newH / (float)textureSize.y;
	_sprite.setScale(scaleX, scaleY);
}

Tile::Tile(std::string path, int w, int h, float x, float y)
{
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_sprite.setPosition({ x,y });
	reScale(w, h);
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
	std::cout << "Tile\n";
}



