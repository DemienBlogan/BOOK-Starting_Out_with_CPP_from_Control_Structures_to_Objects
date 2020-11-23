#pragma once
#include <string>

using std::string;

class Ship
{
private:
	string name;
	string builtYear;

public:
	Ship(const string& name, const string& builtYear);

	void SetName(const string& name);
	void SetBuiltYear(const string& builtYear);

	string GetName() const;
	string GetBuiltYear() const;

	virtual void print() const;
};

class CruiseShip : public Ship
{
private:
	int maxPassengers;

public:
	CruiseShip(const string& name, const string& builtYear, int maxPassengers);

	void SetMaxPassengers(int maxPassengers);
	int GetMaxPassengers() const;

	virtual void print() const override;
};

class CargoShip : public Ship
{
private:
	int cargoCapacity;

public:
	CargoShip(const string& name, const string& builtYear, int cargoCapacity);

	void SetCargoCapacity(int cargoCapacity);
	int GetCargoCapacity() const;

	virtual void print() const override;
};