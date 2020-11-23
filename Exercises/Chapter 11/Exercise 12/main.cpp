/*
12. Course Grade
Write a program that uses a structure to store the following data:
------------------------------------------------------------
Member Name               Description
------------------------------------------------------------
Name                      Student name
Idnum                     Student ID number
Tests                     Pointer to an array of test scores
Average                   Average test score
Grade                     Course grade
------------------------------------------------------------

The program should keep a list of test scores for a group of students. It should ask the
user how many test scores there are to be and how many students there are. It should
then dynamically allocate an array of structures. Each structure's Tests member
should point to a dynamically allocated array that will hold the test scores.

After the arrays have been dynamically allocated, the program should ask for the ID
number and all the test scores for each student. The average test score should be calculated
and stored in the average member of each structure. The course grade should
be computed on the basis of the basis of the following grading scale:
-----------------------------------------
Average Test Grade           Course Grade
-----------------------------------------
91 - 100                     A
81 - 90                      B
71 - 80                      C
61 - 70                      D
60 or below                  F
-----------------------------------------

The course grade should then be stored in the Grade member of each structure. Once
all this data is calculated, a table should be displayed on the screen listing each student's
name, ID number, average test score, and course grade.

Input Validation: Be sure all the data for each student is entered. Do not accept negative
numbers for any test score.
*/

#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string name;
	int id;
	double* tests;
	double average;
	char grade;
};

size_t EnterStudentsAmount();
size_t EnterTestsAmount();
Student* CreateStudentsList(size_t students, size_t tests);
void EnterStudentsInfo(Student list[], size_t students);
void EnterScores(Student list[], size_t students, size_t tests);
void CalculateAverages(Student list[], size_t students, size_t tests);
void ComputeCourseGrades(Student list[], size_t students);
void DeleteStudents(Student list[], size_t students);
void ShowStudentsList(const Student list[], size_t students, size_t tests);

int main()
{
	size_t students = EnterStudentsAmount();
	size_t tests = EnterTestsAmount();
	Student* list = CreateStudentsList(students, tests);

	EnterStudentsInfo(list, students);
	EnterScores(list, students, tests);
	CalculateAverages(list, students, tests);
	ComputeCourseGrades(list, students);
	ShowStudentsList(list, students, tests);

	DeleteStudents(list, students);

	return 0;
}

size_t EnterStudentsAmount()
{
	cout << "Enter amount of students: ";
	size_t students;
	cin >> students;

	return students;
}

size_t EnterTestsAmount()
{
	cout << "How many tests are there? ";
	size_t tests;
	cin >> tests;

	return tests;
}

Student* CreateStudentsList(size_t students, size_t tests)
{
	Student* list = new Student[students];

	for (size_t i = 0; i < students; i++)
		list[i].tests = new double[tests];

	return list;
}

void EnterStudentsInfo(Student list[], size_t students)
{
	for (size_t i = 0; i < students; i++)
	{
		cout << "Enter name for student #" << i + 1 << ": ";
		cin >> list[i].name;
		cout << "Enter ID of " << list[i].name << ": ";
		cin >> list[i].id;
	}
}

void EnterScores(Student list[], size_t students, size_t tests)
{
	for (size_t i = 0; i < students; i++)
	{
		cout << "Enter scores of tests of student #" << i + 1;
		cout << " (" << list[i].name << "):\n";

		for (size_t j = 0; j < tests; j++)
		{
			cout << "\t Test #" << j + 1 << ": ";

			do
			{
				cin >> list[i].tests[j];

				if (list[i].tests[j] < 0)
					cout << "Incorrect score. Try again.\n";

			} while (list[i].tests[j] < 0);
		}
	}
}

void CalculateAverages(Student list[], size_t students, size_t tests)
{
	for (size_t i = 0; i < students; i++)
	{
		double sum = 0;

		for (size_t j = 0; j < tests; j++)
			sum += list[i].tests[j];

		list[i].average = sum / tests;
	}
}

void ComputeCourseGrades(Student list[], size_t students)
{
	for (size_t i = 0; i < students; i++)
	{
		double average = list[i].average;

		if (average >= 91 && average <= 100)
			list[i].grade = 'A';
		else if (average >= 81 && average <= 91)
			list[i].grade = 'B';
		else if (average >= 71 && average <= 80)
			list[i].grade = 'C';
		else if (average >= 61 && average <= 70)
			list[i].grade = 'D';
		else
			list[i].grade = 'F';
	}
}

void DeleteStudents(Student list[], size_t students)
{
	for (size_t i = 0; i < students; i++)
		delete[] list[i].tests;
	delete[] list;
}

void ShowStudentsList(const Student list[], size_t students, size_t tests)
{
	for (size_t i = 0; i < students; i++)
	{
		cout << "Student #" << i + 1 << ":\n";
		cout << "\t Name: " << list[i].name << endl;
		cout << "\t ID: " << list[i].id << endl;

		cout << "\tTest scores: ";
		for (size_t j = 0; j < tests; j++)
			cout << list[i].tests[j] << " ";
		cout << endl;

		cout << "\t Average: " << list[i].average << endl;
		cout << "\t grade: " << list[i].grade << "\n\n";
	}
}