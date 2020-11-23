/*
13. Drink Machine Simulator
Write a program that simulates a soft drink machine. The program should use a structure
that stores the following data:
	Drink Name
	Drink Cost
	Number of Drinks in Machine
The program should create an array of five structures. The elements should be initialized
with the following data:
-----------------------------------------------------
Drink Name           Cost           Number in Machine
-----------------------------------------------------
Cola                 0.75           20
Root Beer            0.75           20
Lemon-Lime           0.75           20
Grape Soda           0.80           20
Cream Soda           0.80           20
-----------------------------------------------------

Each time the program runs, it should enter a loop that perfomrs the following steps:
A list of drinks is displayed on the screen. The user should be allowed to either quit the
program or pick a drink. If the user selects a drink, he or she will next enter the amount
of money that is to be inserted into the drink machine. The program should display the
amount of change that would be returned, and subtract one from the number of that
drink left in the machine. If the user selects a drink that has sold out, a message should
be displayed. The loop then repeats. When the user chooses to quit the program, it
should display the total amount of money the machine earned.

Input Validation: When the user enters an amount of money, do not accept negative
values or values greater than $1.00.
*/

#include <iostream>
#include <string>

using namespace std;

struct Drink
{
	string name;
	double cost;
	int amount;
};

void Show(const Drink drinks[], size_t size);
void ShowMenu();
char PickDrink();
double EnterMoney();
bool IsAvailable(const Drink drinks[], char drink);

int main()
{
	double money, change;
	double machineEarned = 0;
	char drink;
	const size_t SIZE = 5;
	Drink drinks[SIZE] =
	{
		{ "Cola", 0.75, 20 },
		{ "Root Beer", 0.75, 20 },
		{ "Lemon-Lime", 0.75, 20 },
		{ "Grape Soda", 0.80, 20 },
		{ "Cream Soda", 0.80, 20 }
	};

	do
	{
		Show(drinks, SIZE);
		ShowMenu();
		drink = PickDrink();
		system("cls");

		if (drink == 'Q')
			continue;

		if (!IsAvailable(drinks, drink))
		{
			cout << "This drink was sold out.\n";
			continue;
		}

		money = EnterMoney();
		system("cls");

		switch (drink)
		{
		case 'C':
			drinks[0].amount--;
			change = money - drinks[0].cost;
			machineEarned += drinks[0].cost;
			break;

		case 'R':
			drinks[1].amount--;
			change = money - drinks[1].cost;
			machineEarned += drinks[1].cost;
			break;

		case 'L':
			drinks[2].amount--;
			change = money - drinks[2].cost;
			machineEarned += drinks[2].cost;
			break;

		case 'G':
			drinks[3].amount--;
			change = money - drinks[3].cost;
			machineEarned += drinks[3].cost;
			break;

		case 'S':
			drinks[4].amount--;
			change = money - drinks[4].cost;
			machineEarned += drinks[4].cost;
			break;

		default:
			change = 0.0;
		}

		cout << "Change = $" << change << endl;
		system("pause");
		system("cls");

	} while (drink != 'Q');

	cout << "Machine earned $" << machineEarned << endl;

	return 0;
}

void Show(const Drink drinks[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Drink " << drinks[i].name;
		cout << ": $" << drinks[i].cost;
		cout << " (amount = " << drinks[i].amount << ")\n";
	}
}

void ShowMenu()
{
	cout << "-------------- \n";
	cout << "C - Cola       \n";
	cout << "R - Root Beer  \n";
	cout << "L - Lemon-Lime \n";
	cout << "G - Grape Soda \n";
	cout << "S - Cream Soda \n";
	cout << "Q - Quit       \n";
}

char PickDrink()
{
	char drink;

	do
	{
		cout << "Pick a drink: ";
		cin >> drink;

		if (drink != 'C' && drink != 'R' && drink != 'L' && drink != 'G' && drink != 'S' && drink != 'Q')
			cout << "Incorrect letter. Try again.\n";

	} while (drink != 'C' && drink != 'R' && drink != 'L' && drink != 'G' && drink != 'S' && drink != 'Q');

	return drink;
}

double EnterMoney()
{
	double money;

	do
	{
		cout << "Enter money (>= $1.00): ";
		cin >> money;

		if (money < 1.00)
			cout << "Incorrect number. Try again.\n";

	} while (money < 1.00);

	return money;
}

bool IsAvailable(const Drink drinks[], char drink)
{
	switch (drink)
	{
	case 'C':
		return drinks[0].amount != 0;

	case 'R':
		return drinks[1].amount != 0;

	case 'L':
		return drinks[2].amount != 0;

	case 'G':
		return drinks[3].amount != 0;

	case 'S':
		return drinks[4].amount != 0;

	default:
		return false;
	}
}