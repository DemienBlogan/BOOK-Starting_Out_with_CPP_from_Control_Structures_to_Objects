/*
11. Using Files - String Selection Sort Modification
Modify the program you wrote for Programming Challenge 6 (String Selection Sort) so
it reads in 20 strings from a file. The data can be found in the names.txt file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	using namespace std;

	vector<string> names;
	ifstream file("names.txt");
	string name;

	while (getline(file, name))
		names.push_back(name);

	cout << "--- BEFORE sorting: ---\n";
	for (size_t i = 0; i < names.size(); i++)
		cout << names[i] << endl;

	for (size_t i = 0; i < names.size() - 1; i++)
		for (size_t j = i + 1; j < names.size(); j++)
			if (names[i] > names[j])
				std::swap(names[i], names[j]);

	cout << "--- AFTER sorting: ---\n";
	for (size_t i = 0; i < names.size(); i++)
		cout << names[i] << endl;

	file.close();

	return 0;
}