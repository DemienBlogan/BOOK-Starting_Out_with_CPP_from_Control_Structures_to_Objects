#pragma once

class GradedActivity
{
protected:
	double score; // To hold the numeric score

public:
	GradedActivity(double score = 0.0)
		: score(score)
	{ }

	void setScore(double s)
	{
		score = s;
	}

	// Accessor functions
	double getScore() const
	{
		return score;
	}

	virtual char getLetterGrade() const;
};