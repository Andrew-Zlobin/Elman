#pragma once

#include "../Objects/Drawable/Drawable.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Graphics {
private:
	sf::RenderWindow* window;
	Drawable ** m_objects;
public:
	Graphics();
	Graphics(Drawable** objects);
	Graphics& operator= (const Graphics& graphics);
	Graphics(const Graphics& graphics);
	void update();
	sf::RenderWindow* getWindow();
	void close();
};

