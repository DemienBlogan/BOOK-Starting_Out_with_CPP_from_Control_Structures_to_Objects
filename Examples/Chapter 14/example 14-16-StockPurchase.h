#ifndef STOCK_PURCHASE
#define STOCK_PURCHASE
#include "example 14-16-Stock.h"

class StockPurchase
{
private:
	Stock stock; // The stock that was puchased
	int shares;  // The number of shares
public:
	// The default constructor sets shares to 0. The stock
	// object is initialized by its default constructor.
	StockPurchase()
	{ shares= 0; }

	// Constructor
	StockPurchase(const Stock& stockObject, int numShares)
	{ stock = stockObject; 
	  shares = numShares; }

	// Accessor function
	double getCost() const
	{ return shares * stock.getSharePrice(); }
};
#endif