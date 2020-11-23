#include "LandTract.h"

LandTract::LandTract(const FeetInches& length, const FeetInches& width)
	:length{ length }, width{ width }
{ }

void LandTract::SetLength(const FeetInches& length)
{
	this->length = length;
}

void LandTract::SetWidth(const FeetInches& width)
{
	this->width = width;
}

FeetInches LandTract::GetLength() const
{
	return length;
}

FeetInches LandTract::GetWidth() const
{
	return width;
}

FeetInches LandTract::GetArea() const
{
	return length * width;
}

bool LandTract::operator==(const LandTract& other) const
{
	return this->GetArea() == other.GetArea();
}

bool LandTract::operator!=(const LandTract& other) const
{
	return !(*this == other);
}
