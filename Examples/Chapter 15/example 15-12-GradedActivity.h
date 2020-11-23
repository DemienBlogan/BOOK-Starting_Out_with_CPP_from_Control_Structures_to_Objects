#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

// Graded Activity class declaration

class GradedActivity
{
protected:
	double score; // To hold the numeric score
public:
	// Default constructor
	GradedActivity()
	{ score = 0.0; }

	// Constrctor
	GradedActivity(double s)
	{ score = s; }

	// Mutator function
	void setScore(double s)
	{ score = s; }

	// Accessor functions
	double getScore() const
	{ return score;	}

	virtual char getLetterGrade() const;
};
#endif