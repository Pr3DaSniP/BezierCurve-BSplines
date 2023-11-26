#pragma once

#include <vector>
#include "Curve.h"
#include "olcPixelGameEngine.h"

class BezierCurve : public Curve
{
public:
	BezierCurve() = default;

	Point DeCasteljau(const std::vector<Point>& controlPoints, double t);

	Point getDeCasteljauPoint(double t);

	void Draw(olc::PixelGameEngine& pge);
};
