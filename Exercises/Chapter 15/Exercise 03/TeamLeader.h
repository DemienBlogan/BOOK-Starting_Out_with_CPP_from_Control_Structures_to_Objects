#pragma once

#include "ProductionWorker.h"

class TeamLeader : public ProductionWorker
{
private:
	double monthlyBonus;
	int requiredTrainingHours;
	int attendedTrainingHours;

public:
	TeamLeader(
		const string& name = "NoName",
		int number = 0,
		const string& hireDate = "0/0/0",
		int shift = 1,
		double hourlyPayRate = 0,
		double monthlyBonus = 0,
		int requiredTrainingHours = 0,
		int attendedTrainingHours = 0);

	void SetMonthlyBonus(double monthlyBonus);
	void SetRequiredTrainingHours(int requiredTrainingHours);
	void SetAttendedTrainingHours(int attendedTrainingHours);

	double GetMonthlyBonus() const;
	int GetRequiredTrainingHours() const;
	int GetAttendedTrainingHours() const;
};