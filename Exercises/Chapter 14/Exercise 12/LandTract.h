#pragma once

#include "FeetInches.h"

class LandTract
{
private:
	FeetInches length;
	FeetInches width;

public:
	LandTract(const FeetInches& length = FeetInches(), const FeetInches& width = FeetInches());
	void SetLength(const FeetInches& length);
	void SetWidth(const FeetInches& width);
	FeetInches GetLength() const;
	FeetInches GetWidth() const;
	FeetInches GetArea() const;
	bool operator==(const LandTract& other) const;
	bool operator!=(const LandTract& other) const;
};