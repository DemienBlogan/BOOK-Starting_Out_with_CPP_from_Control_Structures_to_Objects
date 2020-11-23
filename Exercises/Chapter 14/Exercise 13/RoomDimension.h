#pragma once

#include "FeetInches.h"

class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;

public:
	RoomDimension(const FeetInches& length = FeetInches(), const FeetInches& width = FeetInches());
	void SetLength(const FeetInches& length);
	void SetWidth(const FeetInches& width);
	FeetInches GetLength() const;
	FeetInches GetWidth() const;
	FeetInches GetArea() const;
	bool operator==(const RoomDimension& other) const;
	bool operator!=(const RoomDimension& other) const;
};