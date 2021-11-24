#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Graphics/Graphics.h"
#include "../Input/Input.h"
#include "../Objects/Bike/Bike.h"
#include "../Objects/Map/Map.h"

class Game {
private:
	bool isRun;
	Graphics graphics;
	Input input;
	Drawable ** m_objects;
	Bike bike;
	Wheel wheel;
	Map map;
public:
	Game();
	void execute();
	void exit();
};

