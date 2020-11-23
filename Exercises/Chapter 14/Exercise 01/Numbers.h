#pragma once

#include <string>

using std::string;

class Numbers
{
private:
	static string lessThan20[20];
	static string hundred;
	static string thousand;

	int number;

public:
	Numbers(int number);
	void print() const;
};