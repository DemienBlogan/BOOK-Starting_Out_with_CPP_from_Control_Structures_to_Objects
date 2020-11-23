#pragma once

#include <string>

using std::string;

class Question
{
private:
	string question;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	int correctAnswerNumber;

public:
	Question(const string& question, const string& answer1, const string& answer2,
		const string& answer3, const string& answer4, int correctAnswerNumber)
		: question(question), answer1(answer1), answer2(answer2), answer3(answer3),
		answer4(answer4), correctAnswerNumber(correctAnswerNumber)
	{ }

	const string& GetQuestion() const { return question; }
	const string& GetAnswer1() const { return answer1; }
	const string& GetAnswer2() const { return answer2; }
	const string& GetAnswer3() const { return answer3; }
	const string& GetAnswer4() const { return answer4; }
	int GetCorrectAnswerNumber() const { return correctAnswerNumber; }
};