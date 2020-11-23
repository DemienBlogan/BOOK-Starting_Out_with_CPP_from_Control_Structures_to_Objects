/*
9. Most Frequent Character
Write a function that accepts either a pointer to a C-string, or a string object, as its
argument. The function should return the character that appears most frequently in the
string. Demonstrate the function in a complete program.
*/

#include <iostream>
#include <string>

char MostFrequentChar(const std::string& str);

int main()
{
	using namespace std;

	cout << "Enter string: ";
	string str;
	getline(cin, str);

	char mostFrequentChar = MostFrequentChar(str);
	cout << "Most frequent character = " << mostFrequentChar << endl;

	return 0;
}

char MostFrequentChar(const std::string& str)
{
	char mostFrequentChar = str[0];
	int amountMostFrequentChar = 0;
	int amountChar;

	for (size_t i = 0; i < str.size(); i++)
	{
		amountChar = 0;

		for (size_t j = 0; j < str.size(); j++)
		{
			if (str[i] == str[j])
				amountChar++;
		}

		if (amountMostFrequentChar < amountChar)
		{
			amountMostFrequentChar = amountChar;
			mostFrequentChar = str[i];
		}
	}

	return mostFrequentChar;
}