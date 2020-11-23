/*
9. Rainfall Statistics Modification
Modify Programming Challenge 2 in Chapter 7 (Rainfall Statistics) to let the user
decide how many months of data will be entered. Use a linked list instead of an array
to hold the monthly data.
*/

#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::list;

void Initialize(list<double>& rainfalls, size_t months);
void Show(const list<double>& rainfalls);
int Min(const list<double>& rainfalls);
int Max(const list<double>& rainfalls);
double Sum(const list<double>& rainfalls);
double Average(const list<double>& rainfalls);

int main()
{
	cout << "Enter amount of months: ";
	size_t months;
	cin >> months;

	list<double> rainfalls;

	cout << "Initializing...\n";
	Initialize(rainfalls, months);

	cout << "\nArray elements:\n";
	Show(rainfalls);

	int minMonth = Min(rainfalls);
	int maxMonth = Max(rainfalls);

	cout << endl;
	cout << "Month with min rainfall = " << minMonth + 1 << endl;
	cout << "Month with max rainfall = " << maxMonth + 1 << endl;

	double sum = Sum(rainfalls);
	double average = Average(rainfalls);

	cout << endl;
	cout << "Sum rainfall = " << sum << endl;
	cout << "Average rainfall = " << average << endl;

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

int Min(const list<double>& rainfalls)
{
	double min = rainfalls.front();
	int minIndex = 0;

	size_t i = 0;
	for (double rainfall : rainfalls)
	{
		if (min > rainfall)
		{
			min = rainfall;
			minIndex = i;
		}

		i++;
	}

	return minIndex;
}

int Max(const list<double>& rainfalls)
{
	double max = rainfalls.front();
	int maxIndex = 0;

	size_t i = 0;
	for (double rainfall : rainfalls)
	{
		if (max < rainfall)
		{
			max = rainfall;
			maxIndex = i;
		}

		i++;
	}

	return maxIndex;
}

double Sum(const list<double>& rainfalls)
{
	double sum = 0.0;

	for (double rainfall : rainfalls)
		sum += rainfall;

	return sum;
}

double Average(const list<double>& rainfalls)
{
	double sum = Sum(rainfalls);
	double average = sum / rainfalls.size();
	return average;
}