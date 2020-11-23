/*
12. Corporate Sales Data Input
Write a program that reads the data in the file created by the program in Programming
Challenge 11. The program should calculate and display the following figures:
- Total corporate sales for each quarter
- Total yearly sales for each division
- Total yearly corporate sales
- Average quarterly sales for the divisions
- The highest and lowest quarters for the corporation
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct CorporateSales
{
	string divisionName;
	int quarter;
	double quarterlySales;
};

void OpenFileForRead(ifstream& file, const string& fileName);
CorporateSales* ReadFromFile(ifstream& file, size_t& size);

int main()
{
	size_t size;
	CorporateSales* divisions;
	string fileName = "Sales.txt";
	ifstream file;

	OpenFileForRead(file, fileName);
	divisions = ReadFromFile(file, size);

	file.close();

	// Total Corporate Sales for each quarter
	double quartalSales[4] = { 0, 0, 0, 0 };
	for (size_t i = 0; i < size; i++)
		quartalSales[divisions[i].quarter - 1] += divisions[i].quarterlySales;
	cout << "Total Corporate Sales for each quarter:\n";
	for (size_t i = 0; i < 4; i++)
		cout << "Quartal #" << i + 1 << ": $" << quartalSales[i] << endl;
	cout << endl;

	// Total yearly sales for each division
	map<string, double> divisionSales;
	divisionSales["West"] = divisionSales["East"] = divisionSales["North"] = divisionSales["South"] = 0;
	for (size_t i = 0; i < size; i++)
		divisionSales[divisions[i].divisionName] += divisions[i].quarterlySales;
	cout << "Total yearly sales for each division:\n";
	for (const auto& division : divisionSales)
		cout << "\t" << division.first << " division: $" << division.second << endl;
	cout << endl;

	// Total yearly corporate sales
	double totalYearlySales = 0;
	for (size_t i = 0; i < size; i++)
		totalYearlySales += divisions[i].quarterlySales;
	cout << "Total yearly corporate sales: $" << totalYearlySales << endl;
	cout << endl;

	// Average quarterly sales for the divisions
	double averageQuarterlySales[4] = { 0, 0, 0, 0 };
	size_t index = 0;
	for (const auto& division : divisionSales)
		averageQuarterlySales[index++] = division.second / 4.0;
	cout << "Average quarterly sales for the divisions:\n";
	index = 0;
	for (const auto& division : divisionSales)
		cout << "\t" << division.first << " division: $" << averageQuarterlySales[index++] << endl;
	cout << endl;

	// The highest and lowest quarters for the corporation
	double maxQuarter = max(quartalSales, quartalSales + 4);
	double minQuarter = min(quartalSales, quartalSales + 4);

	cout << "The higest queater earned $" << maxQuarter << endl;
	cout << "The lowest queater earned $" << minQuarter << endl;

	delete[] divisions;

	return 0;
}

void FillInformation(CorporateSales divisions[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << divisions[i].divisionName << " division:\n";
		cout << "Enter quarter: ";
		cin >> divisions[i].quarter;

		do
		{
			cout << "Enter quartery sales: ";
			cin >> divisions[i].quarterlySales;

			if (divisions[i].quarterlySales < 0)
				cout << "Incorrect value. Try again.\n";

		} while (divisions[i].quarterlySales < 0);
	}
}

void OpenFileForRead(ifstream& file, const string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		cerr << "ERROR: File '" << fileName << "' could not been opened/created.\n";
		exit(1);
	}
}

CorporateSales* ReadFromFile(ifstream& file, size_t& size)
{
	CorporateSales* divisions = nullptr;

	file >> size;
	file.ignore();

	divisions = new CorporateSales[size];

	for (size_t i = 0; i < size; i++)
	{
		getline(file, divisions[i].divisionName);
		file >> divisions[i].quarter;
		file >> divisions[i].quarterlySales;
		file.ignore();
	}

	return divisions;
}