#include "Map.h"

Map::Map(){
	pointsArray = new Point[1000];
	pointsArray[0] = Point(100, 300);
	pointsArray[1] = Point(700, 100);
	pointsArray[2] = Point(900, 100);
	pointsArray[3] = Point(1500, 300);
	pointsArray[4] = Point(2000, 400);
	pointsArray[5] = Point(3000, 200);
	pointsArray[6] = Point(4000, 300);
	pointsArray[7] = Point(6000, 200);
	pointsArray[8] = Point(7000, 10);
	//pointsArray[9] = Point(7100, 1000);

	pointsArraySize = 9;
}

sf::Texture * Map::getTexture() {
	sf::RenderTexture renderTexture;
	renderTexture.create(pointsArray[pointsArraySize - 1].x, 900);
	// check indexes !!!!!


	/*
	int startPoint = 0;
	int endPoint = 0;
	int mapLength = 0;


	while (mapLength < -windowPosition.x) {
		mapLength += pointsArray[startPoint].x;
		startPoint++;
	}
	startPoint -= 2;
	endPoint = startPoint;
	while (mapLength < -windowPosition.x + 1600 && endPoint <= pointsArraySize) {
		mapLength += pointsArray[startPoint].x;
		endPoint++;
	}
	endPoint;
	std::cout << startPoint << ' ' << endPoint<<'\n'; */
	//std::cout << windowPosition.x << ' ' << windowPosition.y << '\n';

	for (int i = 0; i < pointsArraySize; i++) {
		sf::CircleShape point(3);
		point.setFillColor(sf::Color::Black);
		point.setPosition(pointsArray[i].x - 3, pointsArray[i].y);
		renderTexture.draw(point);
		int length = sqrt((pointsArray[i].x - pointsArray[i - 1].x) * (pointsArray[i].x - pointsArray[i - 1].x)
			+ (pointsArray[i].y - pointsArray[i - 1].y) * (pointsArray[i].y - pointsArray[i - 1].y));
		sf::RectangleShape rectangle(sf::Vector2f(length, 5));
		rectangle.setFillColor(sf::Color::Black);
		rectangle.setPosition(pointsArray[i - 1].x, pointsArray[i - 1].y);
		float alpha = ((float) (pointsArray[i].y - pointsArray[i - 1].y));
		rectangle.rotate(asin(alpha / (float)length) * 180 / 3.14);
		renderTexture.draw(rectangle);
	}
	texture = renderTexture.getTexture();
	return & texture;
}

int Map::getHeight(int x)
{
	int mapLength = 0;
	Point a;
	Point b;
	int i = 0;
	while (mapLength < x) {
		i++;
		mapLength = pointsArray[i].x;
	}
	a = pointsArray[i - 1];
	b = pointsArray[i];
	return  (float)(b.y - a.y) * (x - a.x) / (float)(b.x - a.x) + a.y;
}

float Map::getAlpha(int x)
{
	int mapLength = 0;
	Point a;
	Point b;
	int i = 0;
	while (mapLength < x) {
		i++;
		mapLength = pointsArray[i].x;
	}
	a = pointsArray[i - 1];
	b = pointsArray[i];
	float l = b.x - a.x;
	float h = b.y - a.y;
	return asin(h / sqrt(l * l + h * h));
}
