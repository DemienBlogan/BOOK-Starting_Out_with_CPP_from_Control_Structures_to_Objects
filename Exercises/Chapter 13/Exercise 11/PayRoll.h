#pragma once

class PayRoll
{
private:
	double payRate;
	int hours;
	double totalPay;

	void CalculateGrossPay() { totalPay = payRate * hours; }

public:
	PayRoll()
		: payRate(0.0), hours(0), totalPay(0.0)
	{ }

	void SetHours(int hours)
	{
		if (hours >= 0 && hours <= 60)
		{
			this->hours = hours;
			CalculateGrossPay();
		}
	}

	void SetPayRate(double payRate) 
	{ 
		this->payRate = payRate;
		CalculateGrossPay();
	}

	double GetPayRate() const { return payRate; }
	int GetHours() const { return hours; }
	double GetTotalPay() const { return totalPay; }
};