/*
14. Parking Ticket Simulator
For this assignment, you will design a set of classes that work together to simulate a
police officer issuing a parking ticket. The classes you should degisn are:

- The ParkedCar Class: This class should simulate a parked car. The class's responsibilites
  are:
  - To know the car's make, model, color, license number, and the number of minutes
    that the car has been parked.

- The ParkingMeter Class: This class should simulate a parking meter. The class's
  only responsibility is:
  - To know the number of minutes of parking time that has been purchased

- The ParkingTicket Class: This class should simulate a parcking ticket. The class's
  responsibilites are:
  - To report the make, model, color, and license number of the illegally parked car
  - To report the amount of the fine, which is $25 for the first hour or part of an
    hour that the car is illegally parked, plus $10 for every additional hour or part of
    an hour that the car is illegaly parked
  - To report the name and badge number of the police officer issuing the ticket

- The PoliceOfficer Class: This class should simulate a police officer inspecting
  parked cars. The class's responsibilities are:
  - To know the police officer's name and badge number
  - To examine a ParkedCar object and a ParkingMeter object, and determine
    whether the car's time has expired
  - To issue a parking ticket (generate a ParkingTicket object) if the car's time has
    expired

Write a program that demonstrates how these classes collaborate.
*/

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

int main()
{
    ParkedCar car{ "Audi", "R7", "Black", "123-AD", 200 };
    ParkingMeter meter{ 70 };
    PoliceOfficer officer{ "Demien Blogan", "Officer #123145", car, meter };
    ParkingTicket ticket{ car, officer };

    ticket.ReportCar();
    ticket.ReportFine();
    ticket.ReportOfficerInfo();

    return 0;
}