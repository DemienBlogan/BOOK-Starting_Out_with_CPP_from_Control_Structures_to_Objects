/*
19. Trivia Game
In this programming challenge, you will create a simple trivia game for two players.
The program will work like this:
- Starting with player 1, each player gets a turn at answering five trivia questions.
  (There are a total of 10 questions). When a question is displayed, four possible
  answers are also displayed. Only one of the answers is correct, and if the player
  selects the correct answer, he or she earns a point.
- After answers have been selected for all of the questions, the program displays the
  number of points earned by each player and declares the player with the highest
  number of points the winner.

In this program, you will design a Question class to hold the data for a trivia question.
The Question class should have member variables for the following data:
- A trivia question
- Possible answer #1
- Possible answer #2
- Possible answer #3
- Possible answer #4
- The number of the correct answer (1, 2, 3, or 4)

The Question class should have appropriate constructor(s), accessor, and mutator
functions.

The program should create an array of 10 Question objects, one for each trivia question.
Make up your own trivia questions on the subject or subjects of your choice for
the objects.
*/

#include <iostream>

#include "Question.h"

using std::cout;
using std::cin;
using std::endl;

void ShowQuestion(const Question& question);
int AnswerQuestion(const Question& question);
void ShowWinner(int player1Points, int player2Points);
void AskPlayer(const Question questions[], size_t questionAmount, int& playerPoints, int playerNumber);

int main()
{
	const size_t QUESTION_AMOUNT = 10;
	Question questions[QUESTION_AMOUNT] =
	{
		{ "1 + 1 = ?", "1", "2", "3", "4", 2 },
		{ "What language do you learn?", "English", "Russian", "C++", "C#", 3 },
		{ "How many planets does Earth have?", "3", "5", "6", "9", 4 },
		{ "How many fingers does a human have?", "5", "10", "15", "20", 2 },
		{ "10 + 5 = ?", "10", "5", "15", "51", 3 },
		{ "That's the number of this exercise?", "6", "12", "5", "19", 4 },
		{ "Am I feeling loneliness at this moment?", "Yes", "No", "Ask your friends", "...", 1 },
		{ "How many girls have I fallen in love?", "9", "8", "7", "6", 1 },
		{ "How strong my heart is broken?", "20%", "50%", "75%", "100%", 4 },
		{ "How long have I been doing this exercises?", "1 day", "5 days", "a few months", "year", 3 },
	};

	int player1Points = 0;
	int player2Points = 0;

	AskPlayer(questions, QUESTION_AMOUNT, player1Points, 1);
	AskPlayer(questions, QUESTION_AMOUNT, player2Points, 2);

	ShowWinner(player1Points, player2Points);

	return 0;
}


void ShowQuestion(const Question& question)
{
	cout << question.GetQuestion() << endl;
	cout << "1) " << question.GetAnswer1() << endl;
	cout << "2) " << question.GetAnswer2() << endl;
	cout << "3) " << question.GetAnswer3() << endl;
	cout << "4) " << question.GetAnswer4() << endl;
}

int AnswerQuestion(const Question& question)
{
	int answer;

	do
	{
		cout << "Enter the answer: ";
		cin >> answer;

		if (answer != 1 && answer != 2 && answer != 3 && answer != 4)
		{
			system("cls");
			cout << "Incorrect number. Try again.\n";
		}

	} while (answer != 1 && answer != 2 && answer != 3 && answer != 4);

	return answer == question.GetCorrectAnswerNumber() ? 1 : 0;
}

void ShowWinner(int player1Points, int player2Points)
{
	cout << "Player #1 points = " << player1Points << endl;
	cout << "Player #2 points = " << player2Points << endl;

	if (player1Points > player2Points)
		cout << "Player #1 WIN!\n";
	else if (player1Points < player2Points)
		cout << "Player #2 WIN!\n";
	else
		cout << "DRAW!\n";
}

void AskPlayer(const Question questions[], size_t questionAmount, int& playerPoints, int playerNumber)
{
	cout << "Player #" << playerNumber << " turn:\n";
	for (size_t i = 0; i < questionAmount; i++)
	{
		cout << "Question #" << i + 1 << ":\n";
		ShowQuestion(questions[i]);
		playerPoints += AnswerQuestion(questions[i]);
		system("cls");
	}
}