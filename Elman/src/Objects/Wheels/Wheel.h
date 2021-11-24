#pragma once
#include "../Drawable/Drawable.h"
#include "../Map/Map.h"
#include "../Point/Point.h"
#include <iostream>
# define M_PI 3.14159265358979323846
#define M_SPEED 20.0

class Wheel : public Drawable {
private:
	int m_radius;
	float alpha = 0;
	bool isOnRoad = false;
	bool gasPressed = false;
	bool breakPressed = false;
	bool reverseGasPressed = false;
	char direction = 'l';
	float mu = 0.1;
	float max_speed = 20;
	float v_x = 0;
	float v_y = 0;
	float a_x = 0;
	float a_y = 0;
	float v_x_map = 0;
	float v_y_map = 0;
	float a_x_map = 0;
	float a_y_map = 0;
	float F_x = 0;
	float F_y = 0;
	float F_acceleration = 0;
	float g = 9.8;
	float mass = 2;
	Point m_mapPosition;
	Map* m_map;

	float m_bikeSize = 100.0f;
	Wheel* otherWheel;
	bool isRear = false;

public:
	Wheel();
	Point getMapPosition();
	void setMapPosition(Point point);
	void setMap(Map * map);
	float get_v_x();
	int getRadius();
	void update();
	void gas();
	void breaks();
	void countAcceleration();
	float get_F_x();
	float get_F_y();
	void set_F_x(float f);
	void set_F_y(float f);

	void setOtherWheel(Wheel * wheel);
	void setRear(bool i);
};

