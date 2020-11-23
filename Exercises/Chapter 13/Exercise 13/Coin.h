#pragma once

#include <string>

using std::string;

class Coin
{
private:
	string sideUp;

public:
	Coin();
	void Toss();
	string GetSideUp() const { return sideUp; }
};