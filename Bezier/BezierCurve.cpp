#include "BezierCurve.h"

Point BezierCurve::DeCasteljau(const std::vector<Point>& controlPoints, double t) {
	std::vector<Point> points = controlPoints;
	while (points.size() > 1) {
		std::vector<Point> intermediatePoints(points.size() - 1);
		for (int i = 0; i < intermediatePoints.size(); i++) {
			intermediatePoints[i] = interpolate(points[i], points[i + 1], t);
		}
		points = intermediatePoints;
	}
	return points[0];
}

void BezierCurve::Draw(olc::PixelGameEngine& pge)
{
	std::vector<Point> pts_to_draw;
	
	for (auto& point : getControlPoints()) {
		pge.FillCircle(point.getX(), point.getY(), 5, olc::RED);
	}

	if (getControlPoints().size() > 1)
	{
		for (int i = 0; i < getControlPoints().size() - 1; i++) {
			Point p1 = getControlPoints()[i];
			Point p2 = getControlPoints()[i + 1];
			pge.DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), olc::DARK_MAGENTA);
		}

		for (double t = 0.0; t <= 1.0; t += m_possibleSteps[m_stepIndex]) {
			Point p = getDeCasteljauPoint(t);
			pts_to_draw.push_back(p);
		}
		
		for (int i = 0; i < pts_to_draw.size() - 1; ++i) {
			Point p1 = pts_to_draw[i];
			Point p2 = pts_to_draw[i + 1];
			pge.DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
		}
	}
}

Point BezierCurve::getDeCasteljauPoint(double t) { return DeCasteljau(controlPoints, t); }