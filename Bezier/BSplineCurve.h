#pragma once

#include <vector>
#include "Curve.h"
#include "olcPixelGameEngine.h"

class BSplineCurve : public Curve
{
private:
	std::vector<double> noeuds;

	void drawCubicBezierCurve(Point p1, Point p2, Point p3, olc::PixelGameEngine& pge);

public:
	BSplineCurve() = default;

	void addPoid(double p);

	void clearNoeuds();

	std::vector<double> getNoeuds() const;

	void Draw(olc::PixelGameEngine& pge);
};