/*
4. Test Scores #2
Modify the program of Programming Challenge 2 (Test Scores #1) to allow the user
to enter name-score pairs. For each student taking a test, the user types the student's
name followed by the student's integer test score. Modify the sorting function so it
takes an array holding the student names, and an array holding the student test scores.
When the sorted list of scores is displayed, each student's name should be displayed
along with his or her score. In stepping through the arrays, use pointers rather than
array subscripts.
*/

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T* CreateArray(size_t size);
void FillArray(string* names, int* scores, size_t size);
void EnterSize(int& size);
void Sort(string* names, int* scores, size_t size);
void Delete(const string* names, const int* scores);
void Show(const string* names, const int* scores, size_t size);
double Average(const int* scores, size_t size);

int main()
{
	string* names;
	int* scores;
	int size;

	EnterSize(size);

	scores = CreateArray<int>(size);
	names = CreateArray<string>(size);

	FillArray(names, scores, size);

	Sort(names, scores, size);

	Show(names, scores, size);

	double average = Average(scores, size);
	cout << "Average score = " << average << endl;

	Delete(names, scores);

	return 0;
}

template <typename T>
T* CreateArray(size_t size)
{
	return size != 0 ? new T[size] : nullptr;
}

void FillArray(string* names, int* scores, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Enter student's #" << i + 1 << " name: ";
		cin >> names[i];

		cout << "Enter score #" << i + 1 << ": ";
		cin >> scores[i];

		if (scores[i] < 0)
		{
			cout << "Incorrect value. Try again.\n";
			i--;
		}
	}
}

void EnterSize(int& size)
{
	do
	{
		cout << "Enter size: ";
		cin >> size;

		if (size <= 0)
			cout << "Incorrect value. Try again.\n";

	} while (size <= 0);
}

void Sort(string* names, int* scores, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = i + 1; j < size; j++)
		{
			if (scores[i] > scores[j])
			{
				std::swap(scores[i], scores[j]);
				std::swap(names[i], names[j]);
			}
		}
	}
}

void Delete(const string* names, const int* scores)
{
	delete[] names;
	delete[] scores;
}

void Show(const string* names, const int* scores, size_t size)
{
	using namespace std;

	for (size_t i = 0; i < size; i++)
	{
		cout << "Student #" << i + 1 << " " << names[i] << ": ";
		cout << scores[i] << endl;
	}
	cout << endl;
}

double Average(const int arr[], size_t size)
{
	double sum = 0;

	for (size_t i = 0; i < size; i++)
		sum += arr[i];

	double average = sum / size;

	return average;
}