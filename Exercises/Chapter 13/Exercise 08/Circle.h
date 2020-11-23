#pragma once

class Circle
{
private:
	double radius;
	const double PI = 3.14159;

public:
	Circle()
		: radius(0.0)
	{ }

	Circle(double radius)
		: radius(radius)
	{ }

	void SetRadius(double radius) { this->radius = radius; }
	double GetRadius() const { return radius; }
	double GetArea() const { return PI * radius * radius; }
	double GetDiameter() const { return radius * 2; }
	double GetCircumference() const { return 2 * PI * radius; }
};