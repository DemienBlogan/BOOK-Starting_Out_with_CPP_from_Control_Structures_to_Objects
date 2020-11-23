#pragma once

#include <cmath>

class Payment
{
private:
	double payment;
	double loan;
	double rate;
	double term;
	int years;

	void CalculateTerm()
	{
		term = pow(1 + rate / 12, 12 * years);
	}

	void CalculatePayment()
	{
		payment = (loan * (rate / 12.0) * term) / (term - 1);
	}

public:
	Payment(double payment = 0.0, double loan = 0.0, double rate = 0.0, double term = 0.0, int years = 0.0)
		: payment(0.0), loan(0.0), rate(0.0), term(0.0), years(0.0)
	{ }

	void SetLoan(double loan)
	{
		if (loan >= 0)
		{
			this->loan = loan;
			CalculateTerm();
			CalculatePayment();
		}
	}

	void SetRate(double rate)
	{
		if (rate >= 0)
		{
			this->rate = rate;
			CalculateTerm();
			CalculatePayment();
		}
	}

	void SetYears(int years)
	{
		if (years >= 0)
		{
			this->years = years;
			CalculateTerm();
			CalculatePayment();
		}
	}

	double GetPayment() const { return payment; }
	double GetLoan() const { return loan; }
	double GetRate() const { return rate; }
	double GetTerm() const { return term; }
	int GetYears() const { return years; }
};