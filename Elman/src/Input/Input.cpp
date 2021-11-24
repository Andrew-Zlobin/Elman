#include "Input.h"

Input::Input() {
	m_closeButtonPressed = false;
	buttonList[ControlButtons::GAS] = 'W' - 'A';
	buttonList[ControlButtons::BREAK] = 'S' - 'A';
	for (int i = 0; i < 255; i++) {
		pressedButton[i] = false;
	}
}

Input::Input(Graphics graphics) : Input() {
	
	m_window = graphics.getWindow();
}

void Input::setWindow(sf::RenderWindow* window) {
	m_window = window;
}

void Input::update() {
	while (m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_closeButtonPressed = true;
		}
		if (event.type == sf::Event::KeyPressed) {
				pressedButton[event.key.code] = true;
		}
		if (event.type == sf::Event::KeyReleased) {
			pressedButton[event.key.code] = false;
		}
	}
}

bool Input::pressed(ControlButtons button) {
	return pressedButton[buttonList[button]];
}

bool Input::closeButtonPressed() {
	return m_closeButtonPressed;
}
