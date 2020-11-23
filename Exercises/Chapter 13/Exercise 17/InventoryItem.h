#pragma once

#include <string>

using std::string;

class InventoryItem
{
private:
	string description;
	double cost;
	int units;

public:

	InventoryItem()
		: description(""), cost(0.0), units(0)
	{ }

	InventoryItem(string desc)
		: description(desc), cost(0.0), units(0)
	{ }

	InventoryItem(string desc, double c, int u)
		: description(desc), cost(c), units(u)
	{ }

	void setDescription(string d) { description = d; }

	void setCost(double c) { cost = c; }

	void setUnits(int u) { units = u; }

	string getDescription() const { return description; }

	double getCost() const { return cost; }

	int getUnits() const { return units; }
};