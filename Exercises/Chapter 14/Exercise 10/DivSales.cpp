#include "DivSales.h"

double DivSales::totalSales = 0.0;

DivSales::DivSales()
	: quarters{}
{ }

void DivSales::SetSales(double sale1, double sale2, double sale3, double sale4)
{
	if (sale1 < 0 || sale2 < 0 || sale3 < 0 || sale4 < 0)
		return;

	quarters[0] = sale1;
	quarters[1] = sale2;
	quarters[2] = sale3;
	quarters[3] = sale4;

	for (size_t i = 0; i < 4; i++)
		totalSales += quarters[i];
}

double DivSales::GetTotalSales()
{
	return totalSales;
}

double DivSales::GetQuarter(int index) const
{
	return index >= 0 && index < 4 ? quarters[index] : 0.0;
}
