#pragma once

class Die
{
private:
	int sides;
	int value;

public:
	Die(int sides);
	void Toss();
	int GetValue() const;
};