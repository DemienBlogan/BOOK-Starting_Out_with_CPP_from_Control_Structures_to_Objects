/*
10. Driver's License Exam
The local Driver's License Office has asked you to write a program that grades the
written portion of the driver's license exam. The exam has 20 multiple-choice questions.
Here are the correct answers:

1. A	6. B	11. A	16. C
2. D	7. A	12. C	17. C
3. B	8. B	13. D	18. A
4. B	9. C	14. B	19. D
5. C	10. D	15. D	20. B

Your program should store the correct answers shown above in an array. It should ask the
user to enter the student's answers for each of the 20 questions, and the answers should
be stored in another array. After the student's answers have been entered, the program
should display a message indicating whether the student passed of failed the exam.
(A student must correctly answer 15 of the 20 questions to pass the exam). It should then
display the total number of correctly answered questions, the total number of incorrectly
answered questions, and a list showing the question numbers of the incorrectly answered
questions.

Input Validation: Only accept the letters A, B, C, or D as answers.
*/
#include <iostream>

int main()
{
	using namespace std;

	const size_t SIZE = 20;
	char rightAnswers[SIZE] =
	{
		'A', 'D', 'B', 'B', 'C',
		'B', 'A', 'B', 'C', 'D',
		'A', 'C', 'D', 'B', 'D',
		'C', 'C', 'A', 'D', 'B'
	};

	char userAnswers[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ". ";
		cin >> userAnswers[i];

		if (userAnswers[i] < 'A' || userAnswers[i] > 'D')
		{
			cout << "Incorrect letter. Try again.\n";
			i--;
		}
	}

	int grade = 0;

	for (size_t i = 0; i < SIZE; i++)
		if (rightAnswers[i] == userAnswers[i])
			grade++;

	cout << "Answers:\n";
	for (size_t i = 0; i < SIZE; i++)
		cout << i + 1 << ". Correct = " << rightAnswers[i] << " (your = " << userAnswers[i] << ")\n";

	cout << "Grade: " << grade << "/20.\n";

	if (grade >= 15)
		cout << "You pass the exam.\n";
	else
		cout << "You didn't pass the exam.\n";

	return 0;
}