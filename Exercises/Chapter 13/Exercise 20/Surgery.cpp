#include "Surgery.h"

Surgery::Surgery(double bariatricSurgeryCharges,
	double breastSurgeryCharges,
	double colonRectalSurgeryCharges,
	double endocrineSurgeryCharges,
	double gynecologicalSurgeryCharges)
	: bariatricSurgeryCharges(0),
	breastSurgeryCharges(0),
	colonRectalSurgeryCharges(0),
	endocrineSurgeryCharges(0),
	gynecologicalSurgeryCharges(0)
{
	if (bariatricSurgeryCharges > 0)
		this->bariatricSurgeryCharges = bariatricSurgeryCharges;

	if (breastSurgeryCharges > 0)
		this->breastSurgeryCharges = breastSurgeryCharges;

	if (colonRectalSurgeryCharges > 0)
		this->colonRectalSurgeryCharges = colonRectalSurgeryCharges;

	if (endocrineSurgeryCharges > 0)
		this->endocrineSurgeryCharges = endocrineSurgeryCharges;

	if (gynecologicalSurgeryCharges > 0)
		this->gynecologicalSurgeryCharges = gynecologicalSurgeryCharges;
}

void Surgery::AddCharges(PatientAccount& account, SurgeryType surgeryType) const
{
	switch (surgeryType)
	{
	case Surgery::SurgeryType::BARIATRIC:
		account.AddCharges(bariatricSurgeryCharges);
		break;
	case Surgery::SurgeryType::BREAST:
		account.AddCharges(breastSurgeryCharges);
		break;
	case Surgery::SurgeryType::COLON_AND_RECTAL:
		account.AddCharges(colonRectalSurgeryCharges);
		break;
	case Surgery::SurgeryType::ENDOCRINE:
		account.AddCharges(endocrineSurgeryCharges);
		break;
	case Surgery::SurgeryType::GYNECOLOGICAL:
		account.AddCharges(gynecologicalSurgeryCharges);
		break;
	}
}