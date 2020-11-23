#pragma once

#include "PatientAccount.h"

class Surgery
{
private:
	double bariatricSurgeryCharges;
	double breastSurgeryCharges;
	double colonRectalSurgeryCharges;
	double endocrineSurgeryCharges;
	double gynecologicalSurgeryCharges;

public:
	Surgery(double bariatricSurgeryCharges = 750.00,
		double breastSurgeryCharges = 940.00,
		double colonRectalSurgeryCharges = 130.00,
		double EndocrineSurgeryCharges = 540.00,
		double gynecologicalSurgeryCharges = 200.00);

	enum class SurgeryType
	{
		BARIATRIC,
		BREAST,
		COLON_AND_RECTAL,
		ENDOCRINE,
		GYNECOLOGICAL
	};

	void AddCharges(PatientAccount& account, SurgeryType surgeryType) const;
};