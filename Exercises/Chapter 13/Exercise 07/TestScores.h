#pragma once

class TestScores
{
private:
	double score1;
	double score2;
	double score3;

public:
	TestScores(double score1, double score2, double score3)
		: score1(score1), score2(score2), score3(score3)
	{ }

	void SetScore1(double score1) { this->score1 = score1; }
	void SetScore2(double score2) { this->score2 = score2; }
	void SetScore3(double score3) { this->score3 = score3; }

	double GetScore1() const { return score1; }
	double GetScore2() const { return score2; }
	double GetScore3() const { return score3; }
	double GetAverage() const { return (score1 + score2 + score3) / 3.0; }
};