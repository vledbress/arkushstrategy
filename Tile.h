#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Tile
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	int _w, _h;

	void reScale(float newW, float newH) {
		sf::Vector2u textureSize = _texture.getSize();
		float scaleX = newW / (float)textureSize.x;
		float scaleY = newH / (float)textureSize.y;
		_sprite.setScale(scaleX, scaleY);
	}


public:
	Tile(std::string path, int w, int h) {
		
		if (!_texture.loadFromFile(path)) {
			std::cerr << "Error: Could not load image from " << path << std::endl;
			return;
		}
		_sprite.setTexture(_texture);

		_w = w;
		_h = h;
		reScale(_w, _h);
	}

	void draw(sf::RenderWindow& window) {
		window.draw(_sprite);
	}

	sf::Sprite getSprite() { return _sprite; }
};

