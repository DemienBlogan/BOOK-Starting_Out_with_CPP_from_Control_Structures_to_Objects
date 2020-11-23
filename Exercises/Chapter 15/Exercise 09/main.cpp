/*
9. File Filter
A file filter reads an input file, transforms it in some way, and writes the results to an
output file. Write an abstract file filter class that defines a pure virtual function for
transforming a character. Create one derived class of your file filter class that performs
encryption, another that transforms a file to all uppercase, and another that creates an
unchaged copy of the original file. The class should have the following member function:

void doFilter(ifstream& in, ofstream& out)

This function should be called to perform the actual filtering. The member function for
transforming a single character should have the prototype:

char transform(char ch)

The encryption class should have a constructor that takes an integer as an argument
and uses it as the encryption key.
*/

#include <fstream>
#include "FileFilter.h"

using std::ifstream;
using std::ofstream;

int main()
{
	EncryptFilter filter1;
	UpperFilter filter2;
	UnchangedFilter filter3;

	ifstream fin{ "Input.txt" };

	ofstream fout;

	fout.open("Output1.txt");
	filter1.doFilter(fin, fout);
	fout.close();

	fin.clear();
	fin.seekg(0);

	fout.open("Output2.txt");
	filter2.doFilter(fin, fout);
	fout.close();

	fin.clear();
	fin.seekg(0);

	fout.open("Output3.txt");
	filter3.doFilter(fin, fout);
	fout.close();

	fin.close();

	return 0;
}