/*
12. Coin Toss Simulator
Write a class named Coin. The Coin class should have the following member variable:
- A string named sideUp. The sideUp member variable will hold either "heads" or
  "tails" indicating the side of the coin that is facing up.

The Coin class should have the following member fucntions:
- A default constructor that randomly determines the side of the coin that is facing up
  ("heads" or "tails") and initializes the sideUp member variable accordingly.
- A void member function named toss that simulates the tossing of the coin. When
  the toss member function is called, it randomly determines the side of the coin that
  is facing up ("heads" or "tails") and sets the sideUp member variable accordingly.
- A member function named getSideUp that returns the value of the sideUp member variable

Write a program that demonstrates the Coin class. The program should create an
instance of the class and display the side that is initially facing up. Then, user a loop
to toss the coin 20 times. Each time the coin is tossed, display the side that is facing
up. The program should keep count of the number of times heads is facing up and the
number of times tails is facing up, and display those values after the loop finishes.
*/

#include <iostream>

#include "Coin.h"

using std::cout;
using std::endl;

int main()
{
	Coin coin;
	int heads = 0, tails = 0;

	cout << coin.GetSideUp() << endl;
	coin.GetSideUp() == "heads" ? heads++ : tails++;

	for (size_t i = 0; i < 20; i++)
	{
		coin.Toss();
		cout << coin.GetSideUp() << endl;
		coin.GetSideUp() == "heads" ? heads++ : tails++;
	}

	cout << endl;
	cout << "Number of heads = " << heads << endl;
	cout << "Number of tails = " << tails << endl;

	return 0;
}