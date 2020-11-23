#include <cctype>
#include "FileFilter.h"

void FileFilter::doFilter(ifstream& in, ofstream& out)
{
    char ch = in.get();
    while (in.good())
    {
        ch = transform(ch);
        out << ch;
        ch = in.get();
    }
}

char DoubleSpacerFilter::transform(char ch)
{
    return ch;
}

void DoubleSpacerFilter::doFilter(ifstream& in, ofstream& out)
{
    char ch = in.get();
    while (in.good())
    {

        if (ch == '\n')
            out << "\n\n";
        else
            out << ch;

        ch = in.get();
    }
}