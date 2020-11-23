/*
10. File Filter
Write a program that opens a text file and reads its contents into a queue of characters.
The program should then dequeue each character, convert it to uppercase, and store
it in a second file.
*/

#include <fstream>
#include <string>
#include <cctype>
#include "Queue.h"

int main()
{
	std::string filename1{ "File1.txt" };
	std::string filename2{ "File2.txt" };

	std::ifstream file1{ filename1 };
	std::ofstream file2{ filename2 };

	Queue<char> queue;
	char ch;

	while (file1.get(ch))
		queue.Enqueue(ch);

	while (!queue.IsEmpty())
	{
		queue.Dequeue(ch);
		ch = std::toupper(ch);
		file2.put(ch);
	}

	file1.close();
	file2.close();

	return 0;
}