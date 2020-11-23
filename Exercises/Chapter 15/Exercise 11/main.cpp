/*
11. Course Grades
In a course, a teacher gives the following tests and assignmentes:

- A lbad activity that is observed by the teacher and assigned a numeric score.
- A pass/fail exam that has tem questions. The minimum passing score is 70.
- An essay that is assigned a numeric score.
- A final exam that has 50 questions.

Write a class named CourseGrades. The class should have a member named grades
that is an array of GradedActivity pointers. The grades array should have four elements,
one for each of the assignments previously described. The class should have the
following member functions:

setLab:          The function should accept the address of a GradedActivity
                 object as its argument. This object should already hold the student's
                 score for the lab activityt. Element 0 of the grades array
setPassFailExam: This function should accept the address of a PassFailExam
                 object as its argument. This object should already hold the student's
                 score for the pass/fail exam. Element 1 of the grades array
                 should reference this object.
setEssay:        This function should accept the address of an Essay object
                 as its argument. (See Programming Challenge 6 for the Essay
                 class. If you have not completed Programming Challenge 6, use
                 a GradedActivity object instead). This object should already
                 hold the student's score for the essay. Element 2 of the grades
                 array should reference this object.
setPassFailExam: This function should accept the address of a FinalExam object
                 as its argument. This object should already hold the student's
                 score for the final exam. Element 3 of the grades array should
                 reference this object.
print:           This function should display the numeric scores and grades for
                 each element in the grades array.

Demonstrate the class in a program.
*/

#include "CourseGrades.h"
#include "GradedActivity.h"

int main()
{
    CourseGrades course;

    GradedActivity lab{ 23.5 };
    GradedActivity passFailExam{ 83.2 };
    GradedActivity essay{ 95.3 };
    GradedActivity finalExam{ 99.7 };

    course.setLab(&lab);
    course.setPassFailExam(&passFailExam);
    course.setEssay(&essay);
    course.setFinalExam(&finalExam);

    course.print();

    return 0;
}