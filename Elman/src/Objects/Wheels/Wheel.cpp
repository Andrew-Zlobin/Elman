#include "Wheel.h"

Wheel::Wheel() : Drawable("D:\\Code\\mathmod\\lb1\\Elman\\Elman\\imgs\\wheel.png") {
	m_radius = 25;
	max_speed = 20;
	v_x = 0;
	v_y = 0;
	a_x = 0;
	a_y = 0;
	F_x = 0;
	F_y = 0;
	g = 90.8;
	m_mapPosition = Point(300, 600);
	origin = Point(25, 25);
	windowPosition = m_mapPosition;
}

Point Wheel::getMapPosition()
{
	return m_mapPosition;
}

void Wheel::setMapPosition(Point point) {
	m_mapPosition = point;
}

void Wheel::setMap(Map* map) {
	m_map = map;
}

float Wheel::get_v_x()
{
	return v_x;
}

int Wheel::getRadius() {
	return m_radius;
}

void Wheel::update() {

	if (gasPressed) {
		if (F_acceleration < 14) {
			F_acceleration += 0.5;
		}
	} else {
		if (reverseGasPressed) {
			if (F_acceleration > -14) {
				F_acceleration -= 0.5;
			}
		}
		else {
			F_acceleration = 0;
		}
	} 
	
	//std::cout << gasPressed << ' ' << F_acceleration << '\n';
	
	gasPressed = false;
	reverseGasPressed = false;



	a_y = F_y / mass;
	v_y += a_y;
	m_mapPosition.y += v_y;

	a_x = F_x / mass;
	v_x += a_x;
	if (v_x > 0) {
		direction = 'l';
	} else {
		direction = 'r';
	}

	m_mapPosition.x += v_x;
	//m_map->setWindowPosition(Point(m_map->getWindowPosition().x - v_x, m_map->getWindowPosition().y));
	
	float rotationspeed = v_x;
	if (rotationspeed > 30) {
		rotationspeed = 25;
	}
	if (rotationspeed < -30) {
		rotationspeed = -25;
	}
	spriteRotation += asin((float)rotationspeed / (float)m_radius) * 180 / M_PI;
	if (spriteRotation > 64000 || spriteRotation < -64000) { spriteRotation = 0; }

	//std::cout << spriteRotation << ' ' << rotationspeed << '\n';

	isOnRoad = false;
	for (int i_x = -m_radius; i_x <= m_radius; i_x++) {
		float i_y = sqrt(m_radius * m_radius - i_x * i_x);
		if (m_map->getHeight(m_mapPosition.x + i_x) >= m_mapPosition.y - i_y) {
			m_mapPosition.y = m_map->getHeight(m_mapPosition.x + i_x) + i_y;
			alpha = m_map->getAlpha(m_mapPosition.x + i_x);
			isOnRoad = true;
		}
	}
	
	
	windowPosition.y = m_mapPosition.y;
	//windowPosition.x = m_mapPosition.x;

	
}

void Wheel::gas() {
	gasPressed = true;
}

void Wheel::breaks() {
	reverseGasPressed = true;
}

void Wheel::countAcceleration() {
	float F_t = -mass * g / M_SPEED;
	float P = 0;
	if (isOnRoad) {
		P = abs(F_t) * cos(alpha);
	}
	float F_a = F_acceleration;
	float F_tr = 0;
	if (v_x > 0.1) {
		if (direction == 'l') {
			F_tr = -P * mu;
		}
		else {
			F_tr = P * mu;
		}
	}



	F_y = P * cos(alpha) + F_a * sin(alpha) + F_t + F_tr * sin(alpha);
	F_x = 0;
	if (isOnRoad) {
		F_x = -P * sin(alpha) + F_a * cos(alpha) + F_tr * cos(alpha);
	}
}

float Wheel::get_F_x()
{
	return F_x;
}

float Wheel::get_F_y()
{
	return F_y;
}

void Wheel::set_F_x(float f) {
	F_x = f;
}

void Wheel::set_F_y(float f) {
	F_y = f;
}

void Wheel::setOtherWheel(Wheel* wheel) {
	otherWheel = wheel;
}

void Wheel::setRear(bool i) {
	isRear = i;
}

