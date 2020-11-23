#include <cstdlib>

#include "Coin.h"

Coin::Coin()
{
	Toss();
}

void Coin::Toss()
{
	int randFace = rand() % 2;
	sideUp = (randFace == 0) ? "heads" : "tails";
}