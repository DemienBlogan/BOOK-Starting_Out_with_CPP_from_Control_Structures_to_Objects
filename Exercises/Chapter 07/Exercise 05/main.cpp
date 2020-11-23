/*
5. Monkey Business
A local zoo wants to keep track of how many pounds of food each of its three monkeys
eats day during a typical week. Write a program that stores this information in a
two-dimensional 3*5 array, where each row represents a different monkey, and each
column represents a different day of the week. The program should first have the user
input the data for each monkey. Then, it should create a report that includes the folowing
information:

- Average amount of food eaten per day by the whole family of monkeys.
- The least amount of food eaten during the week by any one moneky.
- The greatest amount of food eaten during the week by any one monkey.

Input Validation: Do not accept negative numbers for pounds of food eaten.
*/

#include <iostream>

void EnterFoodPounds(double foodPounds[][5], size_t monkeys);
double Sum(const double foodPounds[][5], size_t monkeys);
double Average(const double foodPounds[][5], size_t monkeys);
double Min(const double foodPounds[][5], size_t monkeys);
double Max(const double foodPounds[][5], size_t monkeys);

int main()
{
	using namespace std;

	const size_t MONKEYS = 3, DAYS = 5;
	double foodPounds[MONKEYS][DAYS];

	EnterFoodPounds(foodPounds, MONKEYS);

	double average = Average(foodPounds, MONKEYS);
	double min = Min(foodPounds, MONKEYS);
	double max = Max(foodPounds, MONKEYS);

	cout << "Average amount of food eaten per day by the whole family of monkeys: " << average << endl;
	cout << "The least amount of food eaten during the week by any one monkey: " << min << endl;
	cout << "The greatest amount of food eaten during the week by any one monkey: " << max << endl;

	return 0;
}

void EnterFoodPounds(double foodPounds[][5], size_t monkeys)
{
	using namespace std;

	if (foodPounds == nullptr)
	{
		cout << "nullptr in function 'EnterFoodPounds'\n";
		exit(0);
	}

	size_t days = 5;
	for (size_t i = 0; i < monkeys; i++)
	{
		cout << "Monkey #" << i + 1 << ":\n";

		for (size_t j = 0; j < days; j++)
		{
			cout << "\tDay #" << j + 1 << ": ";
			cin >> foodPounds[i][j];

			if (foodPounds[i][j] < 0)
			{
				cout << "Incorrect value. Try again.\n";
				j--;
			}
		}
	}
}

double Sum(const double foodPounds[][5], size_t monkeys)
{
	using namespace std;

	if (foodPounds == nullptr)
	{
		cout << "nullptr in function 'EnterFoodPounds'\n";
		exit(0);
	}

	double sum = 0.0;

	size_t days = 5;
	for (size_t i = 0; i < monkeys; i++)
		for (size_t j = 0; j < days; j++)
			sum += foodPounds[i][j];

	return sum;
}

double Average(const double foodPounds[][5], size_t monkeys)
{
	using namespace std;

	if (foodPounds == nullptr)
	{
		cout << "nullptr in function 'EnterFoodPounds'\n";
		exit(0);
	}
	
	if (monkeys == 0)
	{
		cout << "Incorrect value of monkeys.\n";
		exit(0);
	}

	size_t days = 5;
	double sum = Sum(foodPounds, monkeys);
	double average = sum / (monkeys * days);
	return average;
}

double Min(const double foodPounds[][5], size_t monkeys)
{
	using namespace std;

	if (foodPounds == nullptr)
	{
		cout << "nullptr in function 'EnterFoodPounds'\n";
		exit(0);
	}

	double min = foodPounds[0][0];

	size_t days = 5;
	for (size_t i = 0; i < monkeys; i++)
		for (size_t j = 0; j < days; j++)
			if (min > foodPounds[i][j])
				min = foodPounds[i][j];

	return min;
}

double Max(const double foodPounds[][5], size_t monkeys)
{
	using namespace std;

	if (foodPounds == nullptr)
	{
		cout << "nullptr in function 'EnterFoodPounds'\n";
		exit(0);
	}

	double max = foodPounds[0][0];

	size_t days = 5;
	for (size_t i = 0; i < monkeys; i++)
		for (size_t j = 0; j < days; j++)
			if (max < foodPounds[i][j])
				max = foodPounds[i][j];

	return max;
}