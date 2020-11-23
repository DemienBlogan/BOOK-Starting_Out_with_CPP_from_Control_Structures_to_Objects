#ifndef BUDGET_H
#define BUDGET_H

// Budget class declaration
class Budget
{
private:
	static double corpBugdet; // Static member
	double divisionBudget;    // Instance member
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
};

// Definition of static member variable corpBudget.
double Budget::corpBugdet = 0;

#endif