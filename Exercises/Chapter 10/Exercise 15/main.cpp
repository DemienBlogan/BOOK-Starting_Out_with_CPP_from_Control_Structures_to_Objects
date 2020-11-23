/*
15. Character Analysis
If you have downloaded this book's source code, you will find a file named text.txt in
the Chapter 10 folder. Write a program that reads the file's contents and determines
the following:

- The number of uppercase letters in the file
- The number of lowercase letters in the file
- The number of digits in the file
*/

#include <iostream>
#include <fstream>

using namespace std;

int CountUppercase(ifstream& file);
int CountLowercase(ifstream& file);
int CountDigits(ifstream& file);

int main()
{
	ifstream file("File.txt");

	if (!file)
	{
		cout << "Error. File 'File.txt' cannot be found or opened.\n";
		return 1;
	}

	int upperLetters = CountUppercase(file);
	int lowerLetters = CountLowercase(file);
	int digits = CountDigits(file);

	cout << "Uppercase letters = " << upperLetters << endl;
	cout << "Lowercase letters = " << lowerLetters << endl;
	cout << "Digits = " << digits << endl;

	file.close();

	return 0;
}

int CountUppercase(ifstream& file)
{
	int letters = 0;
	char ch;

	while (file >> ch)
		if (isupper(ch))
			letters++;

	file.clear();
	file.seekg(0);

	return letters;
}

int CountLowercase(ifstream& file)
{
	int letters = 0;
	char ch;

	while (file >> ch)
		if (islower(ch))
			letters++;

	file.clear();
	file.seekg(0);

	return letters;
}

int CountDigits(ifstream& file)
{
	int digits = 0;
	char ch;

	while (file >> ch)
		if (isdigit(ch))
			digits++;

	file.clear();
	file.seekg(0);

	return digits;
}