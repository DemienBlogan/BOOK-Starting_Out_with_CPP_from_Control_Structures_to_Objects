#pragma once

class Die
{
private:
	int sides;
	int value;

public:
	Die(int = 6);
	void roll();
	int getSides();
	int getValue();
};