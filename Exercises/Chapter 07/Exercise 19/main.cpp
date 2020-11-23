/*
19. Magic 8 Ball
Write a program that simulates a Magic 8 Ball, which is a fortune-telling toy that displays
a random response to a yes or no question. In the student sample programs for this book,
you will find a text file named 8_ball_responses.txt. The file contains 12 responses, such
as "I don't think so", "Yes, of course!", "I'm not sure", and so forth. The program
should read the responses from the file into an array or vector. It should prompt the
user to ask a question, and then display one of the responses, randomly selected from the
array or vector. The program should repeat until the user is ready to quit.

Contents of 8_ball_responses.txt
Yes, of course!
Without a doubt, yes.
You can count on it.
Ask me later.
I'm not sure.
I can't tell you right now.
I'll tell you after my nap.
No way!
I don't think so.
Without a doubt, no.
The answer is clearly NO.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

void OpenFile(std::ifstream& file, const std::string& fileName);
void CloseFile(std::ifstream& file);
void ReadAnswers(std::vector<std::string>& answers, std::ifstream& file);
std::string EnterQuestion();
void ShowAnswer(const std::vector<std::string>& answers);

int main()
{
	using namespace std;

	srand(static_cast<unsigned>(time(nullptr)));

	vector<string> answers;
	ifstream answersFile;
	string question;

	try
	{
		OpenFile(answersFile, "8_ball_responses.txt");
		ReadAnswers(answers, answersFile);
		question = EnterQuestion();

		while (question != "quit")
		{
			ShowAnswer(answers);
			question = EnterQuestion();
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	CloseFile(answersFile);

	return 0;
}

void OpenFile(std::ifstream& file, const std::string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		using namespace std;

		string errorMessage = "File '" + fileName + "' could not been opened.\n";
		throw std::exception(errorMessage.c_str());
	}
}

void CloseFile(std::ifstream& file)
{
	if (file.is_open())
		file.close();
}

void ReadAnswers(std::vector<std::string>& answers, std::ifstream& file)
{
	if (!answers.empty())
		answers.clear();

	using namespace std;

	string answer;

	while (getline(file, answer))
		answers.push_back(answer);
}

std::string EnterQuestion()
{
	using namespace std;

	cout << "Enter your question (or 'quit' to stop): ";
	string question;
	getline(cin, question);
	return question;
}

void ShowAnswer(const std::vector<std::string>& answers)
{
	using namespace std;

	int randAnswer = rand() % answers.size();
	cout << answers[randAnswer] << endl;
}