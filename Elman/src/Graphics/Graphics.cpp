#include "Graphics.h"
Graphics::Graphics() {
	//sf::RenderWindow newWindow(sf::VideoMode(200, 200), "SFML Works!");
	
}

Graphics::Graphics(Drawable ** objects) {
	window = new sf::RenderWindow(sf::VideoMode(1600, 900), "SFML Works!");
	m_objects = objects;
}

Graphics& Graphics::operator=(const Graphics& graphics) {
	window = graphics.window;
	m_objects = graphics.m_objects;
	return *this;
}

Graphics::Graphics(const Graphics& graphics) {
	window = graphics.window;
	m_objects = graphics.m_objects;
}

void Graphics::update() {
	sf::RenderTexture renderTexture;
	if (!renderTexture.create(1600, 900))
	{
		// error...
	}
	renderTexture.clear(sf::Color::White);

	sf::Sprite objectSprite;
	sf::Texture objectTexture = *(m_objects[0]->getTexture());
	objectSprite.setTexture(objectTexture);
	objectSprite.setPosition(m_objects[0]->getWindowPosition().x, 0);
	objectSprite.setRotation(0);
	renderTexture.draw(objectSprite);

	for (int i = 1; i < 4; i++) {
		sf::Sprite objectSprite;
		sf::Texture objectTexture;
		objectTexture.loadFromFile(m_objects[i]->getTextureFilePath());
		objectSprite.setTexture(objectTexture);
		objectSprite.setOrigin(m_objects[i]->getOrigign().x, m_objects[i]->getOrigign().y);
		objectSprite.setPosition(m_objects[i]->getWindowPosition().x, 900 - m_objects[i]->getWindowPosition().y);
		objectSprite.setRotation(m_objects[i]->getSpriteRotation());
		renderTexture.draw(objectSprite);
	}
	
	
	
	
	renderTexture.display();

	// get the target texture (where the stuff has been drawn)
	const sf::Texture &texture = renderTexture.getTexture();

	// draw it to the window
	sf::Sprite sprite(texture);
	//window->clear(sf::Color::Black);
	window->draw(sprite);
	window->display();
}

sf::RenderWindow* Graphics::getWindow() {
	return window;
}

void Graphics::close() {
	window->close();
}
