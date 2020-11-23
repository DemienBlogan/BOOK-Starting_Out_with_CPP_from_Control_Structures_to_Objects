/*
6. Essay Class
Design an Essay class that is dervied from the GradedActivity class presented in this
chapter. The Essay class should determine the grade a student receives on an essay.
The student's essay score can be up to 100, and is determined in the following manner:

- Grammar: 30 points
- Spelling: 20 points
- Correct length: 20 points
- Content: 30 points

Demonstrate the class in a simple program
*/

#include <iostream>

#include "Essay.h"

using std::cout;
using std::endl;

int main()
{
	Essay essay;

	essay.AddGrammarPoints(18);
	essay.AddSpellingPoints(5);
	essay.AddCorrectLengthPoints(19);
	essay.AddContentPoints(24);

	cout << "Total score = " << essay.getScore() << endl;
	cout << "Grade = " << essay.getLetterGrade() << endl;

	return 0;
}