/*
10. File Double-Spacer
Create a derived class of the abstract filter class of Programming Challenge 9 (File Filter)
that double-spaces a file, that is, it inserts a blank line between any two lines of the file.
*/

#include <fstream>
#include "FileFilter.h"

using std::ifstream;
using std::ofstream;

int main()
{
	DoubleSpacerFilter filter;

	ifstream fin{ "Input.txt" };
	ofstream fout{ "Output.txt" };

	filter.doFilter(fin, fout);

	fin.close();
	fout.close();

	return 0;
}