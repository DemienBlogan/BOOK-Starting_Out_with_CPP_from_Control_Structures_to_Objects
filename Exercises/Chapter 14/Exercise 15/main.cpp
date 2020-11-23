/*
15. Car Instrument Simulator
For this assignment you will design a set of classes that work together to simulate a
car's fuel gauge and odometer. The classes you will design are:

- The FuelGauge Class: This class will simulate a fuel gauge. Its responsibilities are
  - To know the car's current amount of fuel, in gallons.
  - To report the car's current amount of fuel, in gallons.
  - To be able to increment the amount of fuel by 1 gallon. This simulates putting
    fuel in the car. (The car can hold a maximum of 15 gallons).
  - To be able to decrement the amount of fuel by 1 gallon, if the amount of fuel
    is greater than 0 gallons. This simulates burning fuel as the car runs.

- The Odometer Class: This class will simualte the car's odometer. Its responsibilitites
  are:
  - To know the car's current mileage.
  - To report the car's current mileage.
  - To be able to increment the current mileage by 1 mile. The maximum mileage the
    odometer can store is 999,999 miles. When this amount is exceeded, the odometer
    resets the current mileage to 0.
  - TO be able to work with a FuelGauge object. It should decrease the FuelGauge
    object's currect amount of fuel by 1 gallon for every 24 miles traveled. (The car's
    fuel economy is 24 miles per gallon).

Demonstrate the classes by creating instances of each. Simulate filling the car up with
fuel, then run a loop that increments the odometer until the car runs out of fuel. During
each loop iteration, print the car's current mileage and amount of fuel.
*/

#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

using std::cout;
using std::endl;

int main()
{
    FuelGauge gauge;

    cout << "Fiiling up fuel...\n";
    for (size_t i = 0; i < 2; i++)
        gauge.FillUp1Gallon();
    cout << "There is " << gauge.GetFuelGallons() << " gallons.\n";

    Odometer odometer{ gauge };

    for (size_t i = 0; i < 200; i++)
    {
        if (!odometer.IncreaseBy1Mile())
            break;
        else
            cout << "We drove " << odometer.GetMileage() << " miles.\n";
    }

    if (gauge.GetFuelGallons() == 0)
        cout << "Now fuel gauge is empty.\n";

    return 0;
}