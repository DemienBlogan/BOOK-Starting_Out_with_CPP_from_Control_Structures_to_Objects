#include "example 15-9-PassFailActivity.h"

//****************************************************
// Member function PassFailActivity::getLetterGrade  *
// This function returs 'P' if the score is passing, *
// otherwise if returns 'F'.                         *
//****************************************************

char PassFailActivity::getLetterGrade() const
{
	char letterGrade;

	if (score >= minPassingScore)
		letterGrade = 'P';
	else
		letterGrade = 'F';

	return letterGrade;
}