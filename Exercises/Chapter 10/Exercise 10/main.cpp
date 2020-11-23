/*
10. replaceSubstring Function
Write a function named replaceSubstring. The functon should accept three C-string
or string object arguments. Let's call them string1, string2, and string3. It
should search string1 for all occurrences of string2. When it finds an occurrence of
string2, it should replace it with string3. For example, suppose the three arguments
have the following values:
string1: "the dog jumped over the fence"
string2: "the"
string3: "that"
With these three arguments, the function would return a string object with the value
"that dog jumped over that fence". Demonstrate the function in a complete program.
*/

#include <iostream>
#include <string>

void replaceSubstring(std::string& str, const std::string& oldSubStr, const std::string& newSubStr);

int main()
{
	using namespace std;

	cout << "Enter string: ";
	string str;
	getline(cin, str);

	cout << "What substring you want to change?: ";
	string oldSubstring;
	getline(cin, oldSubstring);

	cout << "What substring you want to change to?: ";
	string newSubstring;
	getline(cin, newSubstring);

	replaceSubstring(str, oldSubstring, newSubstring);

	cout << "Result: " << str << endl;

	return 0;
}

void replaceSubstring(std::string& str, const std::string& oldSubStr, const std::string& newSubStr)
{
	size_t index = str.find(oldSubStr);
	while (index != std::string::npos)
	{
		str.replace(index, oldSubStr.size(), newSubStr);
		index = str.find(oldSubStr, index + 1);
	}
}