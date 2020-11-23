#include "TeamLeader.h"

TeamLeader::TeamLeader(
	const string& name,
	int number,
	const string& hireDate,
	int shift,
	double hourlyPayRate,
	double monthlyBonus,
	int requiredTrainingHours,
	int attendedTrainingHours)
	: ProductionWorker(name, number, hireDate, shift, hourlyPayRate),
	monthlyBonus(monthlyBonus),
	requiredTrainingHours(requiredTrainingHours),
	attendedTrainingHours(attendedTrainingHours)
{ }

void TeamLeader::SetMonthlyBonus(double monthlyBonus)
{
	this->monthlyBonus = monthlyBonus;
}

void TeamLeader::SetRequiredTrainingHours(int requiredTrainingHours)
{
	this->requiredTrainingHours = requiredTrainingHours;
}

void TeamLeader::SetAttendedTrainingHours(int attendedTrainingHours)
{
	this->attendedTrainingHours = attendedTrainingHours;
}

double TeamLeader::GetMonthlyBonus() const
{
	return monthlyBonus;
}

int TeamLeader::GetRequiredTrainingHours() const
{
	return requiredTrainingHours;
}

int TeamLeader::GetAttendedTrainingHours() const
{
	return attendedTrainingHours;
}