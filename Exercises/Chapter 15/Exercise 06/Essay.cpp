#include "Essay.h"

Essay::Essay()
	: GradedActivity(),
	grammarScore(0),
	spellingScore(0),
	correctLengthScore(0),
	contentScore(0)
{ }

void Essay::AddGrammarPoints(int points)
{
	if (points > 0 && points + grammarScore <= 30)
	{
		grammarScore += points;
		score += grammarScore;
	}
}

void Essay::AddSpellingPoints(int points)
{
	if (points > 0 && points + spellingScore <= 20)
	{
		spellingScore += points;
		score += spellingScore;
	}
}

void Essay::AddCorrectLengthPoints(int points)
{
	if (points > 0 && points + correctLengthScore <= 20)
	{
		correctLengthScore += points;
		score += correctLengthScore;
	}
}

void Essay::AddContentPoints(int points)
{
	if (points > 0 && points + contentScore <= 30)
	{
		contentScore += points;
		score += contentScore;
	}
}