#ifndef FEETINCHES_H
#define FEETINCHES_H

#include <iostream>
using namespace std;

class FeetInches; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream& operator<<(ostream&, const FeetInches&);
istream& operator>>(istream&, FeetInches&);

// The FeetInches class holds distances or measurements
// expressed in feet and inches.

class FeetInches
{
private:
	int feet;        // To hold a number of feet
	int inches;      // To hold a numbe rof inches
	void simplify(); // Defined in FeetInches.cpp
public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& other)
		: feet(other.feet), inches(other.inches)
	{ }

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	// Overloaded operator functions
	FeetInches operator+(const FeetInches&);  // Overloaded +
	FeetInches operator-(const FeetInches&);  // Overloaded -
	FeetInches operator++();                  // Prefix ++
	FeetInches operator++(int);               // Postfix++
	bool operator>(const FeetInches& right);  // Overloaded >
	bool operator<(const FeetInches& right);  // Overloaded <
	bool operator==(const FeetInches& right); // Overloaded ==
	bool operator<=(const FeetInches& right);
	bool operator>=(const FeetInches& right);
	bool operator!=(const FeetInches& right);
	FeetInches operator*(const FeetInches& other) const;

	// Friends
	friend ostream& operator<<(ostream&, const FeetInches&);
	friend istream& operator>>(istream&, FeetInches&);
};

#endif