#include <iostream>

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "BezierCurve.h"
#include "BSplineCurve.h"

class Affichage : public olc::PixelGameEngine
{
private:
	bool isBezier = true;
	BezierCurve bezierCurve;
	BSplineCurve bSplineCurve;
public:
	Affichage()
	{
		sAppName = "Bezier curve & B-Spline";
	}

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);

		if (GetKey(olc::Key::ENTER).bPressed)
			isBezier = !isBezier;

		int ncurve = 0;
		if (isBezier)
		{
			if (GetMouse(2).bPressed) {
				for (auto& point : bezierCurve.getControlPoints()) {
					Point mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
					if (mouse >= point - Point(5, 5) && mouse <= point + Point(5, 5)) {
						bezierCurve.removePoint(point);
					}
				}
			}

			if(GetMouse(1).bPressed)
				bezierCurve.addPoint({ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) });

			if (GetMouse(0).bHeld) {
				for (auto& point : bezierCurve.getControlPoints()) {
					Point mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
					if (mouse >= point - Point(5, 5) && mouse <= point + Point(5, 5)) {
						bezierCurve.replacePoint(point, mouse);
					}
				}
			}

			if (GetKey(olc::Key::R).bPressed)
				bezierCurve.clear();

			if (GetKey(olc::Key::LEFT).bPressed)
				bezierCurve.decreaseStep();

			if (GetKey(olc::Key::RIGHT).bPressed)
				bezierCurve.increaseStep();


			DrawString(ScreenHeight() - 100, 20, "Step : " + std::to_string(bezierCurve.getPossibleSteps()[bezierCurve.getStepIndex()]), olc::WHITE);
			bezierCurve.Draw(*this);
		}
		else 
		{
			int number = bSplineCurve.getNoeuds().size();

			if (GetMouse(2).bPressed)
			{
				for (auto& point : bSplineCurve.getControlPoints()) {
					Point mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
					if (mouse >= point - Point(5, 5) && mouse <= point + Point(5, 5)) {
						bSplineCurve.removePoint(point);
					}
				}
			}

			if (GetMouse(1).bPressed) {
				bSplineCurve.addPoint({ static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) });
			
				bSplineCurve.clearNoeuds();
				if(number == 0)
					bSplineCurve.addPoid(0.0);
				else
					for (int i = 0; i < number + 1; i++)
						bSplineCurve.addPoid((i) / static_cast<double>(number));
			}

			if (GetMouse(0).bHeld) {
				for (auto& point : bSplineCurve.getControlPoints()) {
					Point mouse = { static_cast<float>(GetMouseX()), static_cast<float>(GetMouseY()) };
					if (mouse >= point - Point(5, 5) && mouse <= point + Point(5, 5)) {
						bSplineCurve.replacePoint(point, mouse);
					}
				}
			}

			if (GetKey(olc::Key::R).bPressed)
				bSplineCurve.clear();

			if (GetKey(olc::Key::LEFT).bPressed)
				bSplineCurve.decreaseStep();

			if (GetKey(olc::Key::RIGHT).bPressed)
				bSplineCurve.increaseStep();

			DrawString(ScreenHeight() - 100, 20, "Step : " + std::to_string(bSplineCurve.getPossibleSteps()[bSplineCurve.getStepIndex()]), olc::WHITE);
			bSplineCurve.Draw(*this);
		}
		
		std::string mode = isBezier ? "Mode : Bezier" : "Mode : B-Spline";
		DrawString(10, 10, "Right click to add a control point", olc::WHITE);
		DrawString(10, 20, "Left click to move a control point", olc::WHITE);
		DrawString(10, 30, "Middle click to remove a control point", olc::WHITE);
		DrawString(10, 40, "Press R to reset", olc::WHITE);
		DrawString(10, 50, mode, olc::WHITE);

		int numControlPoints = isBezier ? bezierCurve.getControlPoints().size() : bSplineCurve.getControlPoints().size();
		DrawString(ScreenHeight() - 100, 10, "Number of control points : " + std::to_string(numControlPoints), olc::WHITE);

		return true;
	}
};

int main()
{
	Affichage app;
	if (app.Construct(900, 600, 1, 1))
		app.Start();

	return 0;
}