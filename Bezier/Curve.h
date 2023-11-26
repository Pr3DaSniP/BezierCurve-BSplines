#pragma once

#include "Point.h"
#include <vector>

#include <iostream>

class Curve
{
protected:
	std::vector<Point> controlPoints;
	std::vector<double> m_possibleSteps = { 0.1, 0.2, 0.5, 0.01, 0.002, 0.005, 0.0001 };
	int m_stepIndex = 0;
public:
	void addPoint(const Point& point);
	void removePoint(const Point& point);
	void removePoint(int index);
	void replacePoint(const Point& oldPoint, const Point& newPoint);
	void clear();
	std::vector<Point> getControlPoints() const;
	Point interpolate(const Point& p1, const Point& p2, double t);
	Point interpolate(const Point& p1, const Point& p2, const Point& p3, double t);

	std::vector<double> getPossibleSteps() const { return m_possibleSteps; }
	inline int getStepIndex() const { return m_stepIndex; }

	inline void increaseStep() { m_stepIndex = (m_stepIndex + 1) % m_possibleSteps.size(); }
	inline void decreaseStep() { m_stepIndex = (m_stepIndex - 1) % m_possibleSteps.size(); }
};
