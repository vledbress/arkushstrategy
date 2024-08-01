#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>


class Tile
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	

	


public:

	void reScale(float newW, float newH);

	void setScale(sf::Vector2f scale);

	void oneMakesYouSmaller(float newW, float newH);


	Tile(std::string path, int w, int h, float x, float y);
	
	sf::Vector2f getOrigSize();

	sf::Vector2f getScaledSize();


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

