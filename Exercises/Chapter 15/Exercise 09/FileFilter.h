#pragma once
#include <fstream>

using std::ifstream;
using std::ofstream;

class FileFilter abstract
{
private:
	virtual char transform(char ch) abstract;

public:
	void doFilter(ifstream& in, ofstream& out);
};

class EncryptFilter final: public FileFilter
{
private:
	virtual char transform(char ch) override final;
};

class UpperFilter final : public FileFilter
{
private:
	virtual char transform(char ch) override final;
};

class UnchangedFilter final: public FileFilter
{
private:
	virtual char transform(char ch) override final;
};