#include "RoomDimension.h"

RoomDimension::RoomDimension(const FeetInches& length, const FeetInches& width)
	:length{ length }, width{ width }
{ }

void RoomDimension::SetLength(const FeetInches& length)
{
	this->length = length;
}

void RoomDimension::SetWidth(const FeetInches& width)
{
	this->width = width;
}

FeetInches RoomDimension::GetLength() const
{
	return length;
}

FeetInches RoomDimension::GetWidth() const
{
	return width;
}

FeetInches RoomDimension::GetArea() const
{
	return length * width;
}

bool RoomDimension::operator==(const RoomDimension& other) const
{
	return this->GetArea() == other.GetArea();
}

bool RoomDimension::operator!=(const RoomDimension& other) const
{
	return !(*this == other);
}