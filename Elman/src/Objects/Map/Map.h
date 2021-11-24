#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Point/Point.h"
#include "../Drawable/Drawable.h"

class Map : public Drawable {
private:
	Point* pointsArray;
	sf::Texture texture;
	int pointsArraySize;
public:
	Map();
	sf::Texture * getTexture();
	int getHeight(int x);
	float getAlpha(int x);
};

