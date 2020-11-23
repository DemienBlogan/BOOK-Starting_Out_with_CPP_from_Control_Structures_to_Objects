#pragma once

#include "InventoryItem.h"

class CashRegister
{
private:
	InventoryItem item;

public:
	CashRegister(string desc, double c, int u)
		: item(desc, c, u)
	{ }

	void AddProfit() { item.setCost(item.getCost() + item.getCost() * 0.30); }

	double GetCost() const { return item.getCost(); }
	double GetPurchaseSubtotal() const { return item.getCost() * item.getUnits(); }
	double GetSalesTax() const { return GetPurchaseSubtotal() * 0.06; }

	void Show() const;
	void EnterQuantity();
};