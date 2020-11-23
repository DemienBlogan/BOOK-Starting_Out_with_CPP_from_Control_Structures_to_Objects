#pragma once

#include "GradedActivity.h"

class Essay : public GradedActivity
{
private:
	int grammarScore;
	int spellingScore;
	int correctLengthScore;
	int contentScore;

public:
	Essay();
	void AddGrammarPoints(int points);
	void AddSpellingPoints(int points);
	void AddCorrectLengthPoints(int points);
	void AddContentPoints(int points);
};