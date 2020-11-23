/*
13. Rainfall Statistics Modification #2
Modify the program you wrote for Programming Challenge 9 so it saves the data in
the linked list to a file. Write a second program that reads the data from the file into a
linked list and displays it on the screen.
*/


#include <iostream>
#include <fstream>
#include <list>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::list;
using std::string;
using std::ofstream;
using std::ifstream;

void Initialize(list<double>& rainfalls, size_t months);
void Show(const list<double>& rainfalls);

void WriteToFile(const string& filename, const list<double>& rainfalls);
void ReadFromFile(const string& filename, list<double>& rainfalls);

int main()
{
	// Write into file
	{
		cout << "Enter amount of months: ";
		size_t months;
		cin >> months;

		list<double> rainfalls;

		cout << "Initializing...\n";
		Initialize(rainfalls, months);

		string filename{ "Rainfalls.txt" };

		WriteToFile(filename, rainfalls);
	}

	// Read from file and show
	{
		list<double> rainfalls;
		string filename{ "Rainfalls.txt" };

		ReadFromFile(filename, rainfalls);

		cout << "\List elements:\n";
		Show(rainfalls);
	}

	return 0;
}

void Initialize(list<double>& rainfalls, size_t months)
{
	for (size_t i = 0; i < months; i++)
	{
		cout << "Enter rainfall for " << i + 1 << " month: ";
		double rainfall;
		cin >> rainfall;

		if (rainfall < 0)
		{
			cout << "Incorrect value. Try again.\n";
			i--;
			continue;
		}

		rainfalls.push_back(rainfall);
	}
}

void Show(const list<double>& rainfalls)
{
	for (double rainfall : rainfalls)
		cout << rainfall << " ";
	cout << endl;
}

void WriteToFile(const string& filename, const list<double>& rainfalls)
{
	ofstream file{ filename };

	for (const auto& rainfall : rainfalls)
		file << rainfall << " ";

	file.close();
}

void ReadFromFile(const string& filename, list<double>& rainfalls)
{
	ifstream file{ filename };
	double rainfall;

	while (file >> rainfall)
		rainfalls.push_back(rainfall);

	file.close();
}