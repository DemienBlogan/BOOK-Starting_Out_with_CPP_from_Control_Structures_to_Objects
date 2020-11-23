/*
10. File Decryption Filter
Write a program that decrypts the file produced by the program in Programming
Challenge 9. The decryption program should read the contents of the coded file, restore
the data to its original state, and write it to another file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream encryptedFile("EnctyptedFile.txt");
	ofstream decryptedFile("DecryptedFile.txt");

	if (!encryptedFile)
	{
		cerr << "Error. File 'EnctyptedFile.txt' could not been opened.\n";
		return 1;
	}

	if (!decryptedFile)
	{
		cerr << "Error. File 'DecryptedFile.txt' could not been opened/created.\n";
		return 2;
	}

	int character;

	character = encryptedFile.get();
	while (!encryptedFile.eof())
	{
		character -= 10;
		decryptedFile << static_cast<char>(character);
		character = encryptedFile.get();
	}

	cout << "Decryption completed!\n";

	encryptedFile.close();
	decryptedFile.close();

	return 0;
}