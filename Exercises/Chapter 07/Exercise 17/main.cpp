/*
17. Name Search
If you have downloaded this book's source code, you will find the following files in this
chapter's folder:

- GirlNames.txt - This file contains a list of the 200 most popular names given to girls
  born in the United States from 2000 to 2009.
- BoyNames.txt - This file contains a list of the 200 most popular names given to boys
  born in the United States from 2000 to 2009.

Write a program that reads the contents of the two files into two separate arrays or
vectors. The user should be able to enter a boy's name, a girl's name, or both, and the
application should dipslay messages indicating whether the names were among the
most popular.
*/

#include <iostream>
#include <fstream>
#include <vector>

void OpenFile(std::ifstream& file, const std::string& fileName);
void CloseFile(std::ifstream& file);
void ReadNames(std::vector<std::string>& names, std::ifstream& file);
void EnterBoyName(std::string& name);
void EnterGirlName(std::string& name);
bool FindNameInFist(const std::string& name, const std::vector<std::string>& list);

int main()
{
	using namespace std;

	vector<string> boyNames, girlNames;
	ifstream boyNamesFile, girlNamesFile;
	string boyName, girlName;

	try
	{
		OpenFile(boyNamesFile, "BoyNames.txt");
		OpenFile(girlNamesFile, "GirlNames.txt");

		ReadNames(boyNames, boyNamesFile);
		ReadNames(girlNames, girlNamesFile);

		EnterBoyName(boyName);
		EnterGirlName(girlName);

		if (FindNameInFist(boyName, boyNames))
			cout << "Boy's name is among the most popular names.\n";

		if (FindNameInFist(girlName, girlNames))
			cout << "Girl's name is among the most popular names.\n";
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}

	CloseFile(boyNamesFile);
	CloseFile(girlNamesFile);

	return 0;
}

void OpenFile(std::ifstream& file, const std::string& fileName)
{
	file.open(fileName);

	if (!file)
	{
		using namespace std;

		string errorMessage = "File '" + fileName + "' could not been opened.\n";
		throw std::exception(errorMessage.c_str());
	}
}

void CloseFile(std::ifstream& file)
{
	if (file.is_open())
		file.close();
}

void ReadNames(std::vector<std::string>& names, std::ifstream& file)
{
	if (!names.empty())
		names.clear();

	using namespace std;

	string name;

	while (file >> name)
		names.push_back(name);
}

void EnterBoyName(std::string& name)
{
	using namespace std;

	cout << "Enter boy's name: ";
	cin >> name;
}

void EnterGirlName(std::string& name)
{
	using namespace std;

	cout << "Enter girl's name: ";
	cin >> name;
}

bool FindNameInFist(const std::string& name, const std::vector<std::string>& list)
{
	for (size_t i = 0; i < list.size(); i++)
		if (name == list[i])
			return true;

	return false;
}