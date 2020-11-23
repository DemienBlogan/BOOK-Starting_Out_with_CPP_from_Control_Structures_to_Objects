/*
17. Morse Code Converter
Morse Code is a code where each letter of the English alphabet, each digit, and various
punctuation characters are represented by a series of dots and dashes. Table 10-10
shows part of the code.

Write a program that asks the user to enter a string then converts that string to Morse
code.

----------------------------------------------------------------------------------------------
Character      Code      Character      Code      Character      Code      Character      Code   
----------------------------------------------------------------------------------------------
space          space     6              -....     G              --.       Q              --.-
comma          --..--    7              --...     H              ....      R              .-.
period         .-.-.-    8              ---..     I              ..        S              ...
question mark  ..--..    9              ----.     J              .---      T              -
0              -----     A              .-        K              -.-       U              ..-
1              .----     B              -...      L              .-..      V              ...-
2              ..---     C              -.-.      M              --        W              .--
3              ...--     D              -..       N              -.        X              -..-
4              ....-     E              .         O              .--       Y              -.--
5              .....     F              ..-.      P              .--.      Z              --..
----------------------------------------------------------------------------------------------   
*/

#include <iostream>
#include <string>

using namespace std;

string EnterString();
string ConverteToMorseCodeString(char character);
void ShowMorseCodeVariant(const string& str);

int main()
{
	string text = EnterString();
	ShowMorseCodeVariant(text);

	return 0;
}

string EnterString()
{
	cout << "Enter text: ";
	string text;
	getline(cin, text);
	return text;
}

string ConverteToMorseCodeString(char character)
{
	switch (character)
	{
		// Specials:
	case ' ': return " ";
	case ',': return "--..--";
	case '.': return ".-.-.-";
	case '?': return "..--..";

		// Digits:
	case '0': return "-----";
	case '1': return ".----";
	case '2': return "..---";
	case '3': return "...--";
	case '4': return "....-";
	case '5': return ".....";
	case '6': return "-....";
	case '7': return "--...";
	case '8': return "---..";
	case '9': return "----.";

		// Letters:
	case 'A': case 'a': return ".-";
	case 'B': case 'b': return "-...";
	case 'C': case 'c': return "-.-.";
	case 'D': case 'd': return "-..";
	case 'E': case 'e': return ".";
	case 'F': case 'f': return "..-.";
	case 'G': case 'g': return "--.";
	case 'H': case 'h': return "....";
	case 'I': case 'i': return "..";
	case 'J': case 'j': return ".---";
	case 'K': case 'k': return "-.-";
	case 'L': case 'l': return ".-..";
	case 'M': case 'm': return "--";
	case 'N': case 'n': return "-.";
	case 'O': case 'o': return "---";
	case 'P': case 'p': return ".--.";
	case 'Q': case 'q': return "--.-";
	case 'R': case 'r': return ".-.";
	case 'S': case 's': return "...";
	case 'T': case 't': return "-";
	case 'U': case 'u': return "..-";
	case 'V': case 'v': return "...-";
	case 'W': case 'w': return ".--";
	case 'X': case 'x': return "-..-";
	case 'Y': case 'y': return "-.--";
	case 'Z': case 'z': return "--..";

	default:
		return "ERROR";
	}
}

void ShowMorseCodeVariant(const string& str)
{
	cout << "Morse Code: ";

	string code;

	for (size_t i = 0; i < str.size(); i++)
	{
		code = ConverteToMorseCodeString(str[i]);
		cout << code;
	}
	cout << endl;
}