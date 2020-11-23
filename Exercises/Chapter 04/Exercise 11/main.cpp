/*
11. Math Tutor
This is a modification of Programming Challenge 17 from Chapter 3. Write  program
that can be used as a math tutor for a young student. The program should display two
random numbers that are to be added, such as:
 247
+129
----
The program should wait for the student to enter the answer. If the answer is correct,
a message of congratulations should be printed. If the answer is incorrect, a message
should be printed showing the correct answer.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	int number1 = rand() % 500;
	int number2 = rand() % 500;
	int sum = number1 + number2;

	cout << " " << setw(3) << number1 << endl;
	cout << "+" << setw(3) << number2 << endl;
	cout << "----\n";

	int answer;
	cin >> answer;

	if (answer == sum)
		cout << "\nRight answer!\n";
	else
		cout << "\nWrong answer!\n";

	return 0;
}