#pragma once

class BankAccount
{
protected:
	double balance;
	int depositsNumber;
	int withdrawalsNumber;
	double interestRate;
	double serviceCharges;

public:
	BankAccount(double balance, double interestRate);

	virtual void deposit(double money);
	virtual void withdraw(double money);
	virtual void calcInt();
	virtual void monthlyProc();

	double GetBalance() const;
	int GetDepositsNumber() const;
	int GetWithdrawalsNumber() const;
	double GetInterestRate() const;
	double GetServiceCharges() const;
};

class SavingsAccount final : public BankAccount
{
private:
	bool status;

public:
	SavingsAccount(double balance, double interestRate);

	virtual void deposit(double money) override final;
	virtual void withdraw(double money) override final;
	virtual void monthlyProc() override final;
};

class CheckingAccount final : public BankAccount
{
public:
	CheckingAccount(double balance, double interestRate);

	virtual void withdraw(double money);
	virtual void monthlyProc();
};