#pragma once

#include "RoomDimension.h"

class RoomCarpet
{
private:
	RoomDimension roomDimension;
	double costOfCarpetPerFoot;

public:
	RoomCarpet(const RoomDimension& roomDimension, double costOfCarpetPerFoot);
	double GetCost() const;
};