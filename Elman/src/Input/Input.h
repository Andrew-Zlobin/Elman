#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Graphics/Graphics.h"

enum ControlButtons {
	GAS,
	BREAK
};


class Input {
private:
	sf::RenderWindow* m_window;
	sf::Event event;
	bool m_closeButtonPressed;
	char buttonList[2];
	bool pressedButton[255];
public:
	Input();
	Input(Graphics graphics);
	void setWindow(sf::RenderWindow* window);
	void update();
	bool pressed(ControlButtons button);
	bool closeButtonPressed();
};

