#include "Point.h"

Point::Point(float x, float y) : m_x(x), m_y(y) {}
float Point::getX() const { return m_x; }
float Point::getY() const { return m_y; }
void Point::setX(float x) { m_x = x; }
void Point::setY(float y) { m_y = y; }

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.m_x << ", " << p.m_y << ")";
	return os;
}

bool operator==(const Point& p1, const Point& p2)
{
	return p1.m_x == p2.m_x && p1.m_y == p2.m_y;
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}

Point operator+(const Point& p1, const Point& p2)
{
	return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
}

Point operator-(const Point& p1, const Point& p2)
{
	return Point(p1.m_x - p2.m_x, p1.m_y - p2.m_y);
}

Point operator*(const Point& p1, const Point& p2)
{
	return Point(p1.m_x * p2.m_x, p1.m_y * p2.m_y);
}

Point operator*(const Point& p, float f)
{
	return Point(p.m_x * f, p.m_y * f);
}

Point operator*(float f, const Point& p)
{
	return Point(p.m_x * f, p.m_y * f);
}

Point operator/(const Point& p1, const Point& p2)
{
	return Point(p1.m_x / p2.m_x, p1.m_y / p2.m_y);
}

Point operator/(const Point& p, float f)
{
	return Point(p.m_x / f, p.m_y / f);
}

Point operator/(float f, const Point& p)
{
	return Point(p.m_x / f, p.m_y / f);
}

bool operator>=(const Point& p1, const Point& p2)
{
	return p1.m_x >= p2.m_x && p1.m_y >= p2.m_y;
}

bool operator<=(const Point& p1, const Point& p2)
{
	return p1.m_x <= p2.m_x && p1.m_y <= p2.m_y;
}

Point Point::operator=(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
	return *this;
}