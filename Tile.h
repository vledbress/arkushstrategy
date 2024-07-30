#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Tile
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	

	void reScale(float newW, float newH);


public:

	Tile(std::string path, int w, int h, float x, float y);
	

	void draw(sf::RenderWindow& window);

	sf::Sprite getSprite() { return _sprite; }

	void setPosition(float x, float y);

	void setPosition(sf::Vector2f v);

	sf::Vector2f getPosition();

	void incX(float x);

	
	void decX(float x);

	
	void incY(float y);

	
	void decY(float y);

	virtual void print();
};

