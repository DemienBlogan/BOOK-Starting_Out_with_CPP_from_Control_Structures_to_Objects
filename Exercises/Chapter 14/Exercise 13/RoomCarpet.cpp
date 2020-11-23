#include "RoomCarpet.h"

RoomCarpet::RoomCarpet(const RoomDimension& roomDimension, double costOfCarpetPerFoot)
    : roomDimension(roomDimension), costOfCarpetPerFoot(costOfCarpetPerFoot)
{ }

double RoomCarpet::GetCost() const
{
    FeetInches area = roomDimension.GetArea();
    int inches = area.getInches();
    int feet = area.getFeet() + inches / 12;

    double cost = costOfCarpetPerFoot * feet;

    return cost;
}
