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

char EncryptFilter::transform(char ch)
{
    return ch + 10;
}
char UpperFilter::transform(char ch)
{
    return toupper(ch);
}

char UnchangedFilter::transform(char ch)
{
    return ch;
}