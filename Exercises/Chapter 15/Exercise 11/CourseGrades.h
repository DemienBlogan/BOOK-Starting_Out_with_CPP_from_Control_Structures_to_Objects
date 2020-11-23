#pragma once
#include "GradedActivity.h"

class CourseGrades
{
private:
	GradedActivity* activities[4];

public:
	void setLab(GradedActivity* const lab);
	void setPassFailExam(GradedActivity* const exam);
	void setEssay(GradedActivity* const essay);
	void setFinalExam(GradedActivity* const exam);
	void print() const;
};

