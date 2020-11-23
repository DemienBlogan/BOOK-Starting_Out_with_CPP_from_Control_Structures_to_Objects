/*
13. Pure Abstract Base Class Project
Define a pure abstract base class called BasicShape. The BasicShape class should
have the following members:

Private Member Variable:
area: A double used to hold the shape's area.

Public Member Functions:
getArea: This function should return the value in the member variable area.
calArea: This function should be a pure virtual function.

Next, define a class named Circle. It should be derived from the Basic Shape class. It
should have the following members:

Private Member Variables:
centerX: a long integer used to hold the x coordinate of the circle's center
centerY: a long integer used to hold the y coordinate of the circle's center
radius: a double used to hold the circle's radius

Public Member Functions:
constructor: accepts values for centerX, centerY, and radius. Should call the
             overriden calcArea function described below.
getCenterX:  returns the value in centerX
getCenterY:  returns the value in centerY
calcArea:    calculates the area of the circle (area = 3.14159 * radius * radius)
             and stores the result in the inherited member area.

Next, define a class named Rectangle. It should be derived from the BasicShape
class. It should have the following members:

Private Member Variables:
width: a long integer used to hold the width of the rectangle
length: a long integer used to hold the length of the rectangle

Public Member Functions:
constructor: accepts values for width and length. Should call the overridden
             calcArea function described below.
getWidth:    returns the value in width
getLength:   returns the value in length
calcArea:    calculates the area of the rectangle (area = length * width) and stores
             the result in the inherited member area.

After you have created these classes, create a dvirer program that defined a Circle
object and a Rectangle object. Demonstrate that each object properly calculates and
reports its area.
*/

#include <iostream>
#include "Shapes.h"

using std::cout;
using std::endl;

int main()
{
    Circle circle{ 3, 7, 10 };
    Rectangle rectangle{ 20, 30 };

    cout << "Circle Information:\n";
    cout << "Center = [" << circle.GetCenterX() << ", " << circle.GetCenterY() << "]\n";
    cout << "Area = " << circle.getArea() << "\n\n";

    cout << "Rectangle Information:\n";
    cout << "Width = " << rectangle.GetWidth() << endl;
    cout << "Length = " << rectangle.GetLength() << endl;
    cout << "Area = " << rectangle.getArea() << endl;

    return 0;
}