#include "Curve.h"

void Curve::addPoint(const Point& point) { controlPoints.push_back(point); }

void Curve::removePoint(const Point& point) { 
	controlPoints.erase(std::find(controlPoints.begin(), controlPoints.end(), point)); 
}

void Curve::removePoint(int index) { controlPoints.erase(controlPoints.begin() + index); }

void Curve::replacePoint(const Point& oldPoint, const Point& newPoint) { 
	controlPoints[std::find(controlPoints.begin(), controlPoints.end(), oldPoint) - controlPoints.begin()] = newPoint; 
}

void Curve::clear() { controlPoints.clear(); }

std::vector<Point> Curve::getControlPoints() const { return controlPoints; }

Point Curve::interpolate(const Point& p1, const Point& p2, double t) { return (1 - t) * p1 + t * p2; }

Point Curve::interpolate(const Point& p1, const Point& p2, const Point& p3, double t) { 
	return (1 - t) * p1 + 2 * (1 - t) * t * p2 + t * t * p3; 
}