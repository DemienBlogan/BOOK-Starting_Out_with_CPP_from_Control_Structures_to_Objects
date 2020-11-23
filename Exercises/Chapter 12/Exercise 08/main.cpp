/*
8. Array/File Functions
Write a function named arrayToFile. The function should accept three arguments:
the name of a file, a pointer to an int array, and the size of the array. The function
should open the specified file in binary mode, write the contents of the array to the file,
and then close the file.

Write another function named fileToArray. This function should accept three arguments:
the name of a file, a pointer to an int array, and the size of the array. The
function should open the specified file in binary mode, read its contents into the array,
and then close the file.

Write a complete program that demonstrates these functions by using the arrayToFile
function to write an array to a file, then using the fileToArray function to read the
data from the same file. After the data are read from the file into the array, display the
array's contents on the screen.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void Initialize(int arr[], size_t size);
void Show(const int arr[], size_t size);
void ArrayToFile(const string& fileName, const int arr[], size_t size);
void FileToArray(const string& fileName, int arr[], size_t size);

int main()
{
	const size_t SIZE = 10;
	int arr[SIZE];

	Initialize(arr, SIZE);
	
	cout << "Array before writing: ";
	Show(arr, SIZE);

	ArrayToFile("Array.bin", arr, SIZE);

	int arr2[SIZE];
	FileToArray("Array.bin", arr2, SIZE);

	cout << "Array after reading: ";
	Show(arr2, SIZE);

	return 0;
}

void Initialize(int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		arr[i] = rand() % 100;
}

void Show(const int arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void ArrayToFile(const string& fileName, const int arr[], size_t size)
{
	ofstream file(fileName, ios::binary);

	for (size_t i = 0; i < size; i++)
		file.write(reinterpret_cast<const char*>(&arr[i]), sizeof(int));

	file.close();
}

void FileToArray(const string& fileName, int arr[], size_t size)
{
	ifstream file(fileName, ios::binary);

	for (size_t i = 0; i < size; i++)
		file.read(reinterpret_cast<char*>(&arr[i]), sizeof(int));

	file.close();
}