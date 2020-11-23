/*
17. Math Tutor
Write a program that can be used as a math tutor for a young student. The program
should display two random numbers to be ad ded, such as
 247
+129
 ---
The program should then pause while the student works on the problem. When the
student is ready to check the answer, he or she can press a key and the program will
display the correct solution:
 247
+129
 ---
 376
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	int num1 = rand() % 500, num2 = rand() % 500;
	int sum = num1 + num2;

	cout << setw(4) << num1 << endl;
	cout << "+";
	cout << setw(3) << num2 << endl;
	cout << "----";
	cin.get();
	cout << setw(4) << sum << endl;

	return 0;
}