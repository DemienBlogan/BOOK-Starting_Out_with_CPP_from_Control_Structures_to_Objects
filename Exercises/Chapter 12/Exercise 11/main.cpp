/*
11. Corporate Sales Data Output
Write a program that uses a structure to store the following data on a company division:
- Division Name (such as East, West, North, or South)
- Quarter (1, 2, 3, or 4)
- Quarterly Sales
The user should be asked for the four quarters' sales figures for the East, West, North,
and South divisions. The data for each quarter for each division should be written to
a file.

Input Validation: Do not accept negative numbers for any sales figures.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct CorporateSales
{
	string divisionName;
	int quarter;
	double quarterlySales;
};

void FillInformation(CorporateSales divisions[], size_t size);
void OpenFileForWrite(ofstream& file, const string& fileName);
void WriteToFile(ofstream& file, const CorporateSales divisions[], size_t size);

int main()
{
	const size_t SIZE = 4;
	CorporateSales divisions[SIZE] =
	{
		{ "East" },
		{ "West" },
		{ "North" },
		{ "South" }
	};

	FillInformation(divisions, SIZE);

	string fileName = "Sales.txt";
	ofstream file;

	OpenFileForWrite(file, fileName);

	WriteToFile(file, divisions, SIZE);

	file.close();

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

void OpenFileForWrite(ofstream& file, const string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		cerr << "ERROR: File '" << fileName << "' could not been opened/created.\n";
		exit(1);
	}
}

void WriteToFile(ofstream& file, const CorporateSales divisions[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		file << divisions[i].divisionName << " division:\n";
		file << "\tQuarter: " << divisions[i].quarter << endl;
		file << "\tQuarterly Sales: " << divisions[i].quarterlySales << "\n\n";
	}
}