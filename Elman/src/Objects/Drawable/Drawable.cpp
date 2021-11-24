#include "Drawable.h"




Drawable::Drawable()
{
}

Drawable::Drawable(std::string filePath) {
	m_filePath = filePath;
}

Point Drawable::getWindowPosition()
{
	return windowPosition;
}

int Drawable::getSpriteRotation()
{
	return spriteRotation;
}


void Drawable::setWindowPosition(Point point) {
	windowPosition = point;
}


std::string Drawable::getTextureFilePath()
{
	return m_filePath;
}

sf::Texture * Drawable::getTexture()
{
	sf::Texture texture;
	return &texture;
}

Point Drawable::getOrigign()
{
	return origin;
}


