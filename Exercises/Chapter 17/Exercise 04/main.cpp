/*
4. File Encryption and Decryption
Write a program that uses a map to assign "codes" to each letter of the alphabet. For
example:

map<char, char> codes = { { 'A', '%' }, { 'a', '9' }, { 'B', '@' }, { 'b', '#'}, etc...};

Using this example, the letter 'A' would be assigned the symbol %, the letter 'a' would
be assigned the number 9, the letter 'B' would be assigned the symbol @, and so forth.
The program should open a specified text file, read its contents, then use the map to
write an encrypted version of the file's contents to a second file. Each character in
the second file should contain the code for the corresponding character in the first
file. Write a second program that opens an encrypted file and displays its decrypted
contents on the screen.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

void Encrypt(std::string& text, std::map<char, char>& codes);
void Decrypt(std::string& text, std::map<char, char>& codes);

int main()
{
	using std::map;
	using std::ofstream;
	using std::ifstream;
	using std::string;
	using std::make_pair;
	using std::endl;
	using std::cout;

	map<char, char> codes =
	{
		make_pair('A', '1'),
		make_pair('B', '2'),
		make_pair('C', '3'),
		make_pair('D', '4'),
		make_pair('E', '5'),
		make_pair('F', '6'),
		make_pair('G', '7'),
		make_pair('H', '8'),
		make_pair('I', '9'),
		make_pair('J', '0'),
		make_pair('K', '!'),
		make_pair('L', '@'),
		make_pair('M', '#'),
		make_pair('N', '$'),
		make_pair('O', '%'),
		make_pair('P', '^'),
		make_pair('Q', '&'),
		make_pair('R', '*'),
		make_pair('S', '('),
		make_pair('T', ')'),
		make_pair('U', '_'),
		make_pair('W', '+'),
		make_pair('X', '_'),
		make_pair('Y', '-'),
		make_pair('Z', '='),
	};

	ifstream fin{ "File1.txt" };
	string text;
	char ch;

	while (fin.get(ch))
		text.push_back(ch);

	fin.close();

	Encrypt(text, codes);

	ofstream fout{ "File2.txt" };

	fout << text;

	fout.close();

	text.clear();

	fin.open("File2.txt");

	while (fin.get(ch))
		text.push_back(ch);

	fin.close();

	Decrypt(text, codes);

	cout << text << endl;

	return 0;
}


void Encrypt(std::string& text, std::map<char, char>& codes)
{
	size_t length = text.length();
	for (size_t i = 0; i < length; i++)
		if (isupper(text[i]))
			text[i] = codes[text[i]];
}

void Decrypt(std::string& text, std::map<char, char>& codes)
{
	using std::vector;
	using std::find;

	vector<char> encryptChars;
	vector<char> decryptChars;

	for (const auto& codePair : codes)
	{
		decryptChars.push_back(codePair.first);
		encryptChars.push_back(codePair.second);
	}

	size_t length = text.length();
	for (size_t i = 0; i < length; i++)
	{
		auto it = find(encryptChars.cbegin(), encryptChars.cend(), text[i]);

		if (it != encryptChars.cend())
		{
			size_t index = it - encryptChars.cbegin();
			text[i] = decryptChars[index];
		}
	}
}