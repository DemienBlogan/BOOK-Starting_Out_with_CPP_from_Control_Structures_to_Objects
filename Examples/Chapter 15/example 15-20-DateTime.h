// Specification file for the Date Time class
#ifndef DATETIME_H
#define DATETIME_H
#include <string>
#include "example 15-20-Date.h"
#include "example 15-20-Time.h"
using namespace std;

class DateTime : public Date, public Time
{
public:
	// Default constructor
	DateTime();

	// Constructor
	DateTime(int, int, int, int, int, int);

	// The showDateTime function displays the
	// date and the time.
	void showDateTime() const;
};
#endif