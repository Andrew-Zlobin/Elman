#include "../Wheels/Wheel.h"
#include "../Point/Point.h"
#include "../Drawable/Drawable.h"
#include "../Map/Map.h"
#include <iostream>
#define M_SPEED 30.0

class Bike : public Drawable {
private:
	//Spring m_frontSpring;
	//Spring rearSpring;

	Map* m_map;

	Wheel m_frontWheel;
	Wheel m_rearWheel;
	Point m_frontPoint;
	Point m_rearPoint;
	float m_bikeSize = 100.0f;
	float mass = 100.0f;
	float k = 1.0f;
	float delta_x = 0.0f;
	float delta_y = 0.0f;
	float g = 9.8f;
	float v_x = 0.0f;
	float v_y = 0.0f;
	float gas_acceleration;
	float break_acceleration;
	float max_speed;
	float max_rear_speed;
	Point mapPosition;
public:
	Bike();
	void gas();
	void breaks();
	void setMap(Map * map);
	Wheel * getFrontWheel();
	Wheel * getRearWheel();
	void update();
};