#include "example 14-4-Budget.h"

// Definition of static member variable corpBudget.
double Budget::corpBugdet = 0;

//*********************************************************
// Definition of static member function mainOffice.       * 
// This function adds the main office's budget request to *
// the corpBudget variable.                               *
//*********************************************************

void Budget::mainOffice(double moffice)
{
	corpBugdet += moffice;
}