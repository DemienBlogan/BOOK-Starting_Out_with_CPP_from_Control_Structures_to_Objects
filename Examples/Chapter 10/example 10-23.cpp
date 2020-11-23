#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function prototype
void split(const string&, char, vector<string>&);

int main()
{
	// String to tokenize
	string str1 = "one two three four";
	string str2 = "10:20:30:40:50";
	string str3 = "a/b/c/d/e/f";

	// vector to hold the tokens.
	vector<string> tokens;

	// Tokenzise str1, using ' ' as the delimiter.
	split(str1, ' ', tokens);
	for (auto e : tokens)
		cout << e << " ";
	cout << endl;
	tokens.clear();

	// Tokenzise str2, using ':' as the delimiter.
	split(str2, ':', tokens);
	for (auto e : tokens)
		cout << e << " ";
	cout << endl;
	tokens.clear();

	// Tokenzise str3, using '/' as the delimiter.
	split(str2, '/', tokens);
	for (auto e : tokens)
		cout << e << " ";
	cout << endl;
	return 0;
}