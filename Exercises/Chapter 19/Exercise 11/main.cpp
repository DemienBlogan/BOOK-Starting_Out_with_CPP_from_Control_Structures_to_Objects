/*
11. File Compare
Write a program that opens two text files and reads their contents into two separate
queues. The program should then determine whether the files are identical by comparing
the characters in the queues. When two nonidentical characters are encountered,
the program should display a message indicating that the files are not the same. If both
queues contain the same set of characters, a message should be displayed indicating
that the files are identical.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"

int main()
{
	std::string filename1{ "File1.txt" };
	std::string filename2{ "File2.txt" };

	std::ifstream file1{ filename1 };
	std::ifstream file2{ filename2 };

	Queue<char> queue1;
	Queue<char> queue2;

	char ch1, ch2;

	while (file1.get(ch1))
		queue1.Enqueue(ch1);

	while (file2.get(ch2))
		queue2.Enqueue(ch2);

	bool areFilesSame = true;

	while (!queue1.IsEmpty() || !queue2.IsEmpty())
	{
		if (!queue1.IsEmpty())
			queue1.Dequeue(ch1);

		if (!queue2.IsEmpty())
			queue2.Dequeue(ch2);

		if (ch1 != ch2)
		{
			areFilesSame = false;
			break;
		}
	}

	if (areFilesSame)
		std::cout << "Files are the same.\n";
	else
		std::cout << "Files are different.\n";

	file1.close();
	file2.close();

	return 0;
}