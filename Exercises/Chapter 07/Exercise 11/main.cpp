/*
11. Exam Grader
One of your professors has asked you to write a program to grade her final exams, which
consist of only 20 multiple-choice questions. Each question has one of four possible
answers: A, B, C, or D. The file CorrectAnswers.txt contains the correct answers for all
of the questions, with each answer, written on a separate line. The first line contains the
answer to the first question, the second line contains the answer to the second question,
and so forth. (Download the book's source code form the Computer Scirence Portal at
www.personhighered.com/gaddis. You will find the file in the Chapter 07 folder).

Write a program that reads the contents of the CorrectAnswers.txt into a char
array, then reads the contents of another file, containing a student's answers, into a
second char array. (You can use the file StudentAnswers.txt for testing purposes. This
file is also in the Chapter 07 source code folder). The program should determine the
number of questions that the student missed, then display the following:

- A list of the questions missed by the student, showing the correct answer and the
  incorrect answer provided by the student for each missed question
- The total number of questions missed
- The percentage of questions answered correctly. This can be calculated as
  Correctly Answered Questions / Total Number of Questions
- If the percentage of correctly answered questions is 70 percent or greater, the program
  should indicate that the student passed the exam. Otherwise, it should indicate
  that the student failed the exam.
*/

#include <iostream>
#include <fstream>

int main()
{
	using namespace std;

	ifstream correctAnswersFile("CorrectAnswers.txt");
	ifstream userAnswersFile("UserAnswers.txt");

	if (!correctAnswersFile)
	{
		cout << "Error. File 'CorrectAnswers.txt' could not been opened.\n";
		return 1;
	}

	if (!userAnswersFile)
	{
		cout << "Error. File 'UserAnswers.txt' could not been opened.\n";
		return 2;
	}

	const size_t SIZE = 20;
	char correctAnswers[SIZE], userAnswers[SIZE];

	for (size_t i = 0; i < SIZE; i++)
	{
		correctAnswersFile >> correctAnswers[i];
		userAnswersFile >> userAnswers[i];
	}

	int missedQuestions = 0;

	cout << "The list of the questions missed by student:\n";
	for (size_t i = 0; i < SIZE; i++)
	{
		if (correctAnswers[i] != userAnswers[i])
		{
			cout << i + 1 << " ";
			missedQuestions++;
		}
	}
	cout << endl;

	cout << "The total number of questions missed: " << missedQuestions << endl;

	double correctAnswersPercentage = (SIZE - missedQuestions) * 100.0 / SIZE;

	cout << "The perentage of questions answered correctly: %";
	cout << correctAnswersPercentage << endl;

	if (correctAnswersPercentage >= 70)
		cout << "You pass the exam.\n";
	else
		cout << "You didn't pass the exam.\n";

	correctAnswersFile.close();
	userAnswersFile.close();

	return 0;
}