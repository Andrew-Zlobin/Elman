#include "Bike.h"

Bike::Bike() : Drawable("D:\\Code\\mathmod\\lb1\\Elman\\Elman\\imgs\\bike.png"){
	m_frontPoint = Point(400, 300);
	m_rearPoint = Point(300, 300);
	
	m_frontWheel.setMapPosition(m_frontPoint);
	m_rearWheel.setMapPosition(m_rearPoint);
	m_frontWheel.setWindowPosition(m_frontPoint);
	m_rearWheel.setWindowPosition(m_rearPoint);

	m_frontWheel.setOtherWheel(&m_rearWheel);
	m_rearWheel.setOtherWheel(&m_frontWheel);
	m_rearWheel.setRear(true);

	g = g / M_SPEED;

	origin = Point(50, 50);
}

void Bike::gas() {
	m_rearWheel.gas();
}

void Bike::breaks() {
	m_rearWheel.breaks();
}

void Bike::setMap(Map* map) {
	m_map = map;
	m_frontWheel.setMap(map);
	m_rearWheel.setMap(map);
}



Wheel * Bike::getFrontWheel()
{
	return &m_frontWheel;
}

Wheel * Bike::getRearWheel()
{
	return &m_rearWheel;

}

void Bike::update() {
	m_frontPoint = m_frontWheel.getWindowPosition();
	m_rearPoint = m_rearWheel.getWindowPosition();

	m_frontWheel.countAcceleration();
	m_rearWheel.countAcceleration();
	
	float F_x = m_frontWheel.get_F_x() + m_rearWheel.get_F_x();
	float F_y = m_frontWheel.get_F_y() + m_rearWheel.get_F_y();
	m_frontWheel.set_F_x(F_x);
	m_frontWheel.set_F_y(F_y);
	m_rearWheel.set_F_x(F_x);
	m_rearWheel.set_F_y(F_y);

	m_frontWheel.update();
	m_rearWheel.update();
	
	float F_elasticity_x = sqrt(F_x * F_x + F_y * F_y);
	float F_t = mass * g;
	float a = (F_elasticity_x - F_t * sin(atan((float)(m_frontPoint.y - m_rearPoint.y)) + sqrt(delta_y * delta_y + delta_x * delta_x) * k)) / mass ;
	delta_x += a * cos(atan((float)(m_frontPoint.y - m_rearPoint.y)));
	delta_y += a * sin(atan((float)(m_frontPoint.y - m_rearPoint.y)));
	//std::cout << delta_x<< ' ' << delta_y << '\n';

	windowPosition = Point((m_frontPoint.x + m_rearPoint.x) /2 + delta_x, (m_frontPoint.y + m_rearPoint.y) / 2 + delta_y);
	spriteRotation = -atan((float)(m_frontPoint.y - m_rearPoint.y) / (float)(m_frontPoint.x - m_rearPoint.x)) * 180 / M_PI;
	//std::cout << spriteRotation << '\n';
	v_x = m_rearWheel.get_v_x();


	std::cout << windowPosition.x << ' ' << windowPosition.y << '\n';
	//std::cout << m_rearWheel.get_v_x() << m_frontWheel.get_v_x()<< '\n';
	//m_frontWheel.setWindowPosition(Point(m_frontWheel.getWindowPosition().x - v_x, m_frontWheel.getWindowPosition().y));
	//m_rearWheel.setWindowPosition(Point(m_rearWheel.getWindowPosition().x - m_rearWheel.get_v_x(), m_rearWheel.getWindowPosition().y));

	m_map->setWindowPosition(Point(m_map->getWindowPosition().x - v_x , m_map->getWindowPosition().y));
}


