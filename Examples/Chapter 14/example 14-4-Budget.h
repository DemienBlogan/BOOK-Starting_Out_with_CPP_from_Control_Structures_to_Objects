#ifndef BUDGET_H
#define BUDGET_H
#include "example 14-4-Auxil.h"

// Budget class declaration
class Budget
{
private:
	static double corpBugdet; // Static member variable
	double divisionBudget;    // Instance member variable
public:
	Budget()
	{ divisionBudget = 0; }

	void addBudget(double b)
	{ divisionBudget += b;
	  corpBugdet += b; }

	double getDivisionBudget() const
	{ return divisionBudget; }

	double getCorpBudget() const
	{ return corpBugdet; }

	// Static member function
	static void mainOffice(double); 

	// Friend function
	friend void AuxiliaryOffice::addBudget(double, Budget&);
};

#endif