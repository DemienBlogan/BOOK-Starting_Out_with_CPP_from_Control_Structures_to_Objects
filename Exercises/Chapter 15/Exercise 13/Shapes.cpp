#include "Shapes.h"

double BasicShape::getArea() const
{
    return area;
}

Circle::Circle(long centerX, long centerY, double radius)
    : centerX(centerX), centerY(centerY), radius(radius)
{
    calcArea();
}

long Circle::GetCenterX() const
{
    return centerX;
}

long Circle::GetCenterY() const
{
    return centerY;
}

void Circle::calcArea()
{
    const static double PI = 3.1415;
    area = PI * radius * radius;
}

Rectangle::Rectangle(long width, long length)
    : width(width), length(length)
{
    calcArea();
}

long Rectangle::GetWidth() const
{
    return width;
}

long Rectangle::GetLength() const
{
    return length;
}

void Rectangle::calcArea()
{
    area = width * length;
}