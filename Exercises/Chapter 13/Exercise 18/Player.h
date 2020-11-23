#pragma once

#include <vector>

#include "Die.h"

using std::vector;

class Player
{
private:
	int points = 0;
	vector<Die> dies;

public:
	Player(int dies, int sides);
	int GetPoints() const;
	void Toss();
};