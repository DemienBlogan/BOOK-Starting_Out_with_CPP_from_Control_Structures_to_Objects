#include <iostream>

#include "Numbers.h"

using std::cout;

string Numbers::lessThan20[20] = 
{ 
	"zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", 
	"eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen"
};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

Numbers::Numbers(int number)
	: number(0)
{
	if (number >= 0 && number <= 9999)
		this->number = number;
}

void Numbers::print() const
{
	int digit1 = number / 1000;
	int digit2 = number / 100 % 10;
	int digit3 = number / 10 % 10;
	int digit4 = number % 10;

	if (digit1 + digit2 + digit3 + digit4 == 0)
		cout << lessThan20[0];
	else
	{
		if (digit1 > 0 && digit1 < 10)
			cout << lessThan20[digit1] << " " << thousand << " ";

		if (digit2 > 0 && digit2 < 10)
			cout << lessThan20[digit2] << " " << hundred << " ";

		int lastTwoDigits = digit3 * 10 + digit4;

		if (lastTwoDigits > 0 && lastTwoDigits < 20)
			cout << lessThan20[lastTwoDigits];
	}
	
	cout << "\n";
}