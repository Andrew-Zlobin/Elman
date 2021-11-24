#include "Game.h"

Game::Game() {
	isRun = true;
	m_objects = new Drawable * [4];
	m_objects[0] = &map;
	bike.setMap(&map);
	m_objects[1] = &bike;
	m_objects[2] = bike.getFrontWheel();
	m_objects[3] = bike.getRearWheel();
	graphics = Graphics(m_objects);
	input = Input(graphics);
}

void Game::execute() {
	
	while (isRun) {
		input.update();
		graphics.update();
		bike.update();
		if (input.closeButtonPressed()) {
			exit();
		}
		if (input.pressed(ControlButtons::GAS)) {
			//std::cout << "gas\n";
			bike.gas();
		}
		if (input.pressed(ControlButtons::BREAK)) {
			//std::cout << "break\n";
			bike.breaks();
		}
	}
}

void Game::exit() {
	isRun = false;
	graphics.close();
}
