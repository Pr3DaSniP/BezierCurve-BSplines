#pragma once
#include <ostream>

class Point
{
	float m_x, m_y;
public:
	Point() = default;
	Point(float x, float y);
	float getX() const;
	float getY() const;
	void setX(float x);
	void setY(float y);

	friend std::ostream& operator<<(std::ostream& os, const Point& p);

	friend bool operator==(const Point& p1, const Point& p2);

	friend bool operator!=(const Point& p1, const Point& p2);

	friend Point operator+(const Point& p1, const Point& p2);

	friend Point operator-(const Point& p1, const Point& p2);

	friend Point operator*(const Point& p1, const Point& p2);

	friend Point operator*(const Point& p, float f);

	friend Point operator*(float f, const Point& p);

	friend Point operator/(const Point& p1, const Point& p2);

	friend Point operator/(const Point& p, float f);

	friend Point operator/(float f, const Point& p);

	friend bool operator>=(const Point& p1, const Point& p2);

	friend bool operator<=(const Point& p1, const Point& p2);

	Point operator=(const Point& p);
};

