/*
18. Fat Gram Calculator
Write a program that asks for the number of calories and fat grams in a food. The
program should display the percentage of calories that come from fat. If the calories
from fat are less than 30 percent of the total calories of the food, it should also display
a message idicating that the food is low in fat.

One gram of fat has 9 calories, so
Calories from fat = fat grams * 9
The percentage of calories from fat can be calculated as
Calories from fat / total calories

Input Validation: Make sure the number of calories and fat grams are not less than 0.
Also, the number of calories from fat cannot be greater than the total number of calories.
If that happens, display an error message indicationg that either the calories of fat grams
were incorrectly entered.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the number of calories: ";
	int calories;
	cin >> calories;

	if (calories <= 0)
	{
		cout << "Incorrect value of calories.\n";
		return 0;
	}

	cout << "Enter the fat grams in a food: ";
	double fatGrams;
	cin >> fatGrams;

	if (fatGrams <= 0)
	{
		cout << "Incorrect value of fat grams.\n";
		return 0;
	}

	const int CALORIES_IN_GRAM = 9;
	int fatCalories = fatGrams * CALORIES_IN_GRAM;

	if (fatCalories > calories)
	{
		cout << "Fat calories can't be greater than all calories.\n";
		return 0;
	}

	double fatPercentage = fatCalories * 100.0 / calories;
	cout << "Fat percentage = " << fatPercentage << "%\n";

	if (fatPercentage < 30)
		cout << "The food is low in fat.\n";
	else
		cout << "The food is fat.\n";

	return 0;
}