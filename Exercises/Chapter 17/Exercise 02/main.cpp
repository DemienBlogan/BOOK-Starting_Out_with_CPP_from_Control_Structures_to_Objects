/*
2. Course Information
Write a program that creates a map containing course numbers and the room numbers
of the rooms where the courses meet. The map should have the following key-value
pairs:

----------------------------------------------------
Course Number (Key)              Room Number (Value)
----------------------------------------------------
CS101                            3004
CS102                            4501
CS103                            6755
NT110                            1244
CM241                            1411
----------------------------------------------------

The program should also create a map containing course numbers and the names of the
instructors that teach each course.The map should have the following key-value pairs:

----------------------------------------------------
Course Number (Key)              Instructor (Value)
----------------------------------------------------
CS101                            Haynes
CS102                            Alvarado
CS103                            Rich
NT110                            Burke
CM241                            Lee
----------------------------------------------------

The program should let the user enter a course number, then it should display the
course's room number, instructor, and meeting time.
*/

#include <iostream>
#include <map>
#include <string>

using std::map;
using std::string;
using std::make_pair;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	map<string, int> roomNumbers
	{
		make_pair("CS101", 3004),
		make_pair("CS102", 4501),
		make_pair("CS103", 6755),
		make_pair("NT110", 1244),
		make_pair("CM241", 1411)
	};

	map<string, string> instructors
	{
		make_pair("CS101", "Haynes"),
		make_pair("CS102", "Alvarado"),
		make_pair("CS103", "Rich"),
		make_pair("NT110", "Burke"),
		make_pair("CM241", "Lee")
	};

	cout << "Enter course number: ";
	string courseNumber;
	cin >> courseNumber;

	auto findCourseIterator = roomNumbers.find(courseNumber);

	if (findCourseIterator != roomNumbers.cend())
	{
		cout << "Room: " << roomNumbers[findCourseIterator->first] << endl;
		cout << "Instructor: " << instructors[findCourseIterator->first] << endl;
	}
	else
		cout << "This course doesn't exist.\n";

	return 0;
}