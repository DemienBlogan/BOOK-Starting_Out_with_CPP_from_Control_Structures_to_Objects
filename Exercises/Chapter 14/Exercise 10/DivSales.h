#pragma once

class DivSales
{
private:
	double quarters[4];

	static double totalSales;

public:
	DivSales();
	void SetSales(double sale1, double sale2, double sale3, double sale4);
	double GetQuarter(int index) const;
	static double GetTotalSales();
};