#pragma once
#include <fstream>

using std::ifstream;
using std::ofstream;

class FileFilter abstract
{
private:
	virtual char transform(char ch) abstract;

public:
	virtual void doFilter(ifstream& in, ofstream& out);
};

class DoubleSpacerFilter final : public FileFilter
{
private:
	virtual char transform(char ch) override final;

public:
	virtual void doFilter(ifstream& in, ofstream& out) override final;
};