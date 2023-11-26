#include "BSplineCurve.h"

void BSplineCurve::drawCubicBezierCurve(Point p1, Point p2, Point p3, olc::PixelGameEngine& pge)
{
	std::vector<Point> pts_to_draw;

	for (double t = 0.0; t <= 1.0; t += m_possibleSteps[m_stepIndex]) {
		Point p = interpolate(p1, p2, p3, t);
		pts_to_draw.push_back(p);
	}

	for (int i = 0; i < pts_to_draw.size() - 1; ++i) {
		Point p1 = pts_to_draw[i];
		Point p2 = pts_to_draw[i + 1];
		pge.DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
	}
}

void BSplineCurve::addPoid(double p) { noeuds.push_back(p); }

void BSplineCurve::clearNoeuds() { noeuds.clear(); }

std::vector<double> BSplineCurve::getNoeuds() const { return noeuds; }

void BSplineCurve::Draw(olc::PixelGameEngine& pge)
{
	auto controlPoints = getControlPoints();

	for (auto& point : controlPoints) {
		pge.FillCircle(point.getX(), point.getY(), 5, olc::RED);
	}

	if (controlPoints.size() > 1) {
		for (int i = 0; i < controlPoints.size() - 1; i++) {
			Point p1 = controlPoints[i];
			Point p2 = controlPoints[i + 1];
			pge.DrawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY(), olc::DARK_MAGENTA);
		}

		for (int i = 0; i < controlPoints.size() - 2; i += 2) {
			Point p1 = controlPoints[i];
			Point p2 = controlPoints[i + 1];
			Point p3 = controlPoints[i + 2];
			drawCubicBezierCurve(p1, p2, p3, pge);
		}
	}
}