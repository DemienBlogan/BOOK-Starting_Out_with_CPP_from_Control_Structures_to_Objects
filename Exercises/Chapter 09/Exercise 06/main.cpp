/*
6. Case Study Modification #1
Modify Program 9-19 (the United Cause case study program) so it can be used with
any set of donations. The program should dynamically allocate the donations array
and ask the user to input its values.
*/

#include <iostream>

using namespace std;

void arrSelectSort(int* [], int);
void showArray(const int[], int);
void showArrPtr(int* [], int);

int main()
{
	cout << "Enter the number of donations: ";
	int numDonations;
	cin >> numDonations;

	int* donations = new int[numDonations];

	for (size_t i = 0; i < numDonations; i++)
	{
		cout << "Enter donation #" << i + 1 << ": ";
		cin >> donations[i];
	}

	int** arrPtr = new int* [numDonations] {};

	for (int count = 0; count < numDonations; count++)
		arrPtr[count] = &donations[count];

	arrSelectSort(arrPtr, numDonations);

	cout << "The donations, sorted in ascending order, are: \n";
	showArrPtr(arrPtr, numDonations);

	cout << "The donations, in their original order, are: \n";
	showArray(donations, numDonations);

	delete[] donations;
	delete[] arrPtr;

	return 0;
}

void arrSelectSort(int* arr[], int size)
{
	int startScan, minIndex;
	int* minElem;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = arr[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(arr[index]) < *minElem)
			{
				minElem = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minElem;
	}
}

void showArray(const int arr[], int size)
{
	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}

void showArrPtr(int* arr[], int size)
{
	for (int count = 0; count < size; count++)
		cout << *(arr[count]) << " ";
	cout << endl;
}