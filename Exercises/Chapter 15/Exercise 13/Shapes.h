#pragma once
class BasicShape abstract
{
protected:
	double area;

public:
	double getArea() const;
	virtual void calcArea() abstract;
};

class Circle final : public BasicShape
{
private:
	long centerX;
	long centerY;
	double radius;

public:
	Circle(long centerX = 0, long centerY = 0, double radius = 1);

	long GetCenterX() const;
	long GetCenterY() const;

	virtual void calcArea() override final;
};

class Rectangle final : public BasicShape
{
private:
	long width;
	long length;

public:
	Rectangle(long width = 1, long length = 1);

	long GetWidth() const;
	long GetLength() const;

	virtual void calcArea() override final;
};