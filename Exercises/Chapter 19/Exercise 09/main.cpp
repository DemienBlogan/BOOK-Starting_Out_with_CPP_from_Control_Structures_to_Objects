/*
9. File Reverser
Write a program that opens a text file and reads its contents into a stack of characters.
The program should then pop the characters from the stack and save them in a second
text file. The order of the characters saved in the second file should be the reverse of
their order in the first file.
*/

#include <fstream>
#include <string>
#include "Stack.h"

int main()
{
	std::string filename1{ "File1.txt" };
	std::string filename2{ "File2.txt" };

	std::ifstream file1{ filename1 };
	std::ofstream file2{ filename2 };

	Stack<char> stack;
	char ch;

	while (file1.get(ch))
		stack.Push(ch);

	while (!stack.IsEmpty())
	{
		stack.Pop(ch);
		file2.put(ch);
	}

	file1.close();
	file2.close();

	return 0;
}