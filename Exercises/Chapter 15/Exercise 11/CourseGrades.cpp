#include <iostream>
#include "CourseGrades.h"

using std::cout;
using std::endl;

void CourseGrades::setLab(GradedActivity* const lab)
{
	activities[0] = lab;
}

void CourseGrades::setPassFailExam(GradedActivity* const exam)
{
	activities[1] = exam;
}

void CourseGrades::setEssay(GradedActivity* const essay)
{
	activities[2] = essay;
}

void CourseGrades::setFinalExam(GradedActivity* const exam)
{
	activities[3] = exam;
}

void CourseGrades::print() const
{
	cout << "--- Lab Activity --- \n";
	cout << "Score: " << activities[0]->getScore() << endl;
	cout << "Grade: " << activities[0]->getLetterGrade() << endl;

	cout << "--- Pass/Fail Exam --- \n";
	cout << "Score: " << activities[1]->getScore() << endl;
	cout << "Grade: " << activities[1]->getLetterGrade() << endl;

	cout << "--- Essay --- \n";
	cout << "Score: " << activities[2]->getScore() << endl;
	cout << "Grade: " << activities[2]->getLetterGrade() << endl;

	cout << "--- Final Exam --- \n";
	cout << "Score: " << activities[3]->getScore() << endl;
	cout << "Grade: " << activities[3]->getLetterGrade() << endl;
}