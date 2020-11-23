/*
3. Chips and Salsa
Write a program that lets a maker of chips and salsa keep track of sales for five different
types of salsa: mild, medium, sweet, hot, and zesty. The program should use two
parallel 5-element arrays: an array of strings that holds the five salsa names, and an
array of integers that holds the number of jars sold during the past month for each salsa
type. The salsa names should be stored using an initialization list at the time the name
array is created. The program should prompt the user to enter the number of jars sold
for each type. Once this sales data has been entered, the program should produce a
report that displays sales for each salsa type, total sales, and the names of the highest
selling and lowest selling products.

Input Validation: Do not accept negative values for number of jars sold.
*/

#include <iostream>
#include <string>

void Initialize(int sales[], const std::string names[], size_t size);
void Show(const int sales[], const std::string names[], size_t size);
std::string Min(const int sales[], const std::string names[], size_t size);
std::string Max(const int sales[], const std::string names[], size_t size);
int Sum(const int sales[], size_t size);

int main()
{
	using namespace std;

	const size_t SIZE = 5;
	string names[SIZE] = { "mild", "medium", "sweet", "hot", "zesty" };
	int sales[SIZE];

	cout << "Initializing...\n";
	Initialize(sales, names, SIZE);

	cout << "\nArray elements:\n";
	Show(sales, names, SIZE);

	string minName = Min(sales, names, SIZE);
	string maxName = Max(sales, names, SIZE);

	cout << endl;
	cout << "Salsa with min sales = " << minName << endl;
	cout << "Salsa with max sales = " << maxName << endl;

	double sum = Sum(sales, SIZE);

	cout << endl;
	cout << "Total sales = " << sum << endl;

	return 0;
}

void Initialize(int sales[], const std::string names[], size_t size)
{
	using namespace std;

	if (sales == nullptr || names == nullptr)
	{
		cout << "nullptr in function 'Initialize'\n";
		exit(0);
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter amount of sales for " << names[i] << " salsa: ";
		cin >> sales[i];

		if (sales[i] < 0)
		{
			cout << "Incorrect value. Try again.\n";
			i--;
		}
	}
}

void Show(const int sales[], const std::string names[], size_t size)
{
	using namespace std;

	if (sales == nullptr || names == nullptr)
	{
		cout << "nullptr in function 'Show'\n";
		exit(0);
	}

	for (size_t i = 0; i < size; i++)
		cout << "The amount of " << names[i] << " salsa sales: " << sales[i] << endl;
}

std::string Min(const int sales[], const std::string names[], size_t size)
{
	using namespace std;

	if (sales == nullptr || names == nullptr)
	{
		cout << "nullptr in function 'Min'\n";
		exit(0);
	}

	int minSale = sales[0];
	string minName = names[0];

	for (size_t i = 1; i < size; i++)
	{
		if (minSale > sales[i])
		{
			minSale = sales[i];
			minName = names[i];
		}
	}

	return minName;
}

std::string Max(const int sales[], const std::string names[], size_t size)
{
	using namespace std;

	if (sales == nullptr || names == nullptr)
	{
		cout << "nullptr in function 'Min'\n";
		exit(0);
	}

	int maxSale = sales[0];
	string maxName = names[0];

	for (size_t i = 1; i < size; i++)
	{
		if (maxSale < sales[i])
		{
			maxSale = sales[i];
			maxName = names[i];
		}
	}

	return maxName;
}

int Sum(const int sales[], size_t size)
{
	using namespace std;

	if (sales == nullptr)
	{
		cout << "nullptr in function 'Sum'\n";
		exit(0);
	}

	double sum = 0.0;

	for (size_t i = 0; i < size; i++)
		sum += sales[i];

	return sum;
}